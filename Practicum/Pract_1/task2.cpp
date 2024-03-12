/*Да се създаде структура Book със следните характеристики: заглавие (до 50 символа) , автор (до 50 символа), жанр и наличност.
Жанровете са ограничени и могат да бъдат "Роман", "Исторически", "Поезия" и "Друг".
Да се създаде структура Libary, която се описва с константен брой книги (вие изберете този брой).
Реализирайте функции за :
инициализиране на книга;
добавяне на нова книга в библиотеката (ако капацитетът е запълнен, да се изведе съобщение);
вземане на книга по подадено заглавие;
връщане на книга по подадено заглавие;
извеждане на информация за всички книги в библиотеката.*/

#include <iostream>
#include <cstring>
#pragma warning (disable: 4996)

enum class Genre {
	Roman,
	Historic,
	Poetry,
	Other
};

struct Book {
	char title[51] = "";
	char author[51] = "";
	Genre genre = Genre::Other;
	unsigned inStock = 0;
};

struct Library {
	Book books[10];
	size_t capacity = 0;
	bool takenBooks[10]{ false };
};

char* getGenre(const Genre& genre) {
	char res[9];
	switch (genre) {
	case Genre::Roman: strcpy(res, "Roman"); return res;
	case Genre::Historic: strcpy(res, "Historic"); return res;
	case Genre::Poetry: strcpy(res, "Poetry"); return res;
	case Genre::Other: strcpy(res, "Other"); return res;
	default:
		return nullptr;
	}
}

void setGenre(const char* text, Book& book) {
	if (!strcmp(text, "Roman")) {
		book.genre = Genre::Roman;
		return;
	}
	else if (!strcmp(text, "Historic")) {
		book.genre = Genre::Historic;
		return;
	}
	else if (!strcmp(text, "Poetry")) {
		book.genre = Genre::Poetry;
		return;
	}
	else if (!strcmp(text, "Other")) {
		book.genre = Genre::Other;
		return;
	}
	return;
}

void initializeBook(Book& book) {
	char genre[9];
	std::cin >> book.title 
			>> book.author 
			>> genre
			>> book.inStock;
	setGenre(genre, book);
}

void addBookToLib(Library& lib, const Book& newBook) {
	if (lib.capacity == 10) {
		std::cerr << "No more space for books" << std::endl;
		return;
	}
	lib.books[lib.capacity++] = newBook;
}

void getBookByTitle(Library& lib, const char* title) {
	for (size_t i = 0; i < lib.capacity; i++) {
		if (!strcmp(lib.books[i].title, title)) {
			lib.takenBooks[i] = true;
			return;
		}
	}
	std::cerr << "No book with the given title found in library!" << std::endl;
}

void returnBookByTitle(Library& lib, const char* title) {
	for (size_t i = 0; i < lib.capacity; i++) {
		if (!strcmp(lib.books[i].title, title)) {
			lib.takenBooks[i] = false;
			return;
		}
	}
	std::cerr << "No book with the given title found in library!" << std::endl;
}

void printGenre(Genre genre) {
	switch (genre){
	case Genre::Roman:
		std::cout << "Roman";
		break;
	case Genre::Historic:
		std::cout << "Historic";
		break;
	case Genre::Poetry:
		std::cout << "Poetry";
		break;
	case Genre::Other:
		std::cout << "Other";
		break;
	default:
		break;
	}
}

void printLibraryInformation(const Library& lib) {
	for (size_t i = 0; i < lib.capacity; i++) {
		std::cout << "Book number: " << i << ". " << std::endl;
		std::cout << "\t Title: \"" << lib.books[i].title << "\" , " << std::endl;
		std::cout << "\t Author: " << lib.books[i].author << ", " << std::endl;
		std::cout << "\t Genre: "; printGenre(lib.books[i].genre); std::cout << ", " << std::endl;
		std::cout << "\t In stock: " << lib.books[i].inStock << ", " << std::endl;
		std::cout << "\t Is currently in library: " << (lib.takenBooks[i] ? "no" : "yes") << "." << std::endl;
		std::cout << std::endl;
	}
}

int main() {
	Library lib
	{
		{
			{"Book1Title", "AuthorOfBook1", Genre::Historic, 2},
			{"Book2Title", "AuthorOfBook2", Genre::Poetry, 1},
			{"Book3Title", "AuthorOfBook3", Genre::Roman, 1},
			{"Book4Title", "AuthorOfBook4", Genre::Other, 2},
		},
		4, {0,0,0,0}
	};
	Book book5{ "Book5Title", "AuthorOfBook5", Genre::Poetry, 1 };
	addBookToLib(lib, book5);
	getBookByTitle(lib, "gs");
	returnBookByTitle(lib, "Book5Title");
	printLibraryInformation(lib);
}