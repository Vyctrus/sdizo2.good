#include "pch.h"
#include "Array.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Array::Array()
{
	size = 0;
}


Array::~Array()
{
}

void Array::addHead(int addNumb)	//OK
{
	if (size == 0) {
		myArray = new int[1];	//utworzenie nowej tablicy, jesli jeszcze jej nie bylo
		size++;
		myArray[0] = addNumb;
		return;
	}
	//tablica zostala zainicjowana juz wczesniej
	size++;
	int *tempArray = new int[size];
	for (int i = 0; i < size - 1; i++) {	//kazda na pozycje o 1 wieksza
		tempArray[i + 1] = myArray[i];	//pierwsza zmiana t[1]=t[0], ostatnia  t[size-1]=t[size-2]
	}
	tempArray[0] = addNumb;
	delete[] myArray;
	myArray = tempArray;
	return;
}

void Array::addTail(int addNumb)	//OK
{
	if (size == 0) {
		myArray = new int[1];	//utworzenie nowej tablicy, jesli jeszcze jej nie bylo
		size++;
		myArray[0] = addNumb;
		return;
	}
	//tablica zostala zainicjowana juz wczesniej
	size++;
	int *tempArray = new int[size];
	for (int i = 0; i < size - 1; i++) {
		tempArray[i] = myArray[i];	//pierwsza zmiana t[0]=t[0], ostatnia  t[size-2]=t[size-2]
	}
	tempArray[size - 1] = addNumb;
	delete[] myArray;
	myArray = tempArray;
	return;
}

void Array::addPos(int addNumb, int numbPos)
{
	if (numbPos > size || numbPos < 0) {
		return;
	}
	if (numbPos == size) {
		addTail(addNumb);
		return;
	}
	if (numbPos == 0) {
		addHead(addNumb);
		return;
	}
	//tablica zostala zainicjowana juz wczesniej
	size++;
	int *tempArray = new int[size];
	for (int i = 0; i < numbPos; i++) {	//przepisz tablice az do wskazanego indeksu
		tempArray[i] = myArray[i];	//pierwsza zmiana t[0]=t[0], ostatnia  t[size-2]=t[size-2]
	}
	tempArray[numbPos] = addNumb;	//we wskazanym miejscu wstaw wartosc
	for (int i = numbPos + 1; i < size; i++) {	//przepisz reszte tablicy
		tempArray[i] = myArray[i - 1];	// t[size-1]=t[size-1-1]
	}
	delete[] myArray;
	myArray = tempArray;
	return;
}

void Array::removeHead()
{
	if (size == 0) {
		return;
	}
	size--;
	int *tempArray = new int[size];	//utworzenie mniejszej tablicy
	for (int i = 0; i < size; i++) {	//kazda na pozycje o 1 wieksza
		tempArray[i] = myArray[i + 1];	//pierwsza zmiana t[0]=t[1], ostatnia t[size-1]=t[size] -dozwolone bo byla tablica wieksza
	}
	delete[] myArray;
	myArray = tempArray;
	return;
}

void Array::removeTail()
{
	if (size == 0) {
		return;
	}
	size--;
	int *tempArray = new int[size];	//utworzenie mniejszej tablicy
	for (int i = 0; i < size; i++) {	//kazda na pozycje o 1 wieksza
		tempArray[i] = myArray[i];	//pierwsza zmiana t[0]=t[0], o ostatnim elemencie z myArray "zapominamy"
	}
	delete[] myArray;
	myArray = tempArray;
	return;
}

void Array::removePos(int numbPos)
{
	if (numbPos >= size || numbPos < 0) {
		return;
	}
	if (numbPos == size - 1) {
		removeTail();
		return;
	}
	if (numbPos == 0) {
		removeHead();
		return;
	}
	size--;
	int *tempArray = new int[size];	//utworzenie mniejszej tablicy
	for (int i = 0; i < numbPos; i++) {	//przpisuje tablice do wskazanego indeksu
		tempArray[i] = myArray[i];
	}
	for (int i = numbPos; i < size; i++) {
		tempArray[i] = myArray[i + 1];	//nadal bezpiecznie bo myArray jest o 1 wieksza 
	}
	delete[] myArray;
	myArray = tempArray;
	return;
}

int Array::removePosV2(int numbPos)
{
	if (numbPos >= size || numbPos < 0) {
		return 0;
	}
	if (numbPos == size - 1) {
		int temp = getNumb(size - 1);
		removeTail();
		return temp;
	}
	if (numbPos == 0) {
		int temp = getNumb(0);
		removeHead();
		return temp;
	}
	size--;
	int *tempArray = new int[size];	//utworzenie mniejszej tablicy
	for (int i = 0; i < numbPos; i++) {	//przpisuje tablice do wskazanego indeksu
		tempArray[i] = myArray[i];
	}
	int temp = myArray[numbPos];
	for (int i = numbPos; i < size; i++) {
		tempArray[i] = myArray[i + 1];	//nadal bezpiecznie bo myArray jest o 1 wieksza 
	}
	delete[] myArray;
	myArray = tempArray;
	return temp;
}

void Array::append(int addNumb)
{
	addTail(addNumb);
}

void Array::loadFromFile(string fileName, Array  * loadedArray)
{
	std::fstream file;
	std::string  dataRow;
	file.open(fileName, std::ios::in);	//fileName = data_in.txt
	if (file.good() == true) {
		getline(file, dataRow);
		std::cout << "Poprawny odczyt z pliku\n";
		int numberOfData = std::stoi(dataRow);
		for (int i = 0; i < numberOfData; i++) {
			getline(file, dataRow);
			loadedArray->append(std::stoi(dataRow));
		}
		file.close();
		return;//std::fstream &file
	}
	else {
		std::cout << "Nieudany odczyt z pliku\n";
	}
	return;
}


bool Array::searchNumb(int numbWanted)
{
	for (int i = 0; i < size; i++) {
		if (numbWanted == myArray[i]) {
			//std::cout << numbWanted << " -liczba jest w strukturze\n";
			return true;
		}
	}
	//std::cout << numbWanted << " -liczby nie ma w strukturze\n";
	return false;
}

int Array::getNumb(int numbPos)
{

	return myArray[numbPos];
}

void Array::display()
{
	for (int i = 0; i < size; i++) {
		std::cout << myArray[i] << " ";
	}
	std::cout << std::endl;
}

void Array::createRand(int sizeOfArray)	//mozna dodac paramter maksymalna liczba
{
	for (int i = 0; i < sizeOfArray; i++) {
		addHead(rand());	//tutaj mozna dac rand() % maksymalna liczba
	}
}

void Array::testFile(string fileName, Array  * loadedArray)
{
	std::fstream file;
	std::string  dataRow;
	file.open(fileName, std::ios::in);	//fileName = data_in.txt
	if (file.good() == true) {
		getline(file, dataRow);
		//std::cout << "Poprawny odczyt z pliku\n";
		int numberOfData = std::stoi(dataRow);
		for (int i = 0; i < numberOfData; i++) {
			getline(file, dataRow);
			//loadedArray->append(std::stoi(dataRow));
			loadedArray->addHead(std::stoi(dataRow));
		}
		file.close();
		return;//std::fstream &file
	}
	else {
		std::cout << "Nieudany odczyt z pliku\n";
	}
	return;
}

int Array::currentSizeIs()
{
	return size;
}

