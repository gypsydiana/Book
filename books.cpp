#include"books.h"
void Cathalog::AddBook(string title, vector<string>authors, unsigned int year, string publisher, unsigned int pages, unsigned int ID, unsigned int quantity, unsigned int instances, vector<reader>picked) {
	cathalog_book b(title, authors, year, publisher, pages, ID,  quantity, instances, picked);
	this->cathalog.push_back(b);
}
void Cathalog::DeleteBookCathalog(string name) {
	for (int i = 0; i < cathalog.size(); i++) {
		if (cathalog[i].title == name) {
			cathalog.erase(cathalog.begin() + i);
			cout << "Книга " << name << "удалена";
		}
	}
}
book::book(string title, vector<string>authors, unsigned int year, string publisher, unsigned int pages) {
	this->title = title;
	this->year = year;
	this->publisher = publisher;
	this->pages = pages;
	this->authors = authors;
}
cathalog_book::cathalog_book(string title, vector<string>authors, unsigned int year, string publisher, unsigned int pages, unsigned int ID, unsigned int quantity, unsigned int instances, vector<reader>picked):book(title, authors, year, publisher, pages) {
	this->ID = ID;
	this->quantity = quantity;
	this->instances = instances;
	this->picked = picked;
}
void Cathalog::Output_id_and_reader(unsigned int id) {
	for (int i = 0; i < cathalog.size(); i++) {
		if (cathalog[i].ID == id) {
			cout << "Название:" << cathalog[i].title << endl;
			cout << "Авторы:";
			for (int j = 0; j < cathalog[i].authors.size(); j++) {
				cout << cathalog[i].authors[j]<<" ";
			}
			cout << endl;
			cout << "Год издания:" << cathalog[i].year << endl;
			cout << "Издательство:" << cathalog[i].publisher << endl;
			cout << "Количество страниц:" << cathalog[i].pages << endl;
			cout << "Общее количество экземпляров:" << cathalog[i].quantity << endl;
			cout << "Количество экземпляров в наличии:" << cathalog[i].instances << endl;
			cout << "Список читателей, взявших книгу, с датой выдачи:" << endl;
			for (int n = 0; n < cathalog[i].picked.size(); n++) {
				cout << "Имя читателя:" << cathalog[i].picked[n].name << endl;
				cout << "Дата выдачи:" << cathalog[i].picked[n].Day << '.'<< cathalog[i].picked[n].Month<<'.'<< cathalog[i].picked[n].Year<<endl;
			}
		}
	}
}
void Cathalog::SearchBook(string name, string author) {
	bool Author;
	for (int i = 0; i < cathalog.size(); i++) {
		for (int j = 0; j < cathalog.size(); j++) {
			if ((cathalog[i].authors[j] == author)) {
				Author = true;
			}
			if(Author && (cathalog[i].title == name)) {
				cout << "Идентификатор в каталоге:" << cathalog[i].ID << endl;
			}
		}
	}
}
void Cathalog::IssuanceBook(string nametitle, string nname, unsigned int dDay, unsigned int mMonth, unsigned int yYear) {
	reader r;
	for (int i = 0; i < cathalog.size(); i++) {
		if (cathalog[i].title == nametitle) {
			if (cathalog[i].instances > 0) {
				cathalog[i].instances--;
				r.Day = dDay;
				r.Month = mMonth;
				r.Year = yYear;
				r.name = nname;
				this->cathalog[i].picked.push_back(r);
			}
			else {
				cout << "К сожалению, выбранной книги нет в наличии :(" << endl;
			}
		}
	}
}
void Cathalog::Return_of_the_book(string nametitle, string nname) {
	for (int i = 0; i < cathalog.size(); i++) {
		if (cathalog[i].title == nametitle) {
			cathalog[i].instances++;
			for (int j = 0; j < cathalog.size(); j++) {
				if (cathalog[i].picked[j].name == nname) {
					this->cathalog[i].picked.erase(cathalog[i].picked.begin() + j);
				}
			}
		}
		break;
	}
}
void Cathalog::DebtorsReaders(unsigned int dDay, unsigned int mMonth, unsigned int yYear) {
	for (int i = 0; i < cathalog.size(); i++) {
		cout << "Задолжность по книге:" << cathalog[i].title << endl;
		for (int j = 0; j < cathalog.size(); j++) {
			if (yYear - cathalog[i].picked[j].Year>=2) {
				cout << cathalog[i].picked[j].name << endl;
			}
			else if (yYear-cathalog[i].picked[j].Year  == 1) {
				if (cathalog[i].picked[j].Month < mMonth) {
					cout << cathalog[i].picked[j].name << endl;
				}
				else if (cathalog[i].picked[j].Month == mMonth) {
					if (cathalog[i].picked[j].Day < dDay) {
						cout << cathalog[i].picked[j].name << endl;
					}
					else {
						cout << "Нет задолженности" << endl;
					}
				}
				else {
					cout << "Нет задолженности" << endl;
				}
			}
			else {
				cout << "Нет задолженности" << endl;
			}
		}
	}
}






