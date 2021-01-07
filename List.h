#ifndef OOP5_LIST_H
#define OOP5_LIST_H

#include <memory>
#include "allocator.h"

#define MAX_ELEMENTS_COUNT 1000

template <class T>
class forward_iterator;

template <class T>
class Element;


template <class T>
class List {
public:
    List() = default;
    const size_t length() const;
    forward_iterator<T> begin();
    forward_iterator<T> end();
    void erase_by_it(forward_iterator<T> it);
    void erase_by_index(const size_t n);
    void insert_by_it(forward_iterator<T> it,const T& value);
    void insert_by_index(const size_t n,const T& value);
    T& operator[](const size_t index) const;
    List<T>& operator=(List<T>&& Other);

private:
    size_t size = 0;
    std::shared_ptr<Element<T>> first = nullptr;
};

template <class T>
class forward_iterator {
public:
    using value_type = T;
    using reference = T&;
    using pointer = T*;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::forward_iterator_tag;
    explicit forward_iterator(Element<T>* ptr);
    T& operator*();
    forward_iterator& operator++();
    forward_iterator operator++(int);
    bool operator== (const forward_iterator& other) const;
    bool operator!= (const forward_iterator& other) const;

private:
    Element<T>* ptr;
    friend List<T>;
};

template <class T>
class Element {
public:
    T value;
    std::shared_ptr<Element> next_el;
    std::weak_ptr<Element> prev_el ;
    forward_iterator<T> next();

    static allocator item_allocator;
    void* operator new(size_t size);
    void operator delete(void* p);
};

#include "List.cpp"
#include "Element.cpp"
#include "forward_iterator.cpp"
#endif //OOP5_LIST_H
