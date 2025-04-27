#include "binarytree.h"

void BinaryTree::generateTestTree() {
    cout << "generating " << name << "\n";

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

void BinaryTree::generateRandomTree(int numberOfNodes) {
    cout << "generating " << name << "\n";

    random_device randDevice;
    mt19937 gen(randDevice());
    uniform_int_distribution distrib(0, 9);

    vector<Node*> nodes;

    for (int i = 0; i < numberOfNodes; i++) {
        nodes.push_back(new Node(distrib(gen)));
    }
    root = nodes.front();

    Node* currentTop = root;
    Node* currentBottom = root;

    for (int i = 1; i<nodes.size(); i++) {
        if (distrib(gen) > 4) {
            // down
            currentBottom->down = nodes[i];
            currentBottom = nodes[i];
        }
        else {
            // right
            currentTop->right = nodes[i];
            currentTop = nodes[i];
            currentBottom = nodes[i];
        }
    }
}

void BinaryTree::printTree() {
    vector<vector<int>> columns;
    Node* currentTop = root;
    Node* currentBottom = root;
    int i = 0;  // columns iterator

    while (currentTop != nullptr) {
        columns.push_back(vector<int>());

        while (currentBottom != nullptr) {
            columns[i].push_back(currentBottom->value);
            currentBottom = currentBottom->down;
        }

        currentTop = currentTop->right;
        currentBottom = currentTop;
        i++;
    }

    int maxDepth = 0;
    for (auto& column : columns) {
        if (column.size() > maxDepth) {
            maxDepth = column.size();
        }
    }

    for (int j = 0; j<maxDepth; j++) {
        for (auto& column : columns) {
            if (j < column.size()) {
                cout << column[j] << "   ";
            } else {
                cout << "    ";
            }
        }
        cout << "\n";
    }
}

void BinaryTree::flattenTree() {
    cout << "flattening " << name << "\n";

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
