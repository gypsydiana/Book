#ifndef books_H
#define books_H
#include <iostream>
#include <istream>
#include <vector>
#include <string>
using namespace std;
struct reader {
	string name;
	unsigned int Day;
	unsigned int Month;
	unsigned int Year;
	reader(){}
	reader(string name, unsigned int Day, unsigned int Month, unsigned int Year ) {
		this->name = name;
		this->Day = Day;
		this->Month = Month;
		this->Year = Year;
	}
};
class book {
public:
	string title;
	vector<string>authors;
	unsigned int year;
	string publisher;
	unsigned int pages;
public:
	book() {};
	book(string title, vector<string>authors, unsigned int year, string publisher, unsigned int pages);
};
class cathalog_book :public book {
public:
	unsigned int ID;
	unsigned int quantity;
	unsigned int instances;
	vector<reader>picked;
public:
	cathalog_book() {};
	cathalog_book(string title, vector<string>authors, unsigned int year, string publisher, unsigned int pages, unsigned int ID, unsigned int quantity, unsigned int instances, vector<reader>picked);
};
class Cathalog {
private:
	vector<cathalog_book>cathalog;
public:
	void AddBook(string title, vector<string>authors, unsigned int year, string publisher, unsigned int pages, unsigned int ID, unsigned int quantity, unsigned int instances,vector<reader>picked);
	void DeleteBookCathalog(string name);
	void Output_id_and_reader(unsigned int id);
	void SearchBook(string name, string author);
	void IssuanceBook(string nametitle, string nname, unsigned int dDay, unsigned int mMonth, unsigned int yYear);
	void Return_of_the_book(string nametitle, string nname);
	void DebtorsReaders(unsigned int dDay, unsigned int mMonth, unsigned int yYear);
};

#endif books_H
