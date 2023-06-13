#include <functional>
#include "bstnode.h"

#ifndef BST_H
#define BST_H

template<typename T>
class BST{
public:
    BST(std::function<bool(size_t, size_t)> comparator) : comparator{comparator} { }

    BSTNode<T>* put(const T& item, BSTNode<T>* node){
        if(node == nullptr) {
            node = new BSTNode<T>(item);
            return node;
        }
        if(item == node->item) return nullptr;
        if(comparator(item, node->item) == true) node->lChild = put(item, node->lChild);
        if(comparator(item, node->item) == false) node->rChild = put(item, node->rChild);
        return node;
    }

    BSTNode<T>* erase(const T& item, BSTNode<T>* node){
        if(node == NULL) return node;
        if(comparator(item, node->item) == true) node->lChild = erase(item, node->lChild);
        else if(comparator(item, node->item) == false) node->rChild = erase(item, node->rChild);
        else {
            if(node->lChild == NULL){
                BSTNode<T>* temp = node->rChild;
                delete node;
                return temp;
            }
            if(node->rChild == NULL){
                BSTNode<T>* temp = node->lChild;
                delete node;
                return temp;
            }
            BSTNode<T>* temp = minMaxNode(node->rChild);
            node->item = temp->item;
            node->rChild = erase(temp->item, node->rChild);
        }
        return node;
    }

    const T* find(const T& item, BSTNode<T>* node){
        if(node->item == item) return item;
        if(comparator(item, node->item)) find(item, node->lChild);
        if(comparator(item, node->item) == false) find(item, node->rChild);
        else return nullptr;
    }

    BSTNode<T>* minMaxNode(BSTNode<T>* node){
        BSTNode<T>* current = node;
        while(current && current->lChild != NULL) current = current->lChild;
        return current;
    }

    void clear(BSTNode<T>* node){
        if(node == nullptr) return;
        clear(node->lChild);
        clear(node->rChild);
        delete node;
        node = nullptr;
    }

private:
    std::function<bool(size_t, size_t)> comparator;

};

#endif