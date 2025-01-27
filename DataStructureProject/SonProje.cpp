#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <chrono>
#include "BST.h"

using namespace std;
using namespace std::chrono;

void toLowercase(string& str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void extractWords(const string& line, BinSeachTree& tree, const string& filename) {
    string word;
    bool inWord = false;

    for (char c : line) {
        if (isalpha(c)) {
            word.push_back(tolower(c));
            inWord = true;
        }
        else {
            if (inWord) {
                tree.insert(word, filename);
                word.clear();
                inWord = false;
            }
        }
    }

    if (inWord) {
        tree.insert(word, filename);
    }
}

int main() {
    int choice1;
    string searchWord;
    auto start = high_resolution_clock::now();

    const int numDocuments = 10000;
    BinSeachTree tree;

    for (int i = 0; i < numDocuments; ++i) {
        string filename = to_string(i) + ".txt";
        ifstream file(filename);

        if (file.is_open()) {
            cout << "Processing document: " << filename << endl;
            string line;
            while (getline(file, line)) {
                toLowercase(line);
                extractWords(line, tree, filename);
            }
            file.close();
        }
        else {
            cerr << "Unable to open file: " << filename << endl;
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);

    do {
        cout << "+-------------------------------------------+\n";
        cout << "|             Document Retrieval            |\n";
        cout << "+-------------------------------------------+\n";
        cout << "| Indexing took " << duration.count() << " seconds.               |\n";
        cout << "+-------------------------------------------+\n";
        cout << "| 1. Enter a single keyword to list         |\n";
        cout << "|    the document(s)(file names)            |\n";
        cout << "| 2. Print the top 10 words that            |\n";
        cout << "|    appeared most frequently               |\n";
        cout << "| 3. Print the top 10 words that            |\n";
        cout << "|    appeared least frequently              |\n";
        cout << "| 4. Exit                                   |\n";
        cout << "+-------------------------------------------+\n";

        cin >> choice1;
        switch (choice1) {
        case 1:
            cout << "Please enter word for search: ";
            cin >> searchWord;
            {
                Leaf_Node* result = tree.search(searchWord);
                if (result) {
                    result->printFileList();
                }
                else {
                    cout << "Word not found." << endl;
                }
            }
            break;
        case 2:
            tree.printTopFrequent(10, true);
            break;
        case 3:
            tree.printTopFrequent(10, false);
            break;
        default:
            break;
        }
    } while (choice1 != 4);

    return 0;
}
