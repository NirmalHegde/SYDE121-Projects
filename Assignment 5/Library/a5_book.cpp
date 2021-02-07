#include <iostream>
#include <string>
#include "a5_book.hpp"

//Book object without any parameters
Book::Book() :
	title("n/a"),
	authors("n/a"),
	dop("n/a") {}

//Book object with 1 parameter
Book::Book(string new_title) :
	title(new_title),
	authors("n/a"),
	dop("n/a") {}

//Book object with 2 parameters
Book::Book(string new_title, string new_authors) :
	title(new_title),
	authors(new_authors),
	dop("n/a") {}

//Book object with 3 parameters
Book::Book(string new_title, string new_authors, string new_dop) :
	title(new_title),
	authors(new_authors),
	dop(new_dop) {}

//Output books to console
void Book::print() {
	cout << title << " " << authors << " " << dop << endl;
}

//getter function for date of publication
string Book::get_dop(){
	return(dop);
}

//getter function for authors
string Book::get_authors(){
	return(authors);
}

//getter function for title
string Book::get_title(){
	return(title);
}


