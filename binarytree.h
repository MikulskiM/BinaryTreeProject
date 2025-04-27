#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <vector>
#include <random>

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
    string name;

public:
    BinaryTree(string treeName) : name(treeName) {}

    void generateTestTree();
    void generateRandomTree(int numberOfNodes);

    void printTree();
    void flattenTree();
};

#endif // BINARYTREE_H
