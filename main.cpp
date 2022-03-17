#include"books.h"
int menu() {
	setlocale(LC_ALL, "Russian");
	string title,name,publisher,author;
	unsigned int Day, Month, Year,ID,year,pages,quantity,instances,number;
	vector<string>authors;
	vector<reader>picked;
	Cathalog user;
	int knopka;
	while (true) {
		cout << "1 " << "Добавьте книгу" << endl;
		cout << "2 " << "Удалите книгу" << endl;
		cout << "3 " << "Вывод информации по книге и читателям, взявшим книгу (по идентификатору книги)" << endl;
		cout << "4 " << "Поиск книги в каталоге по названию и по автору с выдачей идентификатора" << endl;
		cout << "5 " << "Выдача книги читателю" << endl;
		cout << "6 " << "Возврат книги читателем" << endl;
		cout << "7 " << "Вывод списка читателей, не вернувших книги в течение года" << endl;
		cout << "8 " << "Выход" << endl;
		cin >> knopka;
		system("cls");
		switch (knopka)
		{
		case 1:
			cout << "Введите все данные о добавляемой книге" << endl;
			cout << "Название:";
			cin >> title;
			cout << endl << "Автор(ы)";
			cout << endl << "Введите количество авторов:";
			cin >> number;
			for (int i = 1; i <= number; i++) {
				cin >> author;
				authors.push_back(author);
			}
			cout << endl << "Год издания:";
			cin >> year;
			cout << endl << "Издательство:";
			cin >> publisher;
			cout << endl << "Количество страниц:";
			cin >> pages;
			cout << endl << "Идентификатор в каталоге:";
			cin >> ID;
			cout << endl << "Общее количество экземпляров:";
			cin >> quantity;
			cout << endl << "Количество экземпляров в наличии:";
			cin >> instances;
			cout << endl;
			user.AddBook(title,authors, year, publisher, pages, ID, quantity, instances,picked);
			authors.clear();
			break;
		case 2:
			cout << "Введите название удаляемой книги:";
			cin >> title;
			cout << endl;
			user.DeleteBookCathalog(title);
			break;
		case 3:
			cout << "Введите ID книги:";
			cin >> ID;
			cout << endl;
			user.Output_id_and_reader(ID);
			break;
		case 4:
			cout << "Введите название:";
			cin >> title;
			cout <<endl<< "Введите автора:";
			cin >> author;
			cout << endl;
			user.SearchBook(title, author);
			break;
		case 5:
			cout << "Введите информацию о выдаваемой книге и получателе"<<endl;
			cout << "Введите название книги:";
			cin >> title;
			cout << endl << "Введите имя:";
			cin >> name;
			cout << endl << "Введите число:";
			cin >> Day;
			cout << endl << "Введите месяц:";
			cin >> Month;
			cout << endl << "Введите год:";
			cin >> Year;
			cout << endl;
			user.IssuanceBook(title, name, Day, Month, Year);
			break;
		case 6:
			cout << "Возврат книги" << endl;
			cout << "Введите название книги:";
			cin >> title;
			cout << endl << "Введите имя возвращающего книгу человека:";
			cin >> name;
			cout << endl;
			user.Return_of_the_book(title,name);
			break;
		case 7:
			cout << "Введите сегодняшнюю дату"<<endl;
			cout << "Число:";
			cin >> Day;
			cout << endl <<"Месяц:";
			cin >> Month;
			cout << endl << "Год:";
			cin >> Year;
			cout << endl;
			user.DebtorsReaders(Day, Month, Year);
			break;
		case 8:
			system("pause");
			break;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	menu();
	return 0;
}