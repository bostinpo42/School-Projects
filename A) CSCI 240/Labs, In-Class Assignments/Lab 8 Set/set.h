// Austin Ngo
// Lab 8 Set
// CSCI 240 
// Set and BST implementation
#include <stack>
#include <list>
#include "bst.h"

#ifndef SET_H
#define SET_H

template<typename T>
class Set{
public:
    Set(std::function<bool(size_t, size_t)> comparator) : itemQty{0}, root{NULL}, Tree(comparator) {}

    bool insert(const T& item){
        if(Tree.put(item, root) != nullptr) {
            ++itemQty;
            return true;
        }
        return false;
    }

    bool erase(const T& item){
        if(Tree.erase(item, root) != NULL) {
            --itemQty;
            return true;
        }
        return false;
    }

    // bool erase(int position){
    //     std::stack<BSTNode<T>*> s{inOrder(root)};

    //     if(erase(s[position]->item)) return true;
    //     else return false;
    // }

    void clear(){
        Tree.clear(root);
    }

    bool isEmpty(){
        if(itemQty == 0) return true;
        return false;
    }

    size_t size(){ return itemQty; }

    std::list<BSTNode<T>*> toSequence(){
        return inOrder(root);
    } 

    static Set<T> combine(std::list<T>& A, std::list<T>& B, std::list<T>& C){
        typename std::list<BSTNode<T>*>::iterator iteratorA{A.begin()};
        typename std::list<BSTNode<T>*>::iterator iteratorB{B.begin()};

        while(iteratorA != A.cend() && iteratorB != B.cend()){
            if(iteratorA < iteratorB) fromA(iteratorA++, C);
            else if(iteratorA == iteratorB) fromBoth(iteratorA++, iteratorB++, C);
            else fromB(iteratorB++, C);
        }
        while(iteratorA != A.cend()) fromA(iteratorA++, C);
        while(iteratorB != B.cend()) fromB(iteratorB++, C);
        return C;
    }

    static Set<T> intersection(std::list<T> A, std::list<T> B, std::list<T>& C){
        typename std::list<BSTNode<T>*>::iterator iteratorA{A.begin()};
        typename std::list<BSTNode<T>*>::iterator iteratorB{B.begin()};

        while(iteratorA != A.cend() && iteratorB != B.cend()){
            if(iteratorA < iteratorB) fromAInter(iteratorA++, C);
            else if(iteratorA == iteratorB) fromBoth(iteratorA++, iteratorB++, C);
            else fromB(iteratorB++, C);
        }
        while(iteratorA != A.cend()) fromAInter(iteratorA++, C);
        while(iteratorB != B.cend()) fromBInter(iteratorB++, C);
        return C;
    }

private:
    size_t itemQty;
    BST<T> Tree;
    BSTNode<T>* root;

    std::function<bool(size_t, size_t)> comparator;

    std::list<BSTNode<T>*> inOrder(BSTNode<T>* node){
        std::list<BSTNode<T>*> s;
        BSTNode<T>* current = node;

        while(current != nullptr || s.empty() == false){
            while(current != nullptr) {
                s.emplace_front(current);
                current = current->lChild;
            }
            current = s.front();
            s.pop_front();
            current = current->rChild;
        }
        return s;
    }

    void fromA(const std::list<T>& a, std::list<T>& C){
        C.emplace_back(a);
    }

    void fromAInter(const std::list<T>& a, std::list<T>& C){
        return;
    }

    void fromBoth(const std::list<T>& a, const std::list<T>& b, std::list<T>& C){
        C.emplace_back(a);
    }

    void fromB(const std::list<T>& b, std::list<T>& C){
        C.emplace_back(b);
    } 

    void fromBInter(const std::list<T>& b, std::list<T>& C){
        return;
    }
};

#endif