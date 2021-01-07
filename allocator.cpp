allocator::allocator(size_t _size, size_t _count) {
    size = _size;
    count = _count;
    free_blocks.resize(count);
    used_blocks = (char*) malloc(size * count);
    for(size_t i = 0; i < count; i++){
        free_blocks[i] = used_blocks + i * size;
    }
    free_count = count;
}

void* allocator::alloc() {
    void* res = nullptr;
    if (free_count > 0){
        res = free_blocks[free_count - 1];
        free_count--;
    }
    else {
        throw std::overflow_error("cant't alloc");
    }
    return res;
}

void allocator::dealloc(void* ptr) {
    free_blocks[free_count] = ptr;
    free_count++;
}

allocator::~allocator(){
    if (free_count < count){
        std::perror("memory leak");
    }
    free_blocks.clear();
    free(used_blocks);
}
