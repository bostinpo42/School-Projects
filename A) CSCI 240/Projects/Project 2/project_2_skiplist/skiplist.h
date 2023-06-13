#include<vector>
#include<cstdlib>
#include<functional>

#include"skiplist_node.h"

#ifndef SKIPLIST
#define SKIPLIST

// Note: It is assumed that type T has overloded comparison operators
template<typename T>
class Skiplist{
public:
    Skiplist(std::function<bool(T, T)> comparator) : 
    itemQty{0}, levels{}, comparator{comparator} { levels.emplace_back(new SkiplistNode<T>(0)); }
    
    // Adds an item into the container.
    void add(const T& item) {
        // if(contains(item)) return;

        SkiplistNode<T>* newNode = new SkiplistNode<T>(item);
        std::vector<SkiplistNode<T>*> retVector{search(item)};
        size_t count{0};

        while(getsPromoted()) {
            if(levels[count] == 0) {
                levels.emplace_back(new SkiplistNode<T>(0));
                levels[count]->next = newNode;
            }
            for(;count < retVector.size();) retVector[count]->next = newNode;
            ++count;
        }
        ++itemQty;
        // adding a node should create a new node. 
        // when adding a node we should check to see if the item we are storing is already in the list. we should search the highest levels of the list first and work down.
        // when searching we return the least, or greatest number item <, or > our search term, depending on our comparator, for each level.
        // from there we continue searching each level, continuing from the node returned from the previous level.
        // we continue working down each level until we hit l0, where we may find our search term.
        // if we do not find the term then we will add the item after the last node we left off from our search.
        // if the item already exists then we will simply not add it.
        // if we are adding a node, then we should use the vector returned from the search function to ensure that the node we added is added correctly, on each level.
    }

    // Removes and returns an item from the container
    T remove(const T& item) {
        if(contains(item) == false) return;

        std::vector<SkiplistNode<T>*> retVector{search(item)};

        // we remove a node by first searching for it. we cannot remove a node if it does not exist.
        // we search each level for the node, when we reach level 0 we should return a vector of pointers pointing to the node previous to the node we are searching for at each level.
        // we then remove our node, severing any of the connections of the node, and reconnecting them without the node we removed.
        // we return the node we removed.
    }

    // Checks if item is already in the container. Returns true if it is and false otherwise
    bool contains(const T& item) {
        std::vector<SkiplistNode<T>*> retVector{search(item)};
        SkiplistNode<T>* temp{retVector.back()};
        if(temp->next->item == item) return true;
        return false;
    }

    // returns the number of items stored in the set
    size_t size() { return itemQty; }

private:
    std::vector<SkiplistNode<T>*> levels;
    size_t itemQty;

    std::function<bool(T,T)> comparator;

    std::vector<SkiplistNode<T>*> search(const T& item) {
        std::vector<SkiplistNode<T>*> retVector;
        std::vector<SkiplistNode<T>*> temp{levels};
        
        for(size_t count{temp.size()}; count > 0; --count) {
            if(comparator(temp[count]->next->item, item)) retVector.emplace_back(temp[count]);
        }
        
        return retVector;
        // we search each level for the least, or greatest number item < our search term, depending on our comparator, for each level.
        // we add a pointer to this node into a vector for each level, continuing from the node returned from the previous level.
        // we work down each level until we reach l0, where we may find our search term.
        // if we find the search term in l0, return the vector of pointers previous to the node we are searching for.
    }

    bool getsPromoted() { return static_cast<bool>(rand() & 1); }
};

#endif /* SKIPLIST */
