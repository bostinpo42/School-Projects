#include "trie.h"

    Trie::Trie() : root{new NODE} {}

    bool Trie::insert(const std::string& word){
        if(word.empty()) throw TrieError("Invalid Argument");
        if(contains(word)) return false;
        insert(word, 0u, root);
    }

    bool Trie::erase(const std::string& word){
        if(word.empty()) throw TrieError("Invalid Argument");
        if(!contains(word)) return false;

        // write as recursive function
        // two checks, one up and one down checking for terminal nodes
        // Recursively reach bottom node, check if it is a leaf. if it is go back up
        // if it is a leaf we check if it is terminal, and traverse back up

    }

    bool Trie::contains(const std::string& word) const{
        if(word.empty()) throw TrieError("Invalid Argument");

        char idx;
        NODE_PTR ptr{root};

        for(char c : word) {
           idx = c - 'a';
           if(ptr->nexts[idx] == nullptr) return false;
           ptr = ptr->nexts[idx];
        }

        return (ptr->isTerminal);
    }

    bool Trie::insert(const std::string& word, uint64_t cPos, NODE_PTR node){
        char idx{word[cPos] - 'a'};

        if(node->nexts[idx] == nullptr) node->nexts[idx] = new NODE;

        if(cPos >= word.size() - 1){
            node->nexts[idx]->isTerminal = true;
            return true;
        }
        return insert(word, cPos + 1, node->nexts[idx]);
    }