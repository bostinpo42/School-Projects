#ifndef BSTNODE_H
#define BSTNODE_H

template<typename T>
struct BSTNode{
    BSTNode(const T& item) : item{item}, lChild{nullptr}, rChild{nullptr} { }

    T item;
    BSTNode<T>* lChild;
    BSTNode<T>* rChild;
};

#endif