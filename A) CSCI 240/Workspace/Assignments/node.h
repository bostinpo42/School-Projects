
#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node {
    T item{};
    Node<T>* next{};

    Node(T item, Node<T>* next) : item(item), next(next) { }
    Node(T item) : Node<T>(item, nullptr) { }
};

#endif