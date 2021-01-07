template <class T>
forward_iterator<T>::forward_iterator(Element<T>* _ptr){
    ptr = _ptr;
}

template<class T>
T& forward_iterator<T>::forward_iterator::operator*() {
    return ptr->value;
}

template<class T>
forward_iterator<T>& forward_iterator<T>::forward_iterator::operator++() {
    if (ptr == nullptr){
        throw std::out_of_range("out of range");
    }
    *this = ptr->next();
    return *this;
}

template<class T>
forward_iterator<T> forward_iterator<T>::forward_iterator::operator++(int) {
    forward_iterator<T> old = *this;
    ++*this;
    return old;
}

template<class T>
bool forward_iterator<T>::forward_iterator::operator==(const forward_iterator& Other) const {
    return ptr == Other.ptr;
}

template<class T>
bool forward_iterator<T>::forward_iterator::operator!=(const forward_iterator& Other) const {
    return ptr != Other.ptr;
}