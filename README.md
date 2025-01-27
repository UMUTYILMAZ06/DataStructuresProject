# Document Retrieval System

This project is a Document Retrieval System built using a Binary Search Tree (BST) data structure. The program indexes words from multiple `.txt` files and allows the user to perform various search and retrieval operations.

## Features
- **Word Indexing**: The program reads through `.txt` files and indexes the words, associating them with the files where they appear.
- **Search Functionality**: Search for a specific word to see the list of files where it is found.
- **Top Frequent Words**: Display the top 10 most frequently occurring words across all documents.
- **Least Frequent Words**: Display the top 10 least frequently occurring words across all documents.
- **Performance Timing**: The program measures and displays the time taken for indexing all the files.

## How It Works
1. The program reads `.txt` files named `0.txt`, `1.txt`, ..., up to `9999.txt`.
2. Each word is converted to lowercase and stored in a Binary Search Tree along with the filename.
3. Users can interact with the program through a menu interface.

## Program Workflow
1. **Indexing**: The system processes all `.txt` files and stores the words in the BST. It handles each word by converting it to lowercase and ignoring special characters.
2. **User Menu**:
   - **Option 1**: Search for a word and retrieve a list of filenames containing the word.
   - **Option 2**: Display the top 10 most frequent words.
   - **Option 3**: Display the top 10 least frequent words.
   - **Option 4**: Exit the program.

## Prerequisites
- A C++ compiler supporting C++11 or later.
- Ensure that the `.txt` files are present in the program's working directory.

## Compilation and Execution
1. Compile the program using a C++ compiler:
   ```bash
   g++ main.cpp BST.cpp -o DocumentRetrieval
   ```
2. Run the program:
   ```bash
   ./DocumentRetrieval
   ```

## Input Format
- Text files must be named as `0.txt`, `1.txt`, ..., up to `9999.txt` and placed in the working directory.

## Example Usage
- After running the program, you'll see a menu.
- Select option 1 to search for a word and view its associated files.
- Select option 2 or 3 to display frequent or infrequent words.

## Performance
The program reports the time taken to index the files at the start of the menu. This can help analyze its efficiency based on the number of files and their content.

## Notes
- The Binary Search Tree is implemented in the `BST.h` and `BST.cpp` files.
- The program is optimized for handling a large number of files, but performance depends on the file sizes and the number of unique words.

## Future Improvements
- Add support for phrase searches.
- Implement a more advanced data structure like a Trie for faster word lookups.
- Add multi-threading to improve indexing performance.

---
