#pragma once
#include "TreeNode.h"

class BinSeachTree {
public:
    BinSeachTree();
    ~BinSeachTree();

    void insert(const string& word, const string& filename);
    Leaf_Node* search(const string& word) const;
    void printInOrder() const;
    void printTopFrequent(int n, bool mostFrequent) const;

private:
    Leaf_Node* root;

    Leaf_Node* insert(Leaf_Node* node, const string& word, const string& filename);
    Leaf_Node* search(Leaf_Node* node, const string& word) const;
    void printInOrder(Leaf_Node* node) const;
    void getNodes(Leaf_Node* node, vector<Leaf_Node*>& nodes) const;
};

BinSeachTree::BinSeachTree() : root(nullptr) {}

BinSeachTree::~BinSeachTree() {
    
}

void BinSeachTree::insert(const string& word, const string& filename) {
    root = insert(root, word, filename);
}

Leaf_Node* BinSeachTree::insert(Leaf_Node* node, const string& word, const string& filename) {
    if (node == nullptr) {
        Leaf_Node* newNode = new Leaf_Node(word);
        newNode->addFile(filename);
        return newNode;
    }
    if (word < node->word) {
        node->left = insert(node->left, word, filename);
    }
    else if (word > node->word) {
        node->right = insert(node->right, word, filename);
    }
    else {
        node->addFile(filename);
    }
    return node;
}

Leaf_Node* BinSeachTree::search(const string& word) const {
    return search(root, word);
}

Leaf_Node* BinSeachTree::search(Leaf_Node* node, const string& word) const {
    if (node == nullptr || node->word == word) {
        return node;
    }
    if (word < node->word) {
        return search(node->left, word);
    }
    else {
        return search(node->right, word);
    }
}

void BinSeachTree::printInOrder() const {
    printInOrder(root);
}

void BinSeachTree::printInOrder(Leaf_Node* node) const {
    if (node == nullptr) {
        return;
    }
    printInOrder(node->left);
    cout << node->word << " (" << node->counter << ")" << endl;
    node->printFileList();
    printInOrder(node->right);
}

void BinSeachTree::getNodes(Leaf_Node* node, vector<Leaf_Node*>& nodes) const {
    if (node == nullptr) {
        return;
    }
    getNodes(node->left, nodes);
    nodes.push_back(node);
    getNodes(node->right, nodes);
}

void BinSeachTree::printTopFrequent(int n, bool mostFrequent) const {
    vector<Leaf_Node*> nodes;
    getNodes(root, nodes);

  
    sort(nodes.begin(), nodes.end(), [mostFrequent](Leaf_Node* a, Leaf_Node* b) {
        return mostFrequent ? a->counter > b->counter : a->counter < b->counter;
    });

    for (int i = 0; i < n && i < nodes.size(); ++i) {
        cout << nodes[i]->word << " (" << nodes[i]->counter << ")" << endl;
    }
}
