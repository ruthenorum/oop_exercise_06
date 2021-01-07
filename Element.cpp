template <class T>
allocator Element<T>::item_allocator(sizeof(Element<T>),MAX_ELEMENTS_COUNT);

template <class T>
forward_iterator<T> Element<T>::next(){
    return forward_iterator<T>(next_el.get());
}

template <class T>
void* Element<T>::operator new (size_t size) {
    return item_allocator.alloc();
}


template <class T>
void Element<T>::operator delete(void* p) {
    item_allocator.dealloc(p);
}
