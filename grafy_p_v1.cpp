#include "pch.h"
#include <iostream>
using namespace std;

void funkcja(int vertX, int edgeY, int algorithm, GraphM_NO * testGraph);

void forestTest() {
	Forest* myF;
	myF = new Forest(4);

	myF->makeSet(0);
	myF->makeSet(1);
	myF->makeSet(2);

	cout << myF->findSet(2) << endl;

	myF->unionSets(0, 1);
	//cout << myF->findSet(9);
	cout << endl;
	system("pause");
	return;
}
int main()
{
	//forestTest();

	//menu section
	GraphM_NO *testGraph;
	testGraph = new GraphM_NO(0, 0);
	//cout << "bez bledu1\n";
	int userVert = 0;
	int userD = 0;
	int userChoice=999;
	while (userChoice != 0) {
		cout << "------------------------------------------------------\n";
		cout << "Ktory problem chcemy rozwiazywac?\n"
			<< "1. Problem MST\n"
			<< "2. Problem SP\n"
			<<"3. generuj rand 100\n"
			<<"4. Przeksztalc wyniki do excella\n"
			<< "0. Zakoncz\n"
			<< "Wybierz 0,1,2 : ";
		cin >> userChoice;
		switch (userChoice) {
		case 0:
			return 0;
		case 1:
			while (userChoice != 0) {
				//MST graf nieskierowany
				cout << "------------------------------------------------------\n";
				cout << "Problem MST\n";
				cout << "1. Wczytaj z pliku i wyswietl\n"
					<< "2.Wygeneruj graf losowo\n"
					<< "3.Wyswietl listowo i macierzowo\n"
					<< "4.Algorytm Prima i wyswietlenie wynikow\n"
					<< "6.Algorytm Kruskala i wyswietlenie wynikow\n"
					<< "0.Wroc do menu glownego\n";
				cin >> userChoice;
				cout << "------------------------------------------------------\n";
				switch (userChoice) {
				case 0:
					break;
				case 1:
					testGraph = new GraphM_NO(false);//bo graf nieskierowany isOiented
					testGraph->printStart();
					testGraph->printWithValuesList();
					break;
				case 2:
					cout << "Losowe generowanie grafu :\n"
						<< "Podaj liczbe wierzcholkow : ";
					cin >> userVert;
					cout << "Podaj gestosc grafu : ";
					cin >> userD;
					//graf niezorientowany bo jestesmy w sekcji MST
					testGraph->createRandom(userVert, userD, false);
					testGraph->printStart();
					testGraph->printWithValuesList();
					break;
				case 3:
					cout << "--------------Wyswietlam:-------------------------\n";
					testGraph->printStart();
					testGraph->printWithValuesList();
					break;
				case 4:
					algorithms::algorithm_PrimV2(testGraph,true);//true-should be printed
					algorithms::algorithm_Prim_List(testGraph,true);
					userChoice = 999;
					break;
				case 6:
					algorithms::algorithmKruskal(testGraph, true);
					algorithms::algorithmKruskalList(testGraph, true);
					userChoice = 999;
					break;
				}
				
			}
			userChoice = 999;
			break;

		case 2:
			while (userChoice != 0) {
				//Shortest path
				cout << "------------------------------------------------------\n";
				cout << "Problem Shortest path\n";
				cout << "1. Wczytaj z pliku i wyswietl\n"
					<< "2.Wygeneruj graf losowo\n"
					<< "3.Wyswietl listowo i macierzowo\n"
					<< "4.Algorytm Dijkstry i wyswietlenie wynikow\n"
					<< "6.Algorytm BelmanaForda i wyswietlenie wynikow\n"
					<< "0.Wroc do menu glownego\n";
				cin >> userChoice;
				cout << "------------------------------------------------------\n";
				switch (userChoice) {
				case 0:
					break;
				case 1:
					//testGraph = new GraphM_NO(true);//true bo graf skierowany
					testGraph = new GraphM_NO(true, 123);//uzywam innnego konstruktora
					testGraph->printStart();
					testGraph->printWithValuesList();
					break;
				case 2:
					cout << "Losowe generowanie grafu :\n"
						<< "Podaj liczbe wierzcholkow : ";
					cin >> userVert;
					cout << "Podaj gestosc grafu : ";
					cin >> userD;
					//graf niezorientowany bo jestesmy w sekcji SP
					testGraph->createRandom(userVert, userD, true);
					testGraph->printStart();
					testGraph->printWithValuesList();
					break;
				case 3:
					cout << "--------------Wyswietlam:-------------------------\n";
					testGraph->printStart();
					testGraph->printWithValuesList();
					break;
				case 4:
					algorithms::algorithm_Dijkstra(testGraph,true);
					algorithms::algorithm_Dijkstra_List(testGraph,true);
					break;

				case 6:
					algorithms::algorithmBelmanM(testGraph, true);
					algorithms::algorithmBelmanList(testGraph, true);
					break;
				}

				
			}
			userChoice = 990;
			break;
		case 3:
			//testy
			userChoice = 999;

			int vertXtab[5];
			vertXtab[0] = 10;
			vertXtab[1] = 25;
			vertXtab[2] = 50;
			vertXtab[3] = 75;
			vertXtab[4] = 100;

			int edgeYtab[4];
			edgeYtab[0] = 25;
			edgeYtab[1] = 50;
			edgeYtab[2] = 75;
			edgeYtab[3] = 99;

			//funkcja(10, 25, 1, testGraph);
			/*for (int i = 1; i < 9; i++) {
				for (int vnb=0; vnb < 5; vnb++) {
					for (int edg = 0; edg < 4; edg++) {
						funkcja(vertXtab[vnb], edgeYtab[edg], i, testGraph);
					}
				}
			}*/

			
			for (int vnb = 0; vnb < 5; vnb++) {
				for (int edg = 0; edg < 4; edg++) {
					funkcja(vertXtab[vnb], edgeYtab[edg], 7, testGraph);
				}
			}
			
			//funkcja(100, 50, 2, testGraph);
			userChoice = 999;
			break;
		case 4:
			algorithms::toExcel();
			userChoice = 999;
			break;
		}
			

	}
		

}

void binHeapTest() {
	BinaryHeap * myHeap;
	myHeap = new BinaryHeap();

	///////////////////////////////////////////////////////
	if (myHeap->isSizeZero()) {
		std::cout << "isSizeZero :true\n";
	}
	else {
		std::cout << "isSIzeZero: false\n";
	}
	if (myHeap->isSizeZeroV2()) {
		std::cout << "isSizeZero V2:true\n";
	}
	else {
		std::cout << "isSIzeZero V2: false\n";
	}
	cout << "size is :" << myHeap->getSize() << endl;
	cout << "CurrSize is :" << myHeap->getCurrSize() << endl;
	//////////////////////////////////////////////////////
	myHeap->append(0, 0, 0);
	if (myHeap->isSizeZero()) {
		std::cout << "isSizeZero :true\n";
	}
	else {
		std::cout << "isSIzeZero: false\n";
	}
	if (myHeap->isSizeZeroV2()) {
		std::cout << "isSizeZero V2:true\n";
	}
	else {
		std::cout << "isSIzeZero V2: false\n";
	}
	cout << "size is :" << myHeap->getSize() << endl;
	cout << "CurrSize is :" << myHeap->getCurrSize() << endl;
	//////////////////////////////////////////////////////
	myHeap->append(0, 0, 0);
	///////////////////////////////////////
	if (myHeap->isSizeZero()) {
		std::cout << "isSizeZero :true\n";
	}
	else {
		std::cout << "isSIzeZero: false\n";
	}
	if (myHeap->isSizeZeroV2()) {
		std::cout << "isSizeZero V2:true\n";
	}
	else {
		std::cout << "isSIzeZero V2: false\n";
	}
	cout << "size is :" << myHeap->getSize() << endl;
	cout << "CurrSize is :" << myHeap->getCurrSize() << endl;
	//////////////////////////////////////////////////////
	myHeap->pop();
	//////////////////////////////////////////////////////

	if (myHeap->isSizeZero()) {
		std::cout << "isSizeZero :true\n";
	}
	else {
		std::cout << "isSIzeZero: false\n";
	}
	if (myHeap->isSizeZeroV2()) {
		std::cout << "isSizeZero V2:true\n";
	}
	else {
		std::cout << "isSIzeZero V2: false\n";
	}
	cout << "size is :" << myHeap->getSize() << endl;
	cout << "CurrSize is :" << myHeap->getCurrSize() << endl;
	//////////////////////////////////////////////////////
	myHeap->pop();
	//////////////////////////////////////////////////////
	if (myHeap->isSizeZero()) {
		std::cout << "isSizeZero :true\n";
	}
	else {
		std::cout << "isSIzeZero: false\n";
	}
	if (myHeap->isSizeZeroV2()) {
		std::cout << "isSizeZero V2:true\n";
	}
	else {
		std::cout << "isSIzeZero V2: false\n";
	}
	cout << "size is :" << myHeap->getSize() << endl;
	cout << "CurrSize is :" << myHeap->getCurrSize() << endl;
	//////////////////////////////////////////////////////
}

void funkcja(int vertX, int edgeY, int algorithm, GraphM_NO * testGraph) {
	bool isMST = true;
	string beforeExcell="";
	if (algorithm > 4) {
		isMST = false;
	}
	if(algorithm!=1 && algorithm != 1 
		&& algorithm != 2 && algorithm != 3 
		&& algorithm != 4 && algorithm != 5 
		&& algorithm != 6 && algorithm != 7 && algorithm != 8) {
		cout << "wywalilo srogim bledem\n";
	}
	switch (algorithm) {
	case 1:
		beforeExcell.append("MST_");
		beforeExcell.append("Mac_");
		beforeExcell.append("Prim_");
		break;
	case 2:
		beforeExcell.append("MST_");
		beforeExcell.append("List_");
		beforeExcell.append("Prim_");
		break;
	case 3:
		beforeExcell.append("MST_");
		beforeExcell.append("Mac_");
		beforeExcell.append("Krus_");
		break;
	case 4:
		beforeExcell.append("MST_");
		beforeExcell.append("List_");
		beforeExcell.append("Krus_");
		break;
	case 5:
		beforeExcell.append("SP_");
		beforeExcell.append("Mac_");
		beforeExcell.append("Dijx_");
		break;
	case 6:
		beforeExcell.append("SP_");
		beforeExcell.append("List_");
		beforeExcell.append("Dijx_");
		break;
	case 7:
		beforeExcell.append("SP_");
		beforeExcell.append("Mac_");
		beforeExcell.append("Bel_");
		break;
	case 8:
		beforeExcell.append("SP_");
		beforeExcell.append("List_");
		beforeExcell.append("Bel_");
		break;
	}

	//beforeExcell.append("MST_");
	beforeExcell.append("v" + std::to_string(vertX));
	beforeExcell.append("d" + std::to_string(edgeY));
	beforeExcell.append(".txt");


	int userRandVert = vertX;
	int userEdgePercent = edgeY;
	for (int i = 0; i < 100; i++) {
		if (isMST) {
			testGraph->createRandom(userRandVert, userEdgePercent, false);
		}
		else {
			testGraph->createRandom(userRandVert, userEdgePercent, true);
		}
		//	testGraph->createRandom(userRandVert, userEdgePercent, true);	//skierowany , shortest path
		//testGraph->createRandom(userRandVert, userEdgePercent, false);	//nieskierowany, algorytm mst

		auto startTest = std::chrono::high_resolution_clock::now();

		//algorytm ktorego dlugosc trwania chce badac
	//	algorithms::algorithm_Dijkstra(testGraph, false);
	//	algorithms::algorithm_Dijkstra_List(testGraph, false);
		switch (algorithm) {
		case 1:
			algorithms::algorithm_PrimV2(testGraph, false);
			break;
		case 2:
			algorithms::algorithm_Prim_List(testGraph, false);
			break;
		case 3:
			algorithms::algorithmKruskal(testGraph, false);
			break;
		case 4:
			algorithms::algorithmKruskalList(testGraph, false);
			break;
		case 5:
			algorithms::algorithm_Dijkstra(testGraph, false);
			break;
		case 6:
			algorithms::algorithm_Dijkstra_List(testGraph, false);
			break;
		case 7:
			algorithms::algorithmBelmanM(testGraph, false);
			break;
		case 8:
			algorithms::algorithmBelmanList(testGraph, false);
			break;
		}

		auto endTest = std::chrono::high_resolution_clock::now();
		chrono::duration<double> diff = endTest - startTest;

		fstream wyniki;
		
		wyniki.open(beforeExcell, ios::out | ios::app);
		if (wyniki.good() == true) {
			wyniki << diff.count() << endl;
			wyniki.close();
		}
		
	}
	fstream wyniki;
	fstream wynikiCor;
	std::string  dataRow;
	wynikiCor.open("hereIs_"+beforeExcell, ios::out);
	wyniki.open( beforeExcell , ios::in);
	if (wynikiCor.good() && wyniki.good()) {
		for (int i = 0; i < 100; i++) {
			getline(wyniki, dataRow);
			int n = dataRow.length();
			char *chArray = &dataRow[0];
			for (int k = 0; chArray[k] != '\0'; k++) {
				if (chArray[k] == 'e') {
					chArray[k] = 'E';
				}
				if (chArray[k] == '.') {
					chArray[k] = ',';
				}
			}
			string str(chArray);
			wynikiCor << str << std::endl;
		}
		wyniki.close();
		wynikiCor.close();
	}
	//cout << beforeExcell;
	//------------------------------------------------
}


	/*GraphM_NO *testGraph;
	testGraph = new GraphM_NO();
	testGraph->printStart();
	system("pause");
    std::cout << "Hello World!\n"; */

	/*GraphL_NO *testGraphL;
	testGraphL = new GraphL_NO();
	testGraphL->print_start();
	cout << endl;
	cout << "---------------------------";
	cout << endl;
	testGraphL->printWithValues();
	string userInput;
	cout << "Podaj plik do ktorego chcesz zpaisac: ";
	cin >> userInput;
	testGraphL->saveToFile(userInput);
	system("pause");*/


	/*BinaryHeap* testBH;
	testBH = new BinaryHeap();
	testBH->createRand(20);
	testBH->display();
	testBH->display3();
	testBH = NULL;
	system("pause");*/

	//GraphM_NO *testGraph;
	//testGraph = new GraphM_NO(false);//isOriented?
	//testGraph->printStart();
	//testGraph->print_startList();
	////algorithms::algorithm_PrimV2(testGraph);
	//algorithms::algorithm_Dijkstra(testGraph, 0);
	//algorithms::algorithm_Dijkstra_List(testGraph, 0);
	////cout << "jestem za listowym\n";
	//system("pause");
	//testGraph = new GraphM_NO(true);//isOriented?
	//testGraph->printStart();
	//testGraph->print_startList();
	//algorithms::algorithm_Dijkstra(testGraph, 0);
	//algorithms::algorithm_Dijkstra_List(testGraph, 0);
	////algorithms::algorithm_PrimV2(testGraph);
	///*algorithms::algorithm_PrimV2(testGraph);
	//algorithms::algorithm_Dijkstra(testGraph, 1);*/

	////testGraph->createRandom(6, 80, false);
	////testGraph->printStart();
	////testGraph->print_startList();
	//system("pause");


