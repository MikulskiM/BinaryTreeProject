#include <iostream>

#include "binarytree.h"

using namespace std;

int main()
{
    BinaryTree tree;

    // tree.generateTestTree();
    tree.generateRandomTree(10);
    tree.printTree();

    cout << "\n\n";

    tree.flattenTree();
    tree.printTree();

    return 0;
}
