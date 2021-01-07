template<class T>
std::shared_ptr<Element<T>> pop(std::shared_ptr<Element<T>> el) {
    if (el->next_el != nullptr) {
        el->next_el = pop(el->next_el);
        return el;
    }
    return nullptr;
}

template<class T>
std::shared_ptr<Element<T>> push(std::shared_ptr<Element<T>> el) {
    if (el -> next_el != nullptr) {
        return push(el->next_el);
    }
    return el;
}

template <class T>
const size_t List<T>::length() const{
    return size;
}

template <class T>
forward_iterator<T> List<T>::begin() {
    return forward_iterator<T>(first.get());
}

template <class T>
forward_iterator<T> List<T>::end() {
    return forward_iterator<T>(nullptr);
}
template <class T>
void List<T>::erase_by_it(forward_iterator<T> it){
    if (size == 0){
        throw std::invalid_argument("no elements");
    }

    if (it.ptr == nullptr){
        throw std::invalid_argument("no element");
    }

    if (it == begin()){
        first = first->next_el;
        if (first != nullptr){
            first->prev_el.reset();
        }
        size--;
        return;
    }
    if (it == end()){
        first = pop(first);
        size--;
        return;
    }
    std::shared_ptr<Element<T>> after_deleted = it.ptr->next_el;
    std::weak_ptr<Element<T>> before_deleted = it.ptr->prev_el;
    after_deleted->prev_el = before_deleted;
    before_deleted.lock()->next_el = after_deleted;
    size--;
}

template<class T>
void List<T>::erase_by_index(const size_t index) {
    forward_iterator<T> it = begin();
    for (size_t i = 1; i <= index; ++i) {
        it++;
    }
    erase_by_it(it);
}

template<class T>
void List<T>::insert_by_it(forward_iterator<T> it,const T& value){
    if (first == nullptr){
        first = std::shared_ptr<Element<T>>(new Element<T>{value});
    }
    else {
        auto temp = std::shared_ptr<Element<T>>(new Element<T>{value});
        if (it == begin()){
            temp->next_el = first;
            first->prev_el = temp;
            first = temp;
        }
        else if (it.ptr == nullptr){
            temp->prev_el = push(first);
            push(first)->next_el = temp;
        }
        else {
            temp->prev_el = it.ptr->prev_el;
            temp->next_el = it.ptr->prev_el.lock()->next_el;
            it.ptr->prev_el = temp;
            temp->prev_el.lock()->next_el = temp;
        }
    }
    size++;
}

template <class T>
void List<T>::insert_by_index(const size_t n,const T& value){
    forward_iterator<T> it = begin();
    for (size_t i = 0; i < n; i++) {
        it++;
    }
    insert_by_it(it, value);
}

template<class T>
List<T>& List<T>::operator=(List<T>&& Other){
    size = Other.size;
    first = std::move(Other.first);
}

template<class T>
T& List<T>::operator[](const size_t index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("out of range");
    }
    forward_iterator<T> it = begin();
    for (size_t i = 0; i < index; i++) {
        it++;
    }
    return *it;
}