#include "pch.h"
#include "GraphM_NO.h"
using namespace std;


void GraphM_NO::addEdge(int vertFrom, int vertTo, int edgeValue, bool isOriented)
{
	if (isOriented==false) {
		matrix[vertFrom][vertTo] = edgeValue;
		matrix[vertTo][vertFrom] = edgeValue;		//bo niezorientowany
		//edgesNum_check++;
	}
	else {
		matrix[vertFrom][vertTo] = edgeValue;
	}
}

void GraphM_NO::createRandom(int numberOfVerticles, int percentOfEdges, bool isOriented)
{
	int MAX_EDGE_VALUE = 9;
	int verts = numberOfVerticles;
	int edgesMax = verts * (verts - 1) / 2;
	int edges = (((verts * (verts - 1))/2)* (percentOfEdges)) / 100;// not oriented
	if (isOriented) {
		edges = (((verts * (verts - 1)))* (percentOfEdges)) / 100;// oriented
	}
	//cout << "czy tu jest 12? :  " << edges << endl;	
	int edgesAdded = 0;
	GraphM_NO* myRandGraph;
	myRandGraph = new GraphM_NO(numberOfVerticles, edges);
	DoubleConectedList * randList;
	randList = new DoubleConectedList();
	if (verts == 0) {
		cout << "Graf nie posiada wierzcholkow\n";
		return;
	}
	for (int i = 0; i < verts; i++) {
		randList->append(i);
	}
	srand(time(NULL));
	int startRand = rand() % verts;
	if (edges == 0) {
		cout << "Graf nie posiada krawedzi\n";
		return;
	}
	if (edges < verts) {
		cout << "Nie mozna rozpiac drzewa MST, zbyt mala gestosc \n";
		return;
	}

	//blok kodu MST
	Array* conected;
	Array* notConected;
	conected = new Array();
	notConected = new Array();
	for (int i = 0; i < verts; i++) {
		notConected->append(i);
	}

	while (notConected->currentSizeIs() > 0) {
		int currXYZ = notConected->removePosV2(rand() %(notConected->currentSizeIs()));
		if (conected->currentSizeIs() == 0) {
			//nie pobieraj rodzica
			conected->append(currXYZ);
		}
		else {
			int parent = conected->getNumb(rand() % (conected->currentSizeIs()));
			conected->append(currXYZ);
			int tempValue = 1 + rand() % (MAX_EDGE_VALUE - 1);
			myRandGraph->addEdge(parent, currXYZ, tempValue, isOriented);//false
			myRandGraph->addEdgeList(parent, currXYZ, tempValue, isOriented);
			edgesAdded++;
		}
	}
	//cout << "zrobiono mst, edgesAdded: "<<edgesAdded<<"\n";//zwraca ile krawedzi jest w mst
	//mam juz MST

	DoubleConectedList * posibleEdges;
	posibleEdges = new DoubleConectedList();

	for (int i = 0; i < verts; i++) {
		for (int j = 0; j < verts; j++) {
			if ((myRandGraph->whatIsEdge(i, j) == 0)&& i!=j) {		//i!=j zeby nie bylo A-A
				if (isOriented) {
					//dodaj
					posibleEdges->addTailGraph(i, j);
				}
				else {
					if (myRandGraph->whatIsEdge(j, i) != 0 ||posibleEdges->searchNumbGraphV2(i,j) || posibleEdges->searchNumbGraphV2(j, i)) {
						//nie dodawaj
					}
					else {
						posibleEdges->addTailGraph(i, j);
						//dodaj
					}
				}
			}
		}
	}
	//w posibleEdges mam wszystkie krawedzie ktore mog¹ zostac dodane
	//cout << "Edges :" << edges << endl;
	//cout << "edgesAdded: " << edgesAdded << endl;
	//cout << "posibleEdgesSize : " << posibleEdges->getSize() << endl;
	//cout << "edgesMax : " << edgesMax << endl;
	//posibleEdges->displayWithEdgeValue();
	//
	while (edgesAdded < edges && posibleEdges->getSize() != 0) {
		if (posibleEdges->getSize() == 0) {
			cout << "ostrzezenie, za duza gestosc!\n";
		}

		int randPosition = rand()% posibleEdges->getSize();

		int tempFrom = posibleEdges->getNumb(randPosition);			//A				A--->B
		int tempTo = posibleEdges->getNumbValue(randPosition);		//B
		posibleEdges->removePos(randPosition);
		
		int tempValue = 1 + rand() % (MAX_EDGE_VALUE - 1);
		myRandGraph->addEdge(tempFrom, tempTo, tempValue, isOriented);	//minimum 1 jest istotne
		myRandGraph->addEdgeList(tempFrom, tempTo, tempValue, isOriented);
		edgesAdded++;
	}
	//

	//cout << "Randomowo wygenerowano graf\n";
	//cout << "Liczba edgesAdded : " << edgesAdded<<endl;

	vertsNum = verts;
	edgesNum = edges;
	matrix = myRandGraph->matrix;

	vertsNumList = verts;
	edgesNumList = edges;
	myList = myRandGraph->myList;

	srand(time(NULL));
	if (vertsNum != 0) {
		vertMST = rand() % vertsNum;
	}

}

int GraphM_NO::whatIsEdge(int i, int j)
{
	return matrix[i][j];
	//return 0;
}

GraphM_NO::GraphM_NO(int verts, int edges)// tworzy pusty graf zawierajacy potrzebna liczbe miejsc, zainicjowany z "0" //13803
{
	
	vertsNum = verts;
	edgesNum = edges;
	matrix = new int *[verts];
	/*srand(time(NULL));
	if (vertsNum != 0) {
		vertMST = rand() % vertsNum;
	}*/
	
	for (int i = 0; i < verts; i++) {
		matrix[i] = new int[verts];	//wiersze
	}
	for (int i = 0; i < verts; i++) {
		for (int j = 0; j < verts; j++) {
			matrix[i][j] = 0;
		}
	}

	//listowa
	vertsNumList = verts;
	edgesNumList = edges;
	myList = new DoubleConectedList *[verts];
	for (int i = 0; i < verts; i++) {
		myList[i] = NULL;// zamiast zer wypelniamy ja NULL'ami "pustymi listami"
	}	
}

void GraphM_NO::printStart()
{
	cout << "  ";
	for (int i = 0; i < vertsNum; i++) {
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < vertsNum;i++) {
		cout << i << " ";
		for (int j = 0; j < vertsNum; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	cout << endl;
	//std::cout << vertsNum << " " << edgesNum;
}

void GraphM_NO::print_startList()//CZESC reprezentacji listowej
{
	for (int i = 0; i < vertsNum; i++) {
		cout << i << "  ";
		if (myList[i] != NULL) {
			myList[i]->display();
		}
		else {
			cout << endl;
		}
	}
	cout << endl;
}

void GraphM_NO::printWithValuesList()//czesc reprezentacji listowej
{
	for (int i = 0; i < vertsNum; i++) {
		cout << i << "  ";
		if (myList[i] != NULL) {
			myList[i]->displayWithEdgeValue();
		}
		else {
			cout << endl;
		}
	}
	cout << endl;
}

void GraphM_NO::saveToFileList(string fileName)//reprezentacja listowa
{
	fstream wyniki;
	wyniki.open(fileName, ios::out);	//  | ios::app
	if (wyniki.good() == true) {
		wyniki << edgesNum << " " << vertsNum << endl;
		for (int i = 0; i < vertsNum; i++) {
			if (myList[i] != NULL) {
				//int j = 0;
				for (int j = 0; myList[i]->getNumb(j) != NULL; j++) {		//hasnext()?
					if (i <= myList[i]->getNumb(j)) {
						wyniki << i << " " << myList[i]->getNumb(j) << " " << myList[i]->getNumbValue(j) << endl;
					}
				}
			}
		}
		wyniki.close();
	}
}

void GraphM_NO::addEdgeList(int vertFrom, int vertTo, int value, bool isOriented)//13803chyba
{
	DoubleConectedList * list_h1;
	if (myList[vertFrom] == NULL) {
		//jesli wczesniej nie bylo tam listy
		list_h1 = new DoubleConectedList();
		list_h1->addTailGraph(vertTo, value);
		myList[vertFrom] = list_h1;

		if (!isOriented) {//Not oriented
			if (myList[vertTo] == NULL) {
				list_h1 = new DoubleConectedList();	
				list_h1->addTailGraph(vertFrom, value);
				myList[vertTo] = list_h1;
			}
			else {
				if (!myList[vertTo]->searchNumb(vertFrom)) {//jesli nieprawda: nie znajdziesz tej po drugiej stornie wartosci "z"
					myList[vertTo]->addTailGraph(vertFrom, value);//to dostaw j¹
				}
			}
		}

	}
	else {
		if (!myList[vertFrom]->searchNumb(vertTo)) {
			myList[vertFrom]->addTailGraph(vertTo, value);		//dodac sprawdzanie czy w liscie juz jest ta krawedz, nic nie dodawc jesli oriented
			if (!isOriented) {
				addEdgeList(vertTo, vertFrom, value, isOriented);
			}
		}//else - jesli sie znajduje juz tam, to nic nie rob

	}

}



int GraphM_NO::whatIsEdgeList(int i, int j)
{
	if (myList[i] != NULL) {
		return myList[i]->searchNumbGetValue(j);
	}
	return 0;
}



GraphM_NO::GraphM_NO(bool isOriented)
{
	int edgesNum_check = 0;
	std::string fileName;
	std::cout << "Podaj filename : ";
	std::cin >> fileName;

	std::fstream file;
	file.open(fileName, std::ios::in);	//fileName = data_in.txt
	if (file.good() == true) {

		int a;
		if (file >> a)
		{
			//printf("%d ", a);
		}
		edgesNum = a;
		edgesNumList = a;
		if (file >> a)
		{
			//printf("%d ", a);
		}
		vertsNum = a;
		vertsNumList = a;

		//postac macierzowa
		int verts = vertsNum;
		int edges = edgesNum;
		matrix = new int *[verts];
		for (int i = 0; i < verts; i++) {
			matrix[i] = new int[verts];	//wiersze
		}
		for (int i = 0; i < verts; i++) {
			for (int j = 0; j < verts; j++) {
				matrix[i][j] = 0;
			}
		}
		//postac listowa
		int vertsL = vertsNumList;
		int edgesL = edgesNumList;
		myList = new DoubleConectedList *[verts];
		for (int i = 0; i < verts; i++) {
			myList[i] = NULL;// zamiast zer wypelniamy ja NULL'ami "pustymi listami"
		}


		//-----------------odczyt krawedzi
		int w_start;
		int w_end;
		int e_value;//waga
		while (file >> a) {
			w_start = a;
			if (file >> a) {
				//printf("%d ", a);
				w_end = a;
			}
			else {
				cout << "nieoczekiwany blad!\n";
			}

			if (file >> a) {
				e_value = a;
			}
			else {
				cout << "nieoczekiwany blad!\n";
			}

			if (w_start < vertsNum && w_end < vertsNum) {//vertsNum==vertsNumList
				//matrix[w_start][w_end] = e_value;
				//matrix[w_end][w_start] = e_value;	
				addEdge(w_start, w_end, e_value, isOriented);	//dodaj do reprezentacji macierzowej
				addEdgeList(w_start, w_end, e_value, isOriented);	//dodaj do reprezentacji listowej
				edgesNum_check++;
			}
			else {
				cout << "bledny wierzcholek\n";
			}

		}

		file.close();

	}
	else {
		std::cout << "Nieudany odczyt z pliku\n";
	}
	//std::cout << vertsNum << " " << edgesNum;
}

GraphM_NO::GraphM_NO(bool isOriented, int nothing)//uzywany by odczytac wierzcholek w przypadku odczytu pliku typu "sp.txt"
{
	//vertMST = 0;
	int edgesNum_check = 0;
	std::string fileName;
	std::cout << "Podaj filename : ";
	std::cin >> fileName;

	std::fstream file;
	file.open(fileName, std::ios::in);	//fileName = data_in.txt
	if (file.good() == true) {

		int a;
		if (file >> a)
		{
			//printf("%d ", a);
		}
		edgesNum = a;
		edgesNumList = a;
		if (file >> a)
		{
			//printf("%d ", a);
		}
		vertsNum = a;
		vertsNumList = a;
		////////////////////////////////////
		if (file >> a)
		{
			//printf("%d ", a);
		}
		vertMST = a;
		//---------------------------------


		//postac macierzowa
		int verts = vertsNum;
		int edges = edgesNum;
		matrix = new int *[verts];
		for (int i = 0; i < verts; i++) {
			matrix[i] = new int[verts];	//wiersze
		}
		for (int i = 0; i < verts; i++) {
			for (int j = 0; j < verts; j++) {
				matrix[i][j] = 0;
			}
		}
		//postac listowa
		int vertsL = vertsNumList;
		int edgesL = edgesNumList;
		myList = new DoubleConectedList *[verts];
		for (int i = 0; i < verts; i++) {
			myList[i] = NULL;// zamiast zer wypelniamy ja NULL'ami "pustymi listami"
		}


		//-----------------odczyt krawedzi
		int w_start;
		int w_end;
		int e_value;//waga
		while (file >> a) {
			//printf("\n%d ", a);
			w_start = a;
			//cout << "w_start : " << w_start << endl;
			if (file >> a) {
				//printf("%d ", a);
				w_end = a;
			}
			else {
				cout << "nieoczekiwany blad!\n";
			}
			//cout << "w_end wynosi : " << w_end << endl;

			if (file >> a) {
				//printf("%d ", a);
				e_value = a;
			}
			else {
				cout << "nieoczekiwany blad!\n";
			}
			//cout << "My little values: " << w_start << " " << w_end << " " << e_value;

			if (w_start < vertsNum && w_end < vertsNum) {//vertsNum==vertsNumList
				//matrix[w_start][w_end] = e_value;
				//matrix[w_end][w_start] = e_value;	
				addEdge(w_start, w_end, e_value, isOriented);	//dodaj do reprezentacji macierzowej
				addEdgeList(w_start, w_end, e_value, isOriented);	//dodaj do reprezentacji listowej
				edgesNum_check++;
			}
			else {
				cout << w_start << endl;
				cout << w_end << endl;
				cout << vertsNum << endl;
				
				cout << "bledny wierzcholek\n";
			}

		}

		file.close();

	}
	else {
		std::cout << "Nieudany odczyt z pliku\n";
	}
	//std::cout << vertsNum << " " << edgesNum;
}




GraphM_NO::~GraphM_NO()
{
	delete [] matrix;
	delete myList;
}

int GraphM_NO::getVertM()
{
	return vertsNum;
}

int GraphM_NO::getVertL()
{
	return vertsNumList;
}

void GraphM_NO::setVertL(int vertNumber)
{
	vertsNumList = vertNumber;
}

void GraphM_NO::setVertM(int vertNumber)
{
	vertsNum = vertNumber;
}

int GraphM_NO::getEdgesM()
{
	return edgesNum;
}

int GraphM_NO::getEdgesL()
{
	return edgesNumList;
}

void GraphM_NO::setEdgesM(int number)
{
	edgesNum = number;
}

void GraphM_NO::setEdgesL(int number)
{
	edgesNumList = number;
}

int GraphM_NO::getVertMST()
{
	return vertMST;
}
