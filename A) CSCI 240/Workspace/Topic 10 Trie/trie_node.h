#include<cstddef>
#include<array>

#ifndef TRIE_NODE
#define TRIE_NODE

//S is the node's cardinality
template<size_t S>
struct TrieNode{

    TrieNode() : TrieNode(false) { }
    TrieNode(bool isTerminal) : isTerminal{isTerminal}, nexts() { }

    // if a node is deleted all of its descendants are deleted
    ~TrieNode(){
        for(TrieNode* ptr : nexts) {
            if(ptr) {
                delete ptr;
                ptr = nullptr;
            }
        }
    }

    bool isLeaf() {
        for(const auto& n : nexts)
            if(n != nullptr) return false;
        return true;
    }

    bool isTerminal;
    std::array<TrieNode*, S> nexts;
};

#endif