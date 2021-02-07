/*
************************************************************
Student Name: Brendan Marshall, Nirmal Hegde
Student Number: 20894403

SYDE 121 Assignment 005

I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts. This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Project: Books & Libraries
Purpose: Create a virtual library
Due Date: Friday, November 20th, 2020
*************************************************************


TESTING SCENARIOS:

1. Created several books that accounted for all different parameter types (books with 3 parameters, 2 parameters, 1 parameter, and 0 parameters)
2. Created two libraries to account for all parameter types (libraries with a vector, libraries without a vector)
3. Tested the insertion of multiple books of each parameter type into a library (to account for all successful outcomes)
4. Tested the insertion of duplicate books to ensure they were not added
5. Tested the removal of books of each parameter type to accout for all removed outcomes
6. Tested removal of a book that did not exist to ensure the program handled the error correctly
7. Tested the console to ensure the correct values were being outputted


LIMITATIONS:

- It is case sensitive, which results in typos not removing/inserting books when required
- Does not account for more than 3 parameters for Books
- Does not account for only an author or date of publication, as no book would not have a title
- Does not allow for user input (all values must be hardcoded)

*/

//library declaration
#include <iostream>
#include <cassert>

//file insertion
#include "a5_book.hpp"
#include "a5_library.hpp"

//namespace
using namespace std;

//function to test the removal of a book from a library
void test_book_removal(Library& tips, Library& barren, Book dictionary, Book empty) {

    cout << "Testing removal:  " << endl;

    //test removal of book that exists 
    assert(tips.remove("Gaming tips", "Brendan Marshall", "11/12/1996"));

    assert(tips.remove(empty));

    assert(!tips.remove(dictionary));

    //test removal of book that does not exist
    assert(!barren.remove("77", "33", "12"));

    //print result
    tips.print();
    barren.print();

    cout << "-----Testing complete------" << endl;
}

//function to test the insertion of a book into a library
void test_book_insertion(Library& tips, Library& barren, Book dictionary, Book learning) {

    cout << "Testing insertion:  " << endl;

    //tests insert function with new book
    assert(barren.insert("How to lose", "James Charles", "10/11/1111"));

    assert(barren.insert(dictionary));

    //tests insert function with duplicate book
    assert(!tips.insert("Gaming tips", "Brendan Marshall", "11/12/1996"));

    assert(!tips.insert(learning));

    //print result
    tips.print();
    barren.print();

    cout << "-----Testing complete------\n\n" << endl;
}

void initial_library_creation(Library& tips, Library& barren, vector<Book> hoard) {
    cout << "Testing Library Creation:  " << endl;

    //creates Libraries, one empty and one filled with the book objects from the book class made (testing all outcomes)
    barren = Library();
    tips = Library(hoard);

    //prints libraries to console
    barren.print();
    tips.print();

    cout << "-----Testing complete------\n\n" << endl;
}

//Initial Book Creation
void initial_book_creation(Book& gaming, Book& life_hacks, Book& learning, Book& empty, Book& dictionary) {
    cout << "Testing Book Creation:  " << endl;

    //All parameter types used
    gaming = Book("Gaming tips", "Brendan Marshall", "11/12/1996");
    life_hacks = Book("Life Hacks", "Nirmal Hegde");
    learning = Book("SYDE 121 Lesson");
    empty = Book();

    dictionary = Book("All of the words", "Old man #15", "1/1/1");

    //Output of all parameter types to console
    gaming.print();
    life_hacks.print();
    learning.print();
    empty.print();

    dictionary.print();

    cout << "-----Testing complete------\n\n" << endl;
}

//root function containing all tests
void tests() {
    //Class declaration
    Book gaming, life_hacks, learning, empty, dictionary;
    Library tips, barren;

    //PURPOSE: Create books of each parameter type
    initial_book_creation(gaming, life_hacks, learning, empty, dictionary);

    //vector declaration
    vector<Book> hoard = { gaming, life_hacks, learning, empty };

    //PURPOSE: Create libraries of each parameter type
    initial_library_creation(tips, barren, hoard);

    //PURPOSE: Test insertion and removal of books
    test_book_insertion(tips, barren, dictionary, learning);
    test_book_removal(tips, barren, dictionary, empty);
}

//initialization
int main() {
    tests();
}