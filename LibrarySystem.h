#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H

#include "Book.h"
#include "Member.h"
#include "Loan.h"
#include "BST.h"
#include "Queue.h"
#include "Recommendation.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>    
#include <cstdio>    
#include <limits>    

using namespace std;

class LibrarySystem {
private:
    static const int MAX_MEMBERS = 100;
    static const int MAX_LOANS   = 500;
    static const int MAX_BOOKS_ARR = 100;

    
    static const int MAX_BOOK_ID = 1000;

    BookBST bookTree;

    Member members[MAX_MEMBERS];
    int memberCount;

    Loan loans[MAX_LOANS];
    int loanCount;

    
    ReservationQueue reservations[MAX_BOOK_ID];

public:
    LibrarySystem();

    //  BOOK OPERATIONS 

    void addBook();
    void searchBook();
    void searchByField(char* searchTerm, int field);
    void displayBookTable(Book* books, int count);
    void displayAllBooks();

    //  MEMBER OPERATIONS 

    void addMember();
    Member* searchMember(int memberID);
    void displayAllMembers();

    // ✅ NEW: Load members (so option 5 shows members after restart)
    void loadMembers();

    //  ISSUE/RETURN OPERATIONS 

    void issueBook();
    char* getCurrentDate();
    char* getDueDate();
    void returnBook();

    //  REPORTS 

    void displayActiveLoans();
    void displayOverdueBooks();
    void displayTopIssuedBooks();

    //  FILE OPERATIONS 

    void saveBooks();
    void loadBooks();
    void saveMembers();

    //  RECOMMENDATION SYSTEM 

    void getRecommendations();
    void clusterAllBooks();
    void findSimilarBooks();
    void recommendByGenre();

    // Browse by category (kept)
    void browseByCategory();

    void viewMemberHistory();
    void showDashboard();
};

#endif
