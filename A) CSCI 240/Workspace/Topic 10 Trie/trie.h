#include <string>
#include "set.h"
#include "trie_node.h"
#include <stdexcept>

#ifndef TRIE
#define TRIE

using NODE = TrieNode<26>;
using NODE_PTR = TrieNode<26>*;

class Trie : public Set<std::string> {
public:

    bool insert(const std::string& word);
    bool erase(const std::string& word);
    bool contains(const std::string& word) const;

private:
    NODE_PTR root;

    bool erase(const std::string&, NODE_PTR, size_t); // recursive function to erase
    bool insert(const std::string&, uint64_t, NODE_PTR); // recursive function to insert

};

struct TrieError : public std::runtime_error{
    TrieError() : std::runtime_error("Error in Trie") { }
    TrieError(const char* msg) : std::runtime_error(msg) { }
};

#endif