#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <cstring>
using namespace std;

class Member {
public:
    int memberID;
    char name[50];
    char email[50];
    char phone[15];
    int booksBorrowed;

    int borrowHistory[20]; 
    int historyCount;
    double fineAmount;
    
 

  
    
    
    Member() {
        memberID = 0;
        strcpy(name, "");
        strcpy(email, "");
        strcpy(phone, "");
        booksBorrowed = 0;
        historyCount = 0;
        fineAmount = 0.0;
        for (int i = 0; i < 20; i++) {
            borrowHistory[i] = 0;
        }
    }
    
    // Display member info
    void display() {
        cout << "\n--- Member Details ---\n";
        cout << "ID: " << memberID << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl;
        cout << "Books Borrowed: " << booksBorrowed << endl;
        cout << "Fine Amount: Rs." << fineAmount << endl;
    }
    

    bool canBorrow() {
        return booksBorrowed < 5;  
    }
    
    // Add book to history
    void addToHistory(int bookID) {
        if (historyCount < 20) {
            borrowHistory[historyCount] = bookID;
            historyCount++;
        }
    }
};

#endif
