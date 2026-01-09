#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <cstring>
using namespace std;

class Book {
public:
    int bookID;
    char title[100];
    char author[50];
    char ISBN[20];
    char genre[30];
    int totalCopies;
    int availableCopies;
    int timesIssued;
    
   
    Book() {
        bookID = 0;
        strcpy(title, "");
        strcpy(author, "");
        strcpy(ISBN, "");
        strcpy(genre, "");
        totalCopies = 0;
        availableCopies = 0;
        timesIssued = 0;
    }
    
    
    void display() {
        cout << "\n--- Book Details ---\n";
        cout << "ID: " << bookID << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Genre: " << genre << endl;
        cout << "Total Copies: " << totalCopies << endl;
        cout << "Available: " << availableCopies << endl;
        cout << "Times Issued: " << timesIssued << endl;
    }
    
    // Issue a book
    bool issueBook() {
        if (availableCopies > 0) {
            availableCopies--;
            timesIssued++;
            return true;
        }
        return false;
    }
    
    // Return a book
    void returnBook() {
        if (availableCopies < totalCopies) {
            availableCopies++;
        }
    }
};

#endif