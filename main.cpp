#include <iostream>

#include "binarytree.h"

using namespace std;

int main()
{
    BinaryTree tree("tree1");

    // tree.generateTestTree();
    tree.generateRandomTree(10);
    tree.printTree();

    cout << "\n\n";

    tree.flattenTree();
    tree.printTree();

    cout << "\n\n";

    tree.found(6);

    return 0;
}
