#ifndef TREEGENERATOR_H
#define TREEGENERATOR_H

class Node
{
public:
    int value;
    Node* down;
    Node* right;

    Node(int val) : value(val), down(nullptr), right(nullptr) {}
};

class TreeGenerator
{
public:
    TreeGenerator();

    GenerateTestTree();
};

#endif // TREEGENERATOR_H
