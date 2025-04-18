#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

using namespace std;

class BinaryTree
{
private:
    struct Node {
        int value;
        Node* right;
        Node* down;
        Node(int val) : value(val), right(nullptr), down(nullptr) {}
    };

    Node* root;

public:
    BinaryTree();

    void generateTestTree();
    void printTree();
    void printRecursive(Node* node, int depth);
};

#endif // BINARYTREE_H
