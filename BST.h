#ifndef BST_H
#define BST_H
#include "Book.h"


class BookNode {
public:
    Book data;
    BookNode* left;
    BookNode* right;
    
    BookNode() {
        left = NULL;
        right = NULL;
    }
};


class BookBST {
private:
    BookNode* root;
    

    BookNode* insertHelper(BookNode* node, Book book) {
        if (node == NULL) {
            BookNode* newNode = new BookNode();
            newNode->data = book;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }
        
        if (book.bookID < node->data.bookID) {
            node->left = insertHelper(node->left, book);
        } else if (book.bookID > node->data.bookID) {
            node->right = insertHelper(node->right, book);
        }
        
        return node;
    }
    
 
    BookNode* searchHelper(BookNode* node, int bookID) {
        if (node == NULL) {
            return NULL;
        }
        
        if (bookID == node->data.bookID) {
            return node;
        } else if (bookID < node->data.bookID) {
            return searchHelper(node->left, bookID);
        } else {
            return searchHelper(node->right, bookID);
        }
    }
    
    // Display all books (Inorder)
    void displayAllHelper(BookNode* node) {
        if (node != NULL) {
            displayAllHelper(node->left);
            node->data.display();
            displayAllHelper(node->right);
        }
    }
    
public:
    BookBST() {
        root = NULL;
    }
    
    
    void insert(Book book) {
        root = insertHelper(root, book);
    }
    
    // Search a book by ID
    Book* search(int bookID) {
        BookNode* result = searchHelper(root, bookID);
        if (result != NULL) {
            return &(result->data);
        }
        return NULL;
    }
    
    // Display all books
    void displayAll() {
        if (root == NULL) {
            cout << "\nNo books in library!\n";
            return;
        }
        displayAllHelper(root);
    }
    
    // Convert BST to array 
    int toArray(Book arr[], int maxSize) {
        int index = 0;
        toArrayHelper(root, arr, index, maxSize);
        return index;
    }
    
private:
    void toArrayHelper(BookNode* node, Book arr[], int& index, int maxSize) {
        if (node != NULL && index < maxSize) {
            toArrayHelper(node->left, arr, index, maxSize);
            arr[index++] = node->data;
            toArrayHelper(node->right, arr, index, maxSize);
        }
    }
};

#endif