#include "pch.h"
#include "algorithms.h"
using namespace std;

algorithms::algorithms()
{
}


algorithms::~algorithms()
{
}



void algorithms::algorithm_PrimV2(GraphM_NO * myGraph, bool shouldBePrinted)
{
	GraphM_NO * answerGraph;
	answerGraph = new GraphM_NO(myGraph->getVertM(),0);


	if (shouldBePrinted) {
		cout << "Algorytm PrimV2 zaczyna dzialanie\n";
	}
	int verts = myGraph->getVertM();//myGraph->vertsNum;
	int edges = myGraph->getEdgesM();//myGraph->edgesNum;
	if (verts == 1) {
		cout << "Graf ma tylko jeden wierzcholek\n";
		cout << "Algorytm PrimV2 konczy dzialanie\n";
		return;
	}
	if (verts == 0) {
		cout << "Graf nie ma wierzcholkow wierzcholek\n";
		cout << "Algorytm PrimV2 konczy dzialanie\n";
		return;
	}

	int answerSum = 0;

	bool* usedVerticles;
	usedVerticles = new bool[verts];
	for (int i = 0; i < verts; i++) {
		usedVerticles[i] = false;
	}


	//cout << "Algorytm PrimV2 punkt1 dzialanie\n";
	BinaryHeap * posiblyVerts;
	posiblyVerts = new BinaryHeap();

	usedVerticles[0] = true;
	int foundVerts = 0;
	posiblyVerts->append((-1) * 0, 0, 0);//pierwsyz do rozwazania
	while (!posiblyVerts->isSizeZero() && foundVerts != verts) {
		//posiblyVerts->display3();
		graphData tempX = posiblyVerts->pop();
		//posiblyVerts->display3();
		int temp_val = (-1)*tempX.value;
		int temp_from = tempX.verticleFrom;
		int temp_to = tempX.verticleNumb;

		if (usedVerticles[temp_to] == true && temp_to!=0) {
			//jesli juz rozpatrywalem ten wierzcholek- moge do niego dojsc w sposob szybszy
			continue;
		}
		else {
			usedVerticles[temp_to] = true;
			foundVerts += 1;
			answerSum += temp_val;
			if (temp_to != 0) {
				if (shouldBePrinted) {
					//cout << "(" << tempX.verticleFrom << ")->" << "(" << tempX.verticleNumb << ")"
					//	<< "value(" << (-1)*tempX.value << ") AnswerSum: "
					//	<< answerSum << "\n";//skad dokad, jaka wartosc
				}
				answerGraph->addEdge(tempX.verticleFrom, tempX.verticleNumb, (-1)*tempX.value,false);
				answerGraph->addEdgeList(tempX.verticleFrom, tempX.verticleNumb, (-1)*tempX.value, false);
			}
			
			//answerSum += temp_val;
			for (int i = 0; i < verts; i++) {
				int tempEdgeVal = myGraph->whatIsEdge(temp_to, i);
				if (tempEdgeVal != 0 ) {
					//dodawaj wszystko do czeo moge dojsc z obecnego drzewa
					//cout << "what is edge: " << myGraph->whatIsEdge(temp_from, i) << endl;
					if (usedVerticles[i] != true) {
						posiblyVerts->append((-1)*tempEdgeVal, i, temp_to);//##### wartosc,dokad,skad
						//tempto jest chwilowo wartoscia z ktorej bierzemy kolejne odnogi
					}
				}
			}
		
		}

	}

	if (shouldBePrinted) {
		cout << "Macierzowa\n";
		answerGraph->printStart();
		cout << "Listowa\n";
		answerGraph->printWithValuesList();
		cout << "Sumaryczna wartoœæ : " << answerSum << endl;
		cout << "Algorytm PrimV2 konczy dzialanie\n";
		cout << endl;
	}
	

}

void algorithms::algorithm_Prim_List(GraphM_NO * myGraph, bool shouldBePrinted)
{
	GraphM_NO * answerGraph;
	answerGraph = new GraphM_NO(myGraph->getVertL(), 0);


	if (shouldBePrinted) {
		cout << "Algorytm Prim_List zaczyna dzialanie\n";
	}
	
	int verts = myGraph->getVertL(); //myGraph->vertsNumList;
	int edges = myGraph->getEdgesL();//myGraph->edgesNumList;
	//int **matrixData = myGraph->matrix;
	//DoubleConectedList **currList = myGraph->myList;

	if (verts == 1) {
		cout << "Graf ma tylko jeden wierzcholek\n";
		cout << "Algorytm Prim_List konczy dzialanie\n";
		return;
	}
	if (verts == 0) {
		cout << "Graf nie ma wierzcholkow wierzcholek\n";
		cout << "Algorytm Prim_List konczy dzialanie\n";
		return;
	}
	
	int answerSum = 0;
	bool* usedVerticles;
	usedVerticles = new bool[verts];

	for (int i = 0; i < verts; i++) {
		usedVerticles[i] = false;
	}

	BinaryHeap * posiblyVerts;
	posiblyVerts = new BinaryHeap();

	usedVerticles[0] = true;
	int foundVerts = 0;//0


	posiblyVerts->append((-1) * 0, 0, 0);//pierwszy do rozwazania

	while (!posiblyVerts->isSizeZero() && foundVerts != verts) {
		//posiblyVerts->display3();
		graphData tempX = posiblyVerts->pop();
		//posiblyVerts->display3();
		int temp_val = (-1)*tempX.value;
		int temp_from = tempX.verticleFrom;
		int temp_to = tempX.verticleNumb;

		if (usedVerticles[temp_to] == true && temp_to != 0) {
			//jesli juz rozpatrywalem ten wierzcholek- moge do niego dojsc w sposob szybszy
			continue;
		}
		else {
			usedVerticles[temp_to] = true;
			foundVerts += 1;
			answerSum += temp_val;
			if (!temp_to == 0) {
				if (shouldBePrinted) {
					//cout << "(" << tempX.verticleFrom << ")->" << "(" << tempX.verticleNumb << ")"
					//	<< "value(" << (-1)*tempX.value << ") AnswerSum: "
					//	<< answerSum << "\n";//skad dokad, jaka wartosc
				}
				answerGraph->addEdge(tempX.verticleFrom, tempX.verticleNumb, (-1)*tempX.value, false);
				answerGraph->addEdgeList(tempX.verticleFrom, tempX.verticleNumb, (-1)*tempX.value, false);
			}
			
			//answerSum += temp_val;
			for (int i = 0; i < verts; i++) {
				int tempEdgeVal = myGraph->whatIsEdgeList(temp_to, i);
				if (tempEdgeVal != 0) {
					//dodawaj wszystko do czeo moge dojsc z obecnego drzewa
					if (usedVerticles[i] != true) {
						posiblyVerts->append((-1)*tempEdgeVal, i, temp_to);//##### wartosc,dokad,skad
						//tempto jest chwilowo wartoscia z ktorej bierzemy kolejne odnogi
					}
				}
			}

		}

	}

	if (shouldBePrinted) {
		cout << "Macierzowa\n";
		answerGraph->printStart();
		cout << "Listowa\n";
		answerGraph->printWithValuesList();
		cout << "Sumaryczna wartoœæ : " << answerSum << endl;
		cout << "Algorytm Prim_LIST konczy dzialanie\n";
		cout << endl;
	}
	
}

void algorithms::algorithm_Dijkstra_List(GraphM_NO * myGraph, bool shouldBePrinted)
{
	int verticleStart = myGraph->getVertMST();
	if (shouldBePrinted) {
		cout << "Algorytm DijkstraLIST zaczyna dzialanie\n";
	}
	
	int verts = myGraph->getVertL();//myGraph->vertsNumList;
	int edges = myGraph->getEdgesL();//myGraph->edgesNumList;
	//int **matrixData = myGraph->matrix;
	if (verts == 1) {
		cout << "Graf ma tylko jeden wierzcholek\n";
		cout << "Algorytm DijkstraLIST konczy dzialanie\n";
		return;
	}
	if (verts == 0) {
		cout << "Graf nie ma wierzcholkow wierzcholek\n";
		cout << "Algorytm DijkstraLIST konczy dzialanie\n";
		return;
	}



	bool * usedFromQ;
	usedFromQ = new bool[verts];
	for (int i = 0; i < verts; i++) {
		usedFromQ[i] = false;
	}

	int infinity = 9999;//przeniesc definicje do *.h
	int * valueOfPaths;
	valueOfPaths = new int[verts];
	for (int i = 0; i < verts; i++) {
		valueOfPaths[i] = infinity;
	}

	int *previousFrom;
	previousFrom = new int[verts];
	for (int i = 0; i < verts; i++) {
		previousFrom[i] = infinity;
		if (i == verticleStart) {
			previousFrom[i] = i;
		}
	}


	int firstVert = verticleStart;
	valueOfPaths[firstVert] = 0;
	usedFromQ[firstVert] = true;

	BinaryHeap * qHeap;
	qHeap = new BinaryHeap();			//kolejka priorytetowa


	for (int i = 0; i < verts; i++) {
		if (i == firstVert) {
			qHeap->append(0, i, 0);
		}
		else {
			qHeap->append((-1)*infinity, i, 0);//kopiec est maksymalny wiec dla ulatwienia tylko mnoze przez (-1)
		}
	}

	
	bool* usedV2;
	usedV2 = new bool[verts];
	for (int i = 0; i < verts; i++) {
		usedV2[i] = false;
	}
	////////////
	while (!qHeap->isSizeZero()) {//qHeap is not null
		graphData tempX = qHeap->pop();
		if (usedV2[tempX.verticleNumb] == true) {
			//juz to badalem, wyciagnij to i nic nie rob z tym, potrzebne ze wzgeldu na nadmiar danych w kopcu
			continue;
		}
		//tempX.verticleNumb; ---wierzcholek z kotrego wyciagmy
		int father = tempX.verticleNumb;
		for (int i = 0; i < verts; i++) {		//chce wyznaczyc sasiadow  father'a
			int tempEdgeVal = myGraph->whatIsEdgeList(father, i);
			if (/*matrixData[father][i]*/tempEdgeVal != 0) {
				if (usedFromQ[i] == false) {//jesli uzyty juz zostal to go pomin(jesli zostaly dla niego juz rozpatrzone odnogi)
					//posiblyVerts->append((-1)*(matrixData[father][i]), i, father);
					//(nie)wkladam do kopca z ujemna wartoscia aby korzen(max) wartosc,do_gdzie, from_gdzie

					if ((valueOfPaths[father] + (/*matrixData[father][i]*/tempEdgeVal)) < valueOfPaths[i]) {
						valueOfPaths[i] = (valueOfPaths[father] + (tempEdgeVal));
						qHeap->append((-1)*valueOfPaths[i], i, father);
						previousFrom[i] = father;
					}

				}
			}
		}
		usedFromQ[father] = true;
		usedV2[father] = true;


	}
	///////////

	if (shouldBePrinted) {
		for (int i = 0; i < verts; i++) {
			int j = i;
			cout << "(" << i << ")";
			while (previousFrom[j] != firstVert) {
				if (previousFrom[j] == infinity) {
					break;
				}
				cout << "<-(" << previousFrom[j] << ")";
				j = previousFrom[j];
			}
			cout << "<-(" << firstVert << ")   ";

			/*for (int j = 0; j < verts; j++) {
				cout << previousFrom[j]<<" ";
			}*/
			cout << "do punktu(" << i << ") ";
			if (valueOfPaths[i] != infinity) {
				cout << valueOfPaths[i];
			}
			else {
				cout << "Brak polaczenia!";
			}

			cout << endl;
		}
		cout << "Algorytm DijkstraLIST konczy dzialanie\n";
		cout << endl;
	}
}

void algorithms::algorithmKruskal(GraphM_NO * myGraph, bool shouldBePrinted)
{
	GraphM_NO * answerGraph;
	answerGraph = new GraphM_NO(myGraph->getVertM(), 0);

	int answerSum = 0;
	int verticleStart = myGraph->getVertMST();
	if (shouldBePrinted) {
		cout << "Algorytm KruskalM zaczyna dzialanie\n";
	}

	int verts = myGraph->getVertM();//myGraph->vertsNum;
	int edges = myGraph->getEdgesM();//myGraph->edgesNum;
	//int **matrixData = myGraph->matrix;
	if (verts == 1) {
		cout << "Graf ma tylko jeden wierzcholek\n";
		cout << "Algorytm KruskalM konczy dzialanie\n";
		return;
	}
	if (verts == 0) {
		cout << "Graf nie ma wierzcholkow wierzcholek\n";
		cout << "Algorytm KruskalM konczy dzialanie\n";
		return;
	}

	//Utwórz las L z wierzcho³ków oryginalnego grafu – 
	//ka¿dy wierzcho³ek jest na pocz¹tku osobnym drzewem.
	Forest* bigForest;
	bigForest = new Forest(verts);
	for (int i = 0; i < verts; i++) {
		bigForest->makeSet(i);
	}

	//Utwórz zbiór S zawieraj¹cy wszystkie krawêdzie oryginalnego grafu
	BinaryHeap * queue;
	queue = new BinaryHeap();
	for (int i = 0; i < verts; i++) {
		for (int j = 0; j < verts; j++) {
			int tempEdgeVal = myGraph->whatIsEdge(i, j);
			if (tempEdgeVal!= 0) {
				queue->append((-1)*tempEdgeVal, j, i);//value, where to?, where from?
			}
		}
	}
	//Dopóki S nie jest pusty oraz L nie jest jeszcze drzewem rozpinaj¹cym: 
	bool isMST = false;
	int mergeTimes = 0;
	while (!queue->isSizeZero() && !isMST) {
		//Wybierz i usuñ z S jedn¹ z krawêdzi o minimalnej wadze.
		graphData tempX = queue->pop();
		int tempVal = (-1)*tempX.value;
		int tempTo = tempX.verticleNumb;
		int tempFrom = tempX.verticleFrom;
		//jeœli krawêdŸ ta ³¹czy³a dwa ró¿ne drzewa, to dodaj j¹ do lasu L, 
		//tak aby po³¹czy³a dwa odpowiadaj¹ce drzewa w jedno.
		if (bigForest->findSet(tempFrom) != bigForest->findSet(tempTo)) {
			bigForest->unionSets(tempFrom, tempTo);
			answerSum += tempVal;
			if (shouldBePrinted) {
				//cout << "(" << tempFrom << ")->" << "(" << tempTo << ")"
				//	<< "value(" << tempVal << ") AnswerSum: "
				//	<< answerSum << "\n";//skad dokad, jaka wartosc
			}
			answerGraph->addEdge(tempX.verticleFrom, tempX.verticleNumb, (-1)*tempX.value, false);
			answerGraph->addEdgeList(tempX.verticleFrom, tempX.verticleNumb, (-1)*tempX.value, false);
			mergeTimes++;
			if (mergeTimes == verts - 1) {//jesli polaczyles wystarczajaco wiele razy
				isMST = true;
			}
		}
		else {//W przeciwnym wypadku odrzuæ j¹.
			//notihng?
		}
	}
	if (shouldBePrinted) {
		cout << "Macierzowa\n";
		answerGraph->printStart();
		cout << "Listowa\n";
		answerGraph->printWithValuesList();
		cout << "Sumaryczna wartoœæ : " << answerSum << endl;
		cout << "koniec dzialania algorytmu kruskala\n\n";
	}
	
}

void algorithms::algorithmKruskalList(GraphM_NO * myGraph, bool shouldBePrinted)
{
	GraphM_NO * answerGraph;
	answerGraph = new GraphM_NO(myGraph->getVertM(), 0);

	int answerSum = 0;
	int verticleStart = myGraph->getVertMST();
	if (shouldBePrinted) {
		cout << "Algorytm Kruskal LIST zaczyna dzialanie\n";
	}

	int verts = myGraph->getVertL();//myGraph->vertsNum;
	int edges = myGraph->getEdgesL();//myGraph->edgesNum;
	//int **matrixData = myGraph->matrix;
	if (verts == 1) {
		cout << "Graf ma tylko jeden wierzcholek\n";
		cout << "Algorytm Kruskal list konczy dzialanie\n";
		return;
	}
	if (verts == 0) {
		cout << "Graf nie ma wierzcholkow wierzcholek\n";
		cout << "Algorytm Kruskal list konczy dzialanie\n";
		return;
	}

	//Utwórz las L z wierzcho³ków oryginalnego grafu – 
	//ka¿dy wierzcho³ek jest na pocz¹tku osobnym drzewem.
	Forest* bigForest;
	bigForest = new Forest(verts);
	for (int i = 0; i < verts; i++) {
		bigForest->makeSet(i);
	}

	//Utwórz zbiór S zawieraj¹cy wszystkie krawêdzie oryginalnego grafu
	BinaryHeap * queue;
	queue = new BinaryHeap();
	for (int i = 0; i < verts; i++) {
		for (int j = 0; j < verts; j++) {
			int tempEdgeVal = myGraph->whatIsEdgeList(i, j);
			if (tempEdgeVal != 0) {
				queue->append((-1)*tempEdgeVal, j, i);//value, where to?, where from?
			}
		}
	}
	//Dopóki S nie jest pusty oraz L nie jest jeszcze drzewem rozpinaj¹cym: 
	bool isMST = false;
	int mergeTimes = 0;
	while (!queue->isSizeZero() && !isMST) {
		//Wybierz i usuñ z S jedn¹ z krawêdzi o minimalnej wadze.
		graphData tempX = queue->pop();
		int tempVal = (-1)*tempX.value;
		int tempTo = tempX.verticleNumb;
		int tempFrom = tempX.verticleFrom;
		//jeœli krawêdŸ ta ³¹czy³a dwa ró¿ne drzewa, to dodaj j¹ do lasu L, 
		//tak aby po³¹czy³a dwa odpowiadaj¹ce drzewa w jedno.
		if (bigForest->findSet(tempFrom) != bigForest->findSet(tempTo)) {
			bigForest->unionSets(tempFrom, tempTo);
			answerSum += tempVal;
			if (shouldBePrinted) {
				//cout << "(" << tempFrom << ")->" << "(" << tempTo << ")"
				//	<< "value(" << tempVal << ") AnswerSum: "
				//	<< answerSum << "\n";//skad dokad, jaka wartosc
			}
			answerGraph->addEdge(tempX.verticleFrom, tempX.verticleNumb, (-1)*tempX.value, false);
			answerGraph->addEdgeList(tempX.verticleFrom, tempX.verticleNumb, (-1)*tempX.value, false);
			mergeTimes++;
			if (mergeTimes == verts - 1) {//jesli polaczyles wystarczajaco wiele razy
				isMST = true;
			}
		}
		else {//W przeciwnym wypadku odrzuæ j¹.
			//notihng?
		}
	}
	if (shouldBePrinted) {
		cout << "Macierzowa\n";
		answerGraph->printStart();
		cout << "Listowa\n";
		answerGraph->printWithValuesList();
		cout << "Sumaryczna wartoœæ : " << answerSum << endl;
		cout << "koniec dzialania algorytmu kruskala list \n\n";
	}
}

void algorithms::algorithmBelmanM(GraphM_NO * myGraph, bool shouldBePrinted)
{
	//Dla grafu G, funkcji wagowej w i wierzcho³ka s otrzymamy tablicê 
	//d[u] odleg³oœci ka¿dego wierzcho³ka grafu od wierzcho³ka s

	/*Bellman-Ford(G,w,s):

		dla ka¿dego wierzcho³ka v w V[G] wykonaj
		  d[v] = nieskoñczone
		  poprzednik[v] = niezdefiniowane
		d[s] = 0
		dla i od 1 do |V[G]| - 1 wykonaj
		  dla ka¿dej krawêdzi (u,v) w E[G] wykonaj
			je¿eli d[v] > d[u] + w(u,v) to
			  d[v] = d[u] + w(u,v)
			  poprzednik[v] = u
	*/
	int verticleStart = myGraph->getVertMST();
	if (shouldBePrinted) {
		cout << "Algorytm Belman_Ford zaczyna dzialanie\n";
	}
	int verts = myGraph->getVertM();
	int edges = myGraph->getEdgesM();
	if (verts == 1) {
		cout << "Graf ma tylko jeden wierzcholek\n";
		cout << "Algorytm Belman_Ford konczy dzialanie\n";
		return;
	}
	if (verts == 0) {
		cout << "Graf nie ma wierzcholkow wierzcholek\n";
		cout << "Algorytm Belman_Ford konczy dzialanie\n";
		return;
	}

	//dla ka¿dego wierzcho³ka v w V[G] wykonaj
	//d[v] = nieskoñczone
	int infinity = 9999;//przeniesc definicje do *.h
	int * valueOfPaths;

	int *previousFrom;
	previousFrom = new int[verts];

	valueOfPaths = new int[verts];
	for (int i = 0; i < verts; i++) {
		valueOfPaths[i] = infinity;


		//poprzednik[v] = niezdefiniowane
		previousFrom[i] = infinity;
		if (i == verticleStart) {
			previousFrom[i] = i;
		}
	}



	//d[s] = 0
	valueOfPaths[verticleStart] = 0;

	//dla i od 1 do |V[G]| - 1 wykonaj
	for (int i = 0; i < verts-1; i++) {
		// wykonaj dla ka¿dej krawêdzi(u, v) w E[G]
		for (int i = 0; i < verts; i++) {
			for (int j = 0; j < verts; j++) {
				//listOfEdges->addTailGraph()

				int tempVal = myGraph->whatIsEdge(i, j);
				if ( tempVal != 0) {
					//je¿eli d[v] > d[u] + w(u,v) to
					//(valueOfPaths[temp_to] > valueOfPaths[temp_from] + tempValue)
					if (valueOfPaths[j] > valueOfPaths[i] + tempVal) {
						//d[v] = d[u] + w(u, v)
						//	poprzednik[v] = u
						valueOfPaths[j] = valueOfPaths[i] + tempVal;
						previousFrom[j] = i;
					}
				}
			}
		}
		
	}

	////////////

	if (shouldBePrinted) {
		for (int i = 0; i < verts; i++) {
			int j = i;
			cout << "(" << i << ")";
			while (previousFrom[j] != verticleStart) {
				if (previousFrom[j] == infinity) {
					break;
				}
				cout << "<-(" << previousFrom[j] << ")";
				j = previousFrom[j];

			}
			cout << "<-(" << verticleStart << ")   ";

			/*for (int j = 0; j < verts; j++) {
				cout << previousFrom[j]<<" ";
			}*/
			cout << "do punktu(" << i << ") ";
			if (valueOfPaths[i] != infinity) {
				cout << valueOfPaths[i];
			}
			else {
				cout << "Brak polaczenia!";
			}

			cout << endl;
		}
		cout << "Algorytm Belmana Forda konczy dzialanie\n";
		cout << endl;
	}
	
}

void algorithms::algorithmBelmanList(GraphM_NO * myGraph, bool shouldBePrinted)
{
	//Dla grafu G, funkcji wagowej w i wierzcho³ka s otrzymamy tablicê 
	//d[u] odleg³oœci ka¿dego wierzcho³ka grafu od wierzcho³ka s

	/*Bellman-Ford(G,w,s):

		dla ka¿dego wierzcho³ka v w V[G] wykonaj
		  d[v] = nieskoñczone
		  poprzednik[v] = niezdefiniowane
		d[s] = 0
		dla i od 1 do |V[G]| - 1 wykonaj
		  dla ka¿dej krawêdzi (u,v) w E[G] wykonaj
			je¿eli d[v] > d[u] + w(u,v) to
			  d[v] = d[u] + w(u,v)
			  poprzednik[v] = u
	*/
	int verticleStart = myGraph->getVertMST();
	if (shouldBePrinted) {
		cout << "Algorytm Belman_Ford_LIST zaczyna dzialanie\n";
	}
	int verts = myGraph->getVertL();
	int edges = myGraph->getEdgesL();
	if (verts == 1) {
		cout << "Graf ma tylko jeden wierzcholek\n";
		cout << "Algorytm Belman_Ford_LIST konczy dzialanie\n";
		return;
	}
	if (verts == 0) {
		cout << "Graf nie ma wierzcholkow wierzcholek\n";
		cout << "Algorytm Belman_Ford_LIST konczy dzialanie\n";
		return;
	}

	//dla ka¿dego wierzcho³ka v w V[G] wykonaj
	//d[v] = nieskoñczone
	int infinity = 9999;//przeniesc definicje do *.h
	int * valueOfPaths;

	int *previousFrom;
	previousFrom = new int[verts];

	valueOfPaths = new int[verts];
	for (int i = 0; i < verts; i++) {
		valueOfPaths[i] = infinity;


		//poprzednik[v] = niezdefiniowane
		previousFrom[i] = infinity;
		if (i == verticleStart) {
			previousFrom[i] = i;
		}
	}

	//d[s] = 0
	valueOfPaths[verticleStart] = 0;

	//dla i od 1 do |V[G]| - 1 wykonaj
	for (int i = 0; i < verts-1; i++) {
		// wykonaj dla ka¿dej krawêdzi(u, v) w E[G]
		for (int i = 0; i < verts; i++) {
			for (int j = 0; j < verts; j++) {
				//listOfEdges->addTailGraph()

				int tempVal = myGraph->whatIsEdgeList(i, j);
				if (tempVal != 0) {
					//je¿eli d[v] > d[u] + w(u,v) to
					//(valueOfPaths[temp_to] > valueOfPaths[temp_from] + tempValue)
					if (valueOfPaths[j] > valueOfPaths[i] + tempVal) {
						//d[v] = d[u] + w(u, v)
						//	poprzednik[v] = u
						valueOfPaths[j] = valueOfPaths[i] + tempVal;
						previousFrom[j] = i;
					}
				}
			}
		}

	}

	////////////

	if (shouldBePrinted) {
		for (int i = 0; i < verts; i++) {
			int j = i;
			cout << "(" << i << ")";
			while (previousFrom[j] != verticleStart) {
				if (previousFrom[j] == infinity) {
					break;
				}
				cout << "<-(" << previousFrom[j] << ")";
				j = previousFrom[j];

			}
			cout << "<-(" << verticleStart << ")   ";

			/*for (int j = 0; j < verts; j++) {
				cout << previousFrom[j]<<" ";
			}*/
			cout << "do punktu(" << i << ") ";
			if (valueOfPaths[i] != infinity) {
				cout << valueOfPaths[i];
			}
			else {
				cout << "Brak polaczenia!";
			}

			cout << endl;
		}
		cout << "Algorytm Belmana Forda List konczy dzialanie\n";
		cout << endl;
	}
}



void algorithms::toExcel() {
	//----------miniProgram---------------------//
	fstream wyniki;
	fstream wynikiCor;
	std::string  dataRow;
	wynikiCor.open("wynikiCor.txt", ios::out);
	wyniki.open("wyniki.txt", ios::in);
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
	//------------------------------------------------
}

void algorithms::algorithm_Dijkstra(GraphM_NO * myGraph, bool shouldBePrinted)
{
	int verticleStart = myGraph->getVertMST();
	if (shouldBePrinted) {
		cout << "Algorytm Dijkstra zaczyna dzialanie\n";
	}
	int verts = myGraph->getVertM();//myGraph->vertsNum;
	int edges = myGraph->getEdgesM();//myGraph->edgesNum;
	//int **matrixData = myGraph->matrix;
	if (verts == 1) {
		cout << "Graf ma tylko jeden wierzcholek\n";
		cout << "Algorytm Dijkstra konczy dzialanie\n";
		return;
	}
	if (verts == 0) {
		cout << "Graf nie ma wierzcholkow wierzcholek\n";
		cout << "Algorytm Dijkstra konczy dzialanie\n";
		return;
	}

	bool * usedFromQ;
	usedFromQ = new bool[verts];
	for (int i = 0; i < verts; i++) {
		usedFromQ[i] = false;
	}

	int infinity = 9999;//przeniesc definicje do *.h
	int * valueOfPaths;
	valueOfPaths = new int[verts];
	for (int i = 0; i < verts; i++) {
		valueOfPaths[i] = infinity;
	}

	int *previousFrom;
	previousFrom = new int[verts];
	for (int i = 0; i < verts; i++) {
		previousFrom[i] = infinity;
		if (i == verticleStart) {
			previousFrom[i] = i;
		}
	}


	int firstVert = verticleStart;
	valueOfPaths[firstVert] = 0;
	usedFromQ[firstVert] = true;

	BinaryHeap * qHeap;
	qHeap = new BinaryHeap();			//kolejka priorytetowa
	

	for (int i = 0; i < verts; i++) {
		if (i == firstVert) {
			qHeap->append(0, i, 0);
		}
		else {
			qHeap->append((-1)*infinity, i, 0);//kopiec est maksymalny wiec dla ulatwienia tylko mnoze przez (-1)
		}
	}

	
	bool* usedV2;
	usedV2 = new bool[verts];
	for (int i = 0; i < verts; i++) {
		usedV2[i] = false;
	}
	////////////
	while (!qHeap->isSizeZero()) {//qHeap is not null
		graphData tempX = qHeap->pop();
		if (usedV2[tempX.verticleNumb] == true ) {
			//juz to badalem, wyciagnij to i nic nie rob z tym, potrzebne ze wzgeldu na nadmiar danych w kopcu
			continue;
		}
		//tempX.verticleNumb; ---wierzcholek z kotrego wyciagmy
		int father = tempX.verticleNumb;
		for (int i = 0; i < verts; i++) {		//chce wyznaczyc sasiadow  father'a
			int tempEdgeVal = myGraph->whatIsEdge(father, i);
			if (tempEdgeVal != 0) {
				if (usedFromQ[i] == false) {//jesli uzyty juz zostal to go pomin(jesli zostaly dla niego juz rozpatrzone odnogi)
					//posiblyVerts->append((-1)*(matrixData[father][i]), i, father);
					//(nie)wkladam do kopca z ujemna wartoscia aby korzen(max) wartosc,do_gdzie, from_gdzie

					if ((valueOfPaths[father] + (tempEdgeVal)) < valueOfPaths[i]) {
						valueOfPaths[i] = (valueOfPaths[father] + (tempEdgeVal));
						qHeap->append((-1)*valueOfPaths[i], i, father);
						previousFrom[i] = father;
					}

				}
			}
		}
		usedFromQ[father] = true;
		usedV2[father] = true;//to chyba niepotrzebne, ustalane tak samo jakusedFromQ

	
	}
	///////////
	if (shouldBePrinted) {
		for (int i = 0; i < verts; i++) {
			int j = i;
			cout << "(" << i << ")";
			while (previousFrom[j] != firstVert) {
				if (previousFrom[j] == infinity) {
					break;
				}
				cout << "<-(" << previousFrom[j] << ")";
				j = previousFrom[j];
				/*if (j == infinity) {
					break;
				}*/
			}
			cout << "<-(" << firstVert << ")   ";

			/*for (int j = 0; j < verts; j++) {
				cout << previousFrom[j]<<" ";
			}*/
			cout << "do punktu(" << i << ") ";
			if (valueOfPaths[i] != infinity) {
				cout << valueOfPaths[i];
			}
			else {
				cout << "Brak polaczenia!";
			}

			cout << endl;
		}
		cout << "Algorytm Dijkstra konczy dzialanie\n";
		cout << endl;
	}
	
	
}

