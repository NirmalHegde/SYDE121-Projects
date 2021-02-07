#ifndef A5_LIBRARY_HPP
#define A5_LIBRARY_HPP

#include <iostream>
#include <string>
#include <vector>
#include "a5_book.hpp"
using namespace std;

//Library class for storing all books in libraries
class Library {
    //vector declaration
    vector<Book> books;
public:
    //Library objects (one without vector, one with vector)
    Library();
    Library(vector<Book> new_books);

    //check duplicate function
    bool check_duplicate(Book);
    
    //insert function and helper function
    bool insert(Book);
    bool insert(string, string, string);

    //removal function and helper function
	bool remove(Book);
	bool remove(string, string, string);

    //print function
    void print();
};

#endif