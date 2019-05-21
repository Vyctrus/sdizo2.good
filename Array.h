
#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Array
{

private:
	int* myArray;
	int size;
public:
	Array();
	~Array();
	void addHead(int addNumb);	//dodaj na poczatku //OK
	void addTail(int addNumb);	//dodaj na koncu //OK
	void addPos(int addNumb, int numbPos);	//dodanie na wybranej pozycji	//OK
	void removeHead();	//usun na poczatku //OK
	void removeTail();	//usun na koncu //OK
	void removePos(int numbPos);	//usun z pozycji	//OK

	int removePosV2(int numbPos);

	void append(int addNumb);
	static void loadFromFile(string fileName, Array * loadedArray);
	bool searchNumb(int numbWanted);//wyszukanie elementu //Bool zawiera, nie zawiera, nie zwraca adressu gdzie, nie zwraca ilosci: ile?
	int getNumb(int numbPos);	//pozyskanie elementu z pozycji	//chyba OK

	void display();	//wyswietl na ekran	//OK

	void createRand(int sizeOfArray);	//utworzenie randomowo wygenerowanej talbicy
	void testFile(string fileName, Array * loadedArray);

	int currentSizeIs();
};

