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

void BinaryTree::flattenTree() {
    Node* current = root;

    if (root == nullptr) {
        cout << "ERROR: root == nullptr\n";
    }

    while (current != nullptr) {
        Node* right = current->right;

        while (current->down != nullptr) {
            current->right = current->down;
            current->down = nullptr;
            current = current->right;
        }
        current->right = right;
        current = right;
    }
}
