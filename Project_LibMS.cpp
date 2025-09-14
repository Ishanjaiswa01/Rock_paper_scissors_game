#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isIssued;
};

vector<Book> books;

void loadBooks() {
    ifstream file("books.txt");
    if (!file) return;
    Book b;
    while (file >> b.id >> ws && getline(file, b.title) && getline(file, b.author) && file >> b.isIssued) {
        books.push_back(b);
    }
    file.close();
}

void saveBooks() {
    ofstream file("books.txt");
    for (const auto& b : books) {
        file << b.id << '\n' << b.title << '\n' << b.author << '\n' << b.isIssued << '\n';
    }
    file.close();
}

void addBook() {
    Book b;
    cout << "Enter Book ID: "; cin >> b.id;
    cin.ignore();
    cout << "Enter Book Title: "; getline(cin, b.title);
    cout << "Enter Author Name: "; getline(cin, b.author);
    b.isIssued = false;
    books.push_back(b);
    saveBooks();
    cout << "Book added successfully!\n";
}

void displayBooks() {
    if (books.empty()) {
        cout << "No books available!\n";
        return;
    }
    for (const auto& b : books) {
        cout << "ID: " << b.id << " | Title: " << b.title << " | Author: " << b.author << " | "
             << (b.isIssued ? "Issued" : "Available") << "\n";
    }
}

void issueBook() {
    int id;
    cout << "Enter Book ID to Issue: "; cin >> id;
    for (auto& b : books) {
        if (b.id == id && !b.isIssued) {
            b.isIssued = true;
            saveBooks();
            cout << "Book issued successfully!\n";
            return;
        }
    }
    cout << "Book not found or already issued!\n";
}

void returnBook() {
    int id;
    cout << "Enter Book ID to Return: "; cin >> id;
    for (auto& b : books) {
        if (b.id == id && b.isIssued) {
            b.isIssued = false;
            saveBooks();
            cout << "Book returned successfully!\n";
            return;
        }
    }
    cout << "Book not found or not issued!\n";
}

int main() {
    loadBooks();
    int choice;
    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n2. Display Books\n3. Issue Book\n4. Return Book\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    return 0;
}