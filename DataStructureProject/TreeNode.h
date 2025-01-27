#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Node.h"

using namespace std;

class Leaf_Node {
public:
    string word;
    Node* fileList; 
    int counter;
    Leaf_Node* left;
    Leaf_Node* right;

    Leaf_Node(const string& word);
    void addFile(const string& filename);
    bool containsFile(const string& filename) const;
    void printFileList() const;
};

Leaf_Node::Leaf_Node(const string& word) : word(word), fileList(nullptr), counter(0), left(nullptr), right(nullptr) {}

void Leaf_Node::addFile(const string& filename) {
    if (!containsFile(filename)) {
        Node* newNode = new Node(filename);
        newNode->Smallnext = fileList;
        fileList = newNode;
    }
    counter++;
}

bool Leaf_Node::containsFile(const string& filename) const {
    Node* walker = fileList;
    while (walker != nullptr) {
        if (walker->data == filename) {
            return true;
        }
        walker = walker->Smallnext;
    }
    return false;
}

void Leaf_Node::printFileList() const {
    Node* walker = fileList;
    while (walker != nullptr) {
        cout << walker->data << endl;
        walker = walker->Smallnext;
    }
}
