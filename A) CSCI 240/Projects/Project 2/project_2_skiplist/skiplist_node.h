#include<vector>

#ifndef SKIPLIST_NODE
#define SKIPLIST_NODE

template<typename T>
struct SkiplistNode {
    SkiplistNode(T item) : item{item}, next{nullptr} { }

    T item;
    SkiplistNode<T>* next;

    std::vector<SkiplistNode<T>*> levels;
};

#endif /* SKIPLIST_NODE */
