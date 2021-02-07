#include <iostream>
#include <vector>
#include "a5_library.hpp"

//empty library object
Library::Library() :
    books(vector<Book>{}) {}

//library object with vectors
Library::Library(vector<Book> b) :
    books(b) {}

//function to check if there is a duplicate when inserting a book
bool Library::check_duplicate(Book inserting_book) {
    bool duplicate = false;
    //loop through all books and detect if all the parameters are equal, if so, then save boolean variable duplicate to be true
    for (unsigned int i = 0; i < books.size(); i++) {
        Book temp = books.at(i);
        if (temp.get_title() == inserting_book.get_title() && temp.get_authors() == inserting_book.get_authors() && temp.get_dop() == inserting_book.get_dop()) {
            duplicate = true;
        }
    }

    //return for later use
    return duplicate;
}

//helper function to insert book
bool Library::insert(Book inserting_book) {
    //uses check_duplicated function to get a boolean value for duplicate
    bool is_duplicate = check_duplicate(inserting_book);

    //if the book being inserted is not a duplicate, add the book to the library
    if (!is_duplicate) {
        books.push_back(inserting_book);
    }

    //return the opposite of is_duplicate for later use
    return !is_duplicate;
}

//calling function to insert book
bool Library::insert(string new_title, string new_authors, string new_dop) {
        //if there is 3 parameters, save the variable then call the helper function
        Book inserting_book = Book(new_title, new_authors, new_dop);
        return insert(inserting_book);
};

//helper function for removing book
bool Library::remove(Book removing_book) {
    bool book_found = false;
    //loop through all books, if there is a match, erase it and change boolean value
    for (unsigned int i = 0; i < books.size(); i++) {
        Book temp = books.at(i);
        if (temp.get_title() == removing_book.get_title() && temp.get_authors() == removing_book.get_authors() && temp.get_dop() == removing_book.get_dop()) {
            book_found = true;
            books.erase(books.begin() + i);
        }
    }

    //return boolean for later use
    return book_found;
}

//calling function for removing book
bool Library::remove(string new_title, string new_authors, string new_dop) {
    //for books with 3 parameters, save new object then call the helper function
    Book removing_book = Book(new_title, new_authors, new_dop);
    return remove(removing_book);
}

//print function for libraries
void Library::print() {
    //for loop to loop through all books in library and print to console
    for (unsigned int i = 0; i < books.size(); i++) {
        cout << i << " ";
        Book temp = books.at(i);
        temp.print();
    }
}