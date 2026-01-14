#include <iostream>
#include <limits>
#include "LibrarySystem.h"

using namespace std;

static void displayMenu() {
    cout << "\n╔══════════════════════════════════════════════╗\n";
    cout << "║      LIBRARY MANAGEMENT SYSTEM               ║\n";
    cout << "╚══════════════════════════════════════════════╝\n";

    cout << "\n📚 BOOK MANAGEMENT\n";
    cout << "  1. Add Book\n";
    cout << "  2. Search Book\n";
    cout << "  3. Display All Books\n";

    cout << "\n👥 MEMBER MANAGEMENT\n";
    cout << "  4. Register Member\n";
    cout << "  5. Display All Members\n";
    cout << "  6. View Member History\n";

    cout << "\n📋 TRANSACTIONS\n";
    cout << "  7. Issue Book\n";
    cout << "  8. Return Book\n";
    cout << "  9. Display Active Loans\n";
    cout << " 10. Display Overdue Books\n";

    cout << "\n🤖 RECOMMENDATION / CLUSTERING\n";
    cout << " 11. Get Recommendations\n";
    cout << " 12. Cluster All Books\n";
    cout << " 13. Find Similar Books\n";
    cout << " 14. Recommend By Genre\n";
    cout << " 15. Browse By Category\n";

    cout << "\n📊 DASHBOARD\n";
    cout << " 16. Show Dashboard\n";

    cout << "\n💾 FILE\n";
    cout << " 17. Save Books\n";

    cout << "\n  0. Exit\n";
    cout << "\nEnter choice: ";
}

int main() {
    LibrarySystem system;

    
    system.loadBooks();
    system.loadMembers();

    int choice;

    while (true) {
        displayMenu();

        if (!(cin >> choice)) {
            // If user enters non-number, fix input stream
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n✗ Invalid input! Please enter a number.\n";
            continue;
        }

        // Clear leftover newline so getline inside functions won't break
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:  system.addBook(); break;
            case 2:  system.searchBook(); break;
            case 3:  system.displayAllBooks(); break;

            case 4:  system.addMember(); break;              
            case 5:  system.displayAllMembers(); break;
            case 6:  system.viewMemberHistory(); break;

            case 7:  system.issueBook(); break;
            case 8:  system.returnBook(); break;
            case 9:  system.displayActiveLoans(); break;
            case 10: system.displayOverdueBooks(); break;

            case 11: system.getRecommendations(); break;
            case 12: system.clusterAllBooks(); break;
            case 13: system.findSimilarBooks(); break;
            case 14: system.recommendByGenre(); break;
            case 15: system.browseByCategory(); break;

            case 16: system.showDashboard(); break;

            case 17: system.saveBooks(); break;

            case 0:
                cout << "\nGoodbye!\n";
                system.saveBooks();
                system.saveMembers();
                return 0;

           
            default:
                cout << "\n✗ Invalid choice! Try again.\n";
                break;
        }
    }
}
