#ifndef A5_BOOK_HPP
#define A5_BOOK_HPP

#include <iostream>
#include <string>
using namespace std;

//book class for all books
class Book {
    //parameter declaration
    string title, authors, dop;

public:
    //different book object parameter types
    Book();
    Book(string new_title);
    Book(string new_title, string new_authors);
    Book(string new_title, string new_authors, string new_dop);

    //print function declaration
    void print();
    
    //getter function declarations
    string get_dop();
    string get_authors();
    string get_title();
};
#endif