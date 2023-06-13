#include "node.h"
#include <stdexcept>
#include <iostream>

#ifndef LIST_H
#define LIST_H

template<typename T>
class List {
public:
    List() : head{nullptr} {}

    void insertPos(const T& item, size_t pos){
        if(itemQty < pos) throw std::out_of_range("Error: Cannot insert, position out of range."); // check to see if pos is out of range

        // add node to empty list
        if(isEmpty()) {
            head = new Node<T>(item); 
            ++itemQty;
            return;
        }

        // add node to position 0, but not empty
        if(pos == 0){
            Node<T>* temp = head;
            head = new Node<T>(item, temp);
            temp->prev = head;
            ++itemQty;
            return;
        }
        else{

        // adding node to the end
        if(itemQty == pos){
            insertBack(item);
        }

        // add node to specific position
        Node<T>* temp = head;
        for(size_t i{0}; i < pos; ++i){
            temp = temp->next;
        }
        Node<T>* tempPrev = temp->prev;
        temp->prev = new Node<T>(item, temp, tempPrev);
        tempPrev->next = temp->prev;
        }
    }

    void insertFront(const T& item){
        // add node to empty list
        head = new Node<T>(item, head);
        ++itemQty;
    }

    void insertBack(const T& item){
        // add node to empty list
        if(isEmpty()) {
            head = new Node<T>(item); 
            ++itemQty;
            return;
        }

        Node<T>* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = new Node<T>(item, nullptr, temp);
        ++itemQty;
    }

    bool removePos(size_t pos){
        if(isEmpty()) throw std::invalid_argument("Cannot remove from empty list.");
        if(itemQty < pos) throw std::out_of_range("Cannot remove, position is out of range.");
        //removing from position 0
        if(pos == 0) removeFront();

        //removing from the end
        if(pos == itemQty) removeBack();

        //removing from specific position
        Node<T>* temp = head;
        for(size_t i{0}; i < pos; ++i){
            temp = temp->next;
        }
        Node<T>* tempPrev = temp->prev;
        Node<T>* tempNext = temp->next;
        delete temp;
        tempPrev->next = tempNext;
        tempNext->prev = tempPrev;
    }

    void removeFront(){
        if(isEmpty()) throw std::invalid_argument("Cannot remove from empty list.");
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        --itemQty;
    }

    void removeBack(){
        if(isEmpty()) throw std::invalid_argument("Cannot remove from empty list.");
        Node<T>* end = head;
        Node<T>* prev = nullptr;

        while(end->next != nullptr){
            prev = end;
            end = end->next;
        }
        delete end;
        prev->next = nullptr;
        --itemQty;
    }

    bool isEmpty() { return head == nullptr; }

    bool contains(const T& item){
        Node<T>* temp = head;
        while(temp->next != nullptr){
            if(temp->data == item) return true;
            temp = temp->next;
        }
        return false;
    }

    T front(){
        return head->data;
    }

    T back(){
        Node<T>* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        return temp->data;
    }

    void print()
    {
        Node<T>* itr{ head };
        while(itr != nullptr)
        {
            std::cout << itr->data << "->";
            itr = itr->next;
        }
        std::cout << '\n';
    }

private:
    Node<T>* head;
    size_t itemQty{0};
};

#endif