#include <iostream>
#include <vector>
#include <map>
#include <string> 
using namespace std;

class Book {     //this class is for book informations
private:
    string title, author, publisher;
    int year;
    string Isbn;


public:

    Book() { year = 0; }//this is the constructor

    string GetTitle() { return title; } //these functions are to get the book data
    string GetAuthor() { return author; }
    string GetPublisher() { return publisher; }
    int GetYear() { return year; }
    string GetIsbn() { return Isbn; }

    void SetTitle(string tit) { title = tit; }  //these functions to are set the book data
    void SetAuthor(string auth) { author = auth; }
    void SetPublisher(string pub) { publisher = pub; }
    void SetYear(int yea) { year = yea; }
    void SetIsbn(string isbn) { Isbn = isbn; }

    void BookDisplay() {    //this function to display book informantions
        cout << "Book title: " << title << endl;
        cout << "Book author: " << author << endl;
        cout << "Book publisher: " << publisher << endl;
        cout << "Relased year: " << year << endl;
        cout << "Book ISBN: " << Isbn << endl;
    }


};


class library { //this class for the library functions
private:
    vector<Book>Books;
    map<string, Book> BooksMap;

public:
    void AddBook() {
        string title, author, isbn, publisher;
        int year;

        cout << "Enter the title of the book: " << endl;
        getline(cin, title);
        cout << "Enter the author of the book: " << endl;
        getline(cin, author);
        cout << "Enter the publisher of the book: " << endl;
        getline(cin, publisher);
        cout << "Enter the year of the book: " << endl;
        cin >> year;
        cin.ignore();
        cout << "Enter the ISBN of the book: " << endl;
        getline(cin, isbn);

        if (BooksMap.find(isbn) == BooksMap.end()) {
            Book NewBook;
            NewBook.SetTitle(title);
            NewBook.SetAuthor(author);
            NewBook.SetPublisher(publisher);
            NewBook.SetYear(year);
            NewBook.SetIsbn(isbn);

		Books.push_back(NewBook); //this to add the book to the vector
		BooksMap[isbn] = NewBook; //this to add the book to the map
		
		cout << "\nBook added successfully\n" << endl;
		}
		else {
			cout << "This book is already exists" << endl;
        }

    }


    void EditBookTitle() {
        string title, isbn;

        cout << "Enter the ISBN of the book you want to edit: " << endl;
        getline(cin, isbn);

        if (BooksMap.find(isbn) != BooksMap.end()) { //this to check if the book is in the map
            cout << "Enter the new title: " << endl;
            getline(cin, title);

            Book BookEdit = BooksMap[isbn]; //this to get the book from the map
            BookEdit.SetTitle(title); //this to set the new title for the book

            for (int i = 0; i < Books.size(); i++) { //this loop to edit the vector and we use this loop to edit the book in the vector
                if (Books[i].GetIsbn() == isbn) { //this to check if the book is in the vector
                    Books[i].SetTitle(title); //this to set the new title for the book
                }
                break;
            }
            cout << "\nTitle edited successfully\n" << endl;
        }

        else {
            cout << "Book not found" << endl;
        }


    }


    void EditBookAuthor() {
        string author, isbn;

        cout << "Enter the ISBN of the book you want to edit: " << endl;
        getline(cin, isbn);

        if (BooksMap.find(isbn) != BooksMap.end()) {
            cout << "Enter the new author: " << endl;
            getline(cin, author);

            Book BookEdit = BooksMap[isbn];
            BookEdit.SetAuthor(author);

            for (int i = 0; i < Books.size(); i++) {
                if (Books[i].GetIsbn() == isbn) {
                    Books[i].SetAuthor(author);
                }
                break;
            }
            cout << "\nAuthor edited successfully\n" << endl;
        }

        else {
            cout << "Book not found" << endl;
        }


    }


    void EditBookYear() {
        int year = 0;
        string isbn;

        cout << "Enter the ISBN of the book you want to edit: " << endl;
        getline(cin, isbn);

        if (BooksMap.find(isbn) != BooksMap.end()) {
            cout << "Enter the new Year: " << endl;
            cin >> year;
            cin.ignore();

            Book BookEdit = BooksMap[isbn];
            BookEdit.SetYear(year);

            for (int i = 0; i < Books.size(); i++) {
                if (Books[i].GetIsbn() == isbn) {
                    Books[i].SetYear(year);
                }
                break;
            }
            cout << "\nYear edited successfully\n" << endl;
        }

        else {
            cout << "Book not found" << endl;
        }

    }

    void EditBookPublisher() {
        string publisher, isbn;

        cout << "Enter the ISBN of the book you want to edit: " << endl;
        getline(cin, isbn);

        if (BooksMap.find(isbn) != BooksMap.end()) {
            cout << "Enter the new publisher: " << endl;
            getline(cin, publisher);

            Book BookEdit = BooksMap[isbn];
            BookEdit.SetPublisher(publisher);

            for (int i = 0; i < Books.size(); i++) {
                if (Books[i].GetIsbn() == isbn) {
                    Books[i].SetPublisher(publisher);
                }
                break;
            }
            cout << "\nPublisher edited successfully\n" << endl;
        }

        else {
            cout << "Book not found" << endl;
        }
    }

    void EditBookISBN() {
        string isbn, ISBN;

        cout << "Enter the ISBN of the book you want to edit: " << endl;
        getline(cin, isbn);

        if (BooksMap.find(isbn) != BooksMap.end()) {
            cout << "Enter the new ISBN: " << endl;
            cin >> ISBN;
            cin.ignore();

            Book BookEdit = BooksMap[isbn];
            BookEdit.SetIsbn(ISBN);

            for (int i = 0; i < Books.size(); i++) {
                if (Books[i].GetIsbn() == isbn) {
                    Books[i].SetIsbn(ISBN);

                }
                break;
            }
            cout << "\nISBN edited successfully\n" << endl;
        }

        else {
            cout << "Book not found" << endl;
        }

    }

    void RemoveBook() {
        string isbn;
        char RemoveChoice;

        cout << "Enter the ISBN of the book that you want to delete: ";
        getline(cin, isbn);

		cout << "I want to delete: [" << BooksMap[isbn].GetTitle() << "] (y / n)" << endl; //this to confirm the book that the user want to delete
        cin >> RemoveChoice;
        cin.ignore();

        if (RemoveChoice == 'y' || RemoveChoice == 'Y') { 
            if (BooksMap.find(isbn) != BooksMap.end()) {
				BooksMap.erase(isbn); //this to delete the book from the map

                for (int i = 0;i < Books.size(); i++) {
                    if (Books[i].GetIsbn() == isbn) {
                        Books.erase(Books.begin() + i); //this to delete the book from the vector

                    }
                    break;
                }
                cout << "\nBook deleted successfully\n";
            }
            else {
                cout << "Book not found" << endl;
            }
        }
        else if (RemoveChoice == 'n' || RemoveChoice == 'N') {
            cout << "Backing to menu..." << endl;
        }
        else {
            cout << "please enter 'y' or 'n'" << endl;
        }

    }

    void ClearBooks() {
        char ClearChoice;
        cout << "Do you want to CLEAR your library? (y/n)" << endl;
        cin >> ClearChoice;

        if (ClearChoice == 'y' || ClearChoice == 'Y') {
            BooksMap.clear(); //this to clear the map
            Books.clear(); //this to clear the vector
            cout << "\nLibrary cleared successfully" << endl;
        }


        else if (ClearChoice == 'n' || ClearChoice == 'N') {
            cout << "Backing to menu..." << endl;
        }
        else {
            cout << "please enter 'y' or 'n'" << endl;
        }

    }


    void SearchBook() {
        string isbn;

        cout << "Enter the isbn of the book: ";
        getline(cin, isbn);



        if (BooksMap.find(isbn) != BooksMap.end()) {
            Book BookSearch = BooksMap[isbn]; //this to get the book from the map by the isbn

            cout <<"TITLE: " << BookSearch.GetTitle() << " | "; //this to display the book informantions
           cout <<"AUTHOR: " << BookSearch.GetAuthor() << " | ";
           cout << "ISBN: " << BookSearch.GetIsbn() << " | ";
			cout <<"PUBLISHER: " << BookSearch.GetPublisher() << " | ";
			cout <<"YEAR: " << BookSearch.GetYear();
			cout << "\n-------------------------------------" << endl;

            cout << "\n" << endl;
        }
        else {
            cout << "Book not found" << endl;
        }
    }


    void DisplayBooks() {
        if (Books.empty()) { //this to check if the vector is empty
            cout << "sorry there is no books available now" << endl;
            return;
        }
        else {

            cout << "Your books list: \n" << endl;
            for (int i = 0; i < Books.size(); i++) {
                cout << "[Book " << i + 1 << "]" << ": " << endl; //this to display the book number
                Books[i].BookDisplay();
                cout << "-------------------------------------" << endl;
            }
        }
    }


};

int main() {
    Book TheBook;   //this is the Book class object
    library TheLibrary; //this is the library class object

    //this is the menu variables
    int choice;

    //this is the menu
    while (true) { //this is the menu infinite loop
        cout << "======================================" << endl;
        cout << "WELCOME TO ABDULLAH LIBRARY\n\n";
        cout << "[1] Add" << endl;
        cout << "[2] Delete" << endl;;
        cout << "[3] Edit" << endl;;
        cout << "[4] Search" << endl;
        cout << "[5] Display All Books" << endl;
        cout << "[6] Exit\n\n";

        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();
        cout << "======================================" << endl;

        switch (choice) {
        case 1:
            cout << "Add a new book\n----------------------------" << endl;
            TheLibrary.AddBook();
            break;

        case 2:
            int RemoveChoice;
            cout << "[1] A single book" << endl;
            cout << "[2] All the books\n" << endl;

            cout << "what you want to delete? " << endl;
            cin >> RemoveChoice;
            cin.ignore();


            switch (RemoveChoice) { //this is the switch case to check what the user want to delete
            case 1:
                TheLibrary.RemoveBook();
                break;

            case 2:
                TheLibrary.ClearBooks();
                break;
            }
            break;
        case 3:
            int EditChoice;

            cout << "[1] Edit Title" << endl;
            cout << "[2] Edit Author" << endl;
            cout << "[3] Edit Year" << endl;
            cout << "[4] Edit Publisher" << endl;
            cout << "[5] Edit ISBN\n" << endl;

            cout << "What you want to edit?" << endl;
            cin >> EditChoice;
            cin.ignore();

            switch (EditChoice) { //this is the switch case to check what the user want to edit
            case 1:
                TheLibrary.EditBookTitle();
                break;

            case 2:
                TheLibrary.EditBookAuthor();
                break;

            case 3:
                TheLibrary.EditBookYear();
                break;

            case 4:
                TheLibrary.EditBookPublisher();
                break;
            case 5:
                TheLibrary.EditBookISBN();
                break;

            }
            break;

        case 4:
            TheLibrary.SearchBook();
            break;

        case 5:
            TheLibrary.DisplayBooks();
            break;

        case 6:
            cout << "Thank you for using ABDULLAH LIBRARY\nSee you soon (:" << endl;
        }
        if (choice == 6) { //this to exit the program
            break;
        }
    }
    return 0;

}

