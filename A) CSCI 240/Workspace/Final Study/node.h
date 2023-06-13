
#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node {
    Node(const T& data) : data{data}, next{nullptr}, prev{nullptr} {}
    Node(const T& data, Node<T>* next) : data{data}, next{next}, prev{nullptr} {}
    Node(const T& data, Node<T>* next, Node<T>* prev) : data{data}, next{next}, prev{prev} {}

    int data;
    Node<T>* next;
    Node<T>* prev;
};

#endif