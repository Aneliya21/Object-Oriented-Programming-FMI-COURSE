/*Да се създаде структура Product, която се описва със следните характеристики:

име на продукта (до 100 символа);
количество в наличност (цяло число);
цена на продукта (дробно число);
категория на продукта - ELECTRONICS, CLOTHING, BOOKS, FOOD или BEAUTY;
доставчик на продукта (до 100 символа);
Да се създаде програма, която управлява склад от продукти, като информацията се съхранява в двоичен файл. Нека програмата поддържа следните функционалности:

Зареждане на продуктите от двоичен файл в паметта;

По подаден двоичен файл да се вкарат n продукта, като информация за тях се чете от конзолата. Ако информацията, въведена за някой продукт, 
е валидна, и ако няма вече такова име на продукт във файла, продуктът се запазва в двоичния файл;

Промяна на информацията за наличното количество от даден продукт и записване на новите данни във файла;

Извеждане на информация за всички продукти от склада;

Извеждане на информация за конкретен продукт по подадено име;

По подадено име на друг файл и категория да се запишат всички продукти от дадената категория в съответния файл; */

#include <iostream>
#include <fstream>

namespace Constants {
	constexpr size_t MAX_LEN = 100;
	constexpr size_t MAX_SIZE_PRODS = 10;
}
namespace Validations {
	bool isStringValid(const char* str) {
		return (str != nullptr && strlen(str) < Constants::MAX_LEN);
	}
	bool isValidCathegory(int n) {
		return n >= 0 && n <= 5;
	}
	bool isValidPrice(double price) {
		return price >= 0.0;
	}
}

enum class Cathegory {
	ELECTRONICS,
	CLOTHING,
	BOOKS,
	FOOD,
	BEAUTY,
	OTHER
};

struct Product {
	char productName[Constants::MAX_LEN + 1] = "";
	int inStock = 0;
	double productPrice = 0.0;
	Cathegory productCathegory = Cathegory::OTHER;
	char productSupplier[Constants::MAX_LEN + 1] = "";
};

void printProduct(const Product prod) {
	std::cout << "Name: " << prod.productName << ", ";
	std::cout << "In stock: " << prod.inStock << ", ";
	std::cout << "Price: " << prod.productPrice << ", ";
	std::cout << "Cathegory: " << (int)prod.productCathegory << ", ";
	std::cout << "Supplier: " << prod.productSupplier;
}

void printProducts(const Product* prod, size_t n) {
	for (size_t i = 0; i < n; i++) {
		printProduct(prod[i]);
		std::cout << std::endl;
	}
}

void readProductFromBinaryFile(std::ifstream& ifs, Product& product) {
	ifs.read((char*)&product, sizeof(Product));
}

void writeProductToBinaryFile(std::ofstream& ofs, const Product& product) {
	ofs.write((const char*)&product, sizeof(Product));
}

void setCathegory(int n, Product& prod) {
	switch (n)
	{
	case 0:prod.productCathegory = Cathegory::ELECTRONICS; break;
	case 1:prod.productCathegory = Cathegory::CLOTHING; break;
	case 2:prod.productCathegory = Cathegory::BOOKS; break;
	case 3:prod.productCathegory = Cathegory::FOOD; break;
	case 4:prod.productCathegory = Cathegory::BEAUTY; break;
	case 5:prod.productCathegory = Cathegory::OTHER; break;
	default:
		break;
	}
}

bool inputProduct(Product& prod) {

	std::cin >> prod.productName;
	if (!Validations::isStringValid(prod.productName)) {
		std::cerr << "Invalid product name input" << std::endl;
		return false;
	}

	std::cin >> prod.inStock;

	std::cin >> prod.productPrice;
	if (!Validations::isValidPrice(prod.productPrice)) {
		std::cerr << "Invalid price input" << std::endl;
		return false;
	}

	int cat = 0;
	std::cin >> cat;
	if (!Validations::isValidCathegory(cat)) {
		std::cerr << "Ivalid cathegory input" << std::endl;
		return false;
	}
	setCathegory(cat, prod);

	std::cin >> prod.productSupplier;
	if (!Validations::isStringValid(prod.productSupplier)) {
		std::cerr << "Invalid supplier name input" << std::endl;
		return false;
	}
	return true;
}

struct Storage {
	Product products[Constants::MAX_SIZE_PRODS];
	size_t currentSize = 0;
};

void readStorageFromBinaryFile(const char* fileName, Storage& stor) {
	if (!fileName) {
		std::cerr << "Error";
		return;
	}

	std::ifstream ifs(fileName, std::ios::binary);
	if (!ifs.is_open()) {
		std::cerr << "Error";
		return;
	}

	ifs.read((char*)&stor.currentSize, sizeof(stor.currentSize));

	for (size_t i = 0; i < stor.currentSize; i++) {
		readProductFromBinaryFile(ifs, stor.products[i]);
	}

	ifs.close();
}

void writeStorageToBinaryFile(const char* fileName, const Storage& stor) {
	if (!fileName) {
		std::cerr << "Error";
		return;
	}

	std::ofstream ofs(fileName, std::ios::binary);
	if (!ofs.is_open()) {
		std::cerr << "Error";
		return;
	}

	ofs.write((char*)&stor.currentSize, sizeof(stor.currentSize));

	for (size_t i = 0; i < stor.currentSize; i++) {
		writeProductToBinaryFile(ofs, stor.products[i]);
	}

	ofs.close();
}

bool isProductInStorage(const Storage& stor, const char* name) {
	for (size_t i = 0; i < stor.currentSize; i++) {
		if (strcmp(stor.products[i].productName, name) == 0) {
			return true;
		}
	}
	return false;
}

void writeStorageFromConsoleToBinaryFile(const char* fileName, Storage& stor) {
	if (!fileName) {
		std::cerr << "Error";
		return;
	}

	std::ofstream ofs(fileName, std::ios::binary);
	if (!ofs.is_open()) {
		std::cerr << "Error";
		return;
	}

	std::cin >> stor.currentSize;
	ofs.write((const char*)&stor.currentSize, sizeof(stor.currentSize));

	bool isValidInput = false;
	for (size_t i = 0; i < stor.currentSize; i++) {
		isValidInput = inputProduct(stor.products[i]);
		if (isValidInput && !isProductInStorage(stor, stor.products[i].productName)) {
			writeProductToBinaryFile(ofs, stor.products[i]);
		}
	}

	ofs.close();
}

void changeInStockVariable(Product& prod, int valueToChange) {
	prod.inStock = valueToChange;
}

void printStorageInfo(const Storage& stor) {
	std::cout << "Products in storage count: " << stor.currentSize << std::endl;
	printProducts(stor.products, stor.currentSize);
	std::cout << std::endl;
}

void printProductFromStorageByName(const Storage& stor, const char* name) {
	if (!name) {
		std::cerr << "Error";
		return;
	}

	for (size_t i = 0; i < stor.currentSize; i++) {
		if (strcmp(stor.products[i].productName, name) == 0) {
			printProduct(stor.products[i]);
			break;
		}
	}
}

size_t getCountOfProductsFromCathegory(const Storage& stor, Cathegory cat) {
	size_t count = 0;
	for (size_t i = 0; i < stor.currentSize; i++) {
		if ((int)stor.products[i].productCathegory == (int)cat) {
			count++;
		}
	}
	return count;
}

void writeProductsFromStorageToFileByCarthegory(const char* fileName,
												const Storage& stor,
												Cathegory cat) {
	if (!fileName) {
		std::cerr << "Error";
		return;
	}

	std::ofstream ofs(fileName, std::ios::binary);
	if (!ofs.is_open()) {
		std::cerr << "Error";
		return;
	}

	size_t countOfProductsToWrite = getCountOfProductsFromCathegory(stor, cat);

	ofs.write((const char*)&countOfProductsToWrite, sizeof(countOfProductsToWrite));

	for (size_t i = 0; i < stor.currentSize; i++) {
		if ((int)stor.products[i].productCathegory == (int)cat) {
			writeProductToBinaryFile(ofs, stor.products[i]);
		}
	}
}

int main() {
	Product prod1 = {
		"Name1", 3, 4.5, Cathegory::BEAUTY, "supl1"
	};
	Product prod2 = {
		"Name2", 3, 4.5, Cathegory::BEAUTY, "supl2"
	};
	Product prod3 = {
		"Name3", 3, 4.5, Cathegory::BEAUTY, "supl3"
	};
	Product prod4 = {
		"Name4", 3, 4.5, Cathegory::BEAUTY, "supl4"
	};

	Product prods[] = { prod1, prod2, prod3, prod4 };

	/*printProducts(prods, 4);

	std::ofstream ofs("file.txt", std::ios::binary);
	if (!ofs.is_open()) {
		std::cerr << "Error";
		return 0;
	}


	writeProductToBinaryFile(ofs, prod2);
	
	Product prod;

	ofs.close();

	std::ifstream ifs("file.txt", std::ios::binary);
	if (!ifs.is_open()) {
		std::cerr << "Error";
		return 0;
	}

	readProductFromBinaryFile(ifs, prod);

	std::cout << std::endl;
	printProduct(prod);

	ifs.close();*/

	Storage stor{
		{prod1, prod2, prod3, prod4}, 4
	};

	writeStorageToBinaryFile("stor.txt", stor);

	Storage stor1;

	readStorageFromBinaryFile("stor.txt", stor1);

	printProducts(stor1.products, 4);
	std::cout << stor1.currentSize;
}
