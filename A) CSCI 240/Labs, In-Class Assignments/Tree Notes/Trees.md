Austin Ngo  
Tree Notes  
Topic 4a  
08/28/2022  

# Storage Techniques

## Linear organization
- Array, linked list, Stack, Queue, and Dictionary
- Objects stored in this manner appear one after another
## Nonlinear organization
- Trees and graphs
- Objects stored in this manner are arranged hierarchically


# Trees
- Trees are widely used in computer science as a data organization used to place data in a hierarchical structure
- Trees are collections of nodes which are connected by edges without having any cycle

## Tree Terminology
- Level: the level of a node which represents it's hierarchy
- Root: a single node at the top level of the tree
- Children: the nodes branching down from the tree are the children of the nodes from the previous level
- Parent: a node which has children is the parent of those children
- Leaf: a node without children
- Subtree: any node and its children form a subtree of the original tree
- Sibling: sibling nodes share the same parent node
- Uncles: siblings of a node's parent
- Ancestor: a node which is connected to all lower-level nodes
- Descendant: lower-level nodes which are connected to ancestor node
- Edge: connection between one node and another
- Path: a sequence of nodes and edges connecting a node with a descendant
- Height of a node: the number of edges on the longest path between that node and a leaf, +1 (plus one), or the number of nodes on the longest path between that node and a leaf.
- Height of a tree: the height of its root node
- Depth of node: The number of edges from the trees root node, +1 (plus one)
- N-ary Tree: each node has no more than n children
    - Binary tree: each node has at most two children
    - Ternary tree: each node has at most three children


# Binary Trees
- Full Binary Tree: all internal nodes have two children, all leaves are at the same depth
    - The number of nodes in a **full** binary tree of height h is : $n = 2^h - 1$
    - The height of a **full or complete** binary tree having n nodes: $h = ceil(log_2(n + 1))$
    - The number of leaf nodes in a **full** binary tree having a height h is : $n = 2^{h - 1}$
    - The number of non-leaf nodes in a **full** binary tree having a height h is : $n = 2^{h - 1} - 1$
    
- Complete Binary Tree: almost-full binary tree, bottom level of the tree is filling from left to right but may not have its full compliment of leaves
    - The number of leaf nodes in a **complete binary** tree having a number of nodes n is : $L = floor((n + 1)/2)$
    - The number of non-leaf nodes in a **complete binary** tree having a number of nodes n : $NL = ceil((n - 1)/2)$
  
# Tree Traversals
- The common tree traversals are:
  - Preorder Traversal
  - Inorder Traversal
  - Postorder Traversal
  - Level-order Traversal
  
## Pre-order Traversal
1. Process the root
2. Process the nodes in the left subtree with a recursive call
3. Process the nodes in the right subtree with a recursive call
   
## In-order Traversal
1. Process the nodes in the left subtree with a recursive call
2. Process the root
3. Process the nodes in the right subtree with a recursive call

## Post-order Traversal
1. Process the nodes in the left tree with a recursive call
2. Process the nodes in the right subtree with a recurisve call
3. Process the root

## Level-order Traversal
1. Process the root
2. Process nodes one level at a time (visiting nodes from left to right)
   