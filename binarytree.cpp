#include "binarytree.h"

#include <vector>

BinaryTree::BinaryTree() : root(nullptr) {}

void BinaryTree::generateTestTree() {
    root = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    root->right = n2;
    n2->right = n3;
    n3->right = n4;
    n4->right = n5;

    // level 2
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    root->down = n6;
    n2->down = n7;
    n3->down = n8;
    n5->down = n9;

    // level 3
    Node* n10 = new Node(3);
    Node* n11 = new Node(4);
    Node* n12 = new Node(2);
    n6->down = n10;
    n7->down = n11;
    n8->down = n12;

    // level 4
    Node* n13 = new Node(8);
    n11->down = n13;
}

// void BinaryTree::printTree() {
//     if (!root) return;

//     std::vector<Node*> currentLevel;

//     // Level 1
//     Node* curr = root;
//     while (curr) {
//         std::cout << curr->value;
//         currentLevel.push_back(curr);
//         if (curr->right) std::cout << " - ";
//         curr = curr->right;
//     }
//     std::cout << std::endl;

//     // Print levels down
//     bool hasNextLevel = true;
//     while (hasNextLevel) {
//         hasNextLevel = false;

//         // Print '|' lines
//         for (size_t i = 0; i < currentLevel.size(); ++i) {
//             if (currentLevel[i] && currentLevel[i]->down)
//                 std::cout << "|";
//             else
//                 std::cout << " ";

//             if (i != currentLevel.size() - 1)
//                 std::cout << "   ";
//         }
//         std::cout << std::endl;

//         // Move to next level
//         std::vector<Node*> nextLevel;
//         for (Node* node : currentLevel) {
//             if (node && node->down) {
//                 nextLevel.push_back(node->down);
//                 hasNextLevel = true;
//             } else {
//                 nextLevel.push_back(nullptr);
//             }
//         }

//         // Print values
//         for (size_t i = 0; i < nextLevel.size(); ++i) {
//             if (nextLevel[i])
//                 std::cout << nextLevel[i]->value;
//             else
//                 std::cout << " ";

//             if (i != nextLevel.size() - 1)
//                 std::cout << "   ";
//         }
//         std::cout << std::endl;

//         currentLevel = nextLevel;
//     }
// }


void BinaryTree::printTree() {
    if (root == nullptr) {
        cout << "ERROR:\tcan't print tree - root is null pointer\n";
        return;
    }

    Node* temp = root;

    // level 1
    while (temp != nullptr) {
        cout << temp->value;
        if (temp->right) {
            cout << " - ";
        }
        temp = temp->right;
    }

    // level 2
    cout << "\n";
    temp = root;
    while (temp != nullptr) {
        if (temp->down) {
            cout << "|   ";
        }
        else {
            cout << "    ";
        }
        temp = temp->right;
    }

    cout << "\n";
    temp = root;
    while (temp != nullptr) {
        if (temp->down) {
            cout << temp->down->value;
        }
        else {
            cout << " ";
        }
        cout << "   ";
        temp = temp->right;
    }

    // level 3
    cout << "\n";
    temp = root;
    while (temp != nullptr) {
        if (temp->down && temp->down->down) {
            cout << "|   ";
        }
        else {
            cout << "    ";
        }
        temp = temp->right;
    }

    cout << "\n";
    temp = root;
    while (temp != nullptr) {
        if (temp->down && temp->down->down) {
            cout << temp->down->down->value;
        }
        else {
            cout << " ";
        }
        cout << "   ";
        temp = temp->right;
    }

    // level 4
    cout << "\n";
    temp = root;
    while (temp != nullptr) {
        if (temp->down && temp->down->down && temp->down->down->down) {
            cout << "|   ";
        }
        else {
            cout << "    ";
        }
        temp = temp->right;
    }

    cout << "\n";
    temp = root;
    while (temp != nullptr) {
        if (temp->down && temp->down->down && temp->down->down->down) {
            cout << temp->down->down->down->value;
        }
        else {
            cout << " ";
        }
        cout << "   ";
        temp = temp->right;
    }

    cout << "\n";
}
