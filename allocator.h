#ifndef OOP6_ALLOCATOR_H
#define OOP6_ALLOCATOR_H

#include <vector>

class allocator {
public:
    allocator(size_t size,size_t count);
    void* alloc();
    void dealloc(void* ptr);
    ~allocator();
private:
    size_t size;
    size_t count;
    char* used_blocks;
    std::vector<void*> free_blocks;
    size_t free_count;
};

#include "allocator.cpp"
#endif //OOP6_ALLOCATOR_H
