#include "pch.h"
#include "Forest.h"


void Forest::makeSet(int iter)
{
	myForest[iter].up = iter;
	myForest[iter].rank = 0;
}

void Forest::unionSets(int v_from, int v_to)// wierzcholek z jednego zbioru, wierzcholek z drugiego ze zbiorow
{
	int root_1;
	int root_2;
	root_1 = findSet(v_from);//szukaj korzenia drzewa 1
	root_2 = findSet(v_to);	//szukaj korzenia drzewa 2
	if (root_1 != root_2) {	//laczymy drzewa w jedno
		if (myForest[root_1].rank > myForest[root_2].rank) {
			myForest[root_2].up = root_1;
		}
		else {
			myForest[root_1].up = root_2;
			if (myForest[root_1].rank == myForest[root_2].rank) {
				myForest[root_2].rank++;
			}
		}
	}
}

int Forest::findSet(int verticleX)
{
	if (myForest[verticleX].up != verticleX) {	//wyszukiwanie reprezentanta
		myForest[verticleX].up = findSet(myForest[verticleX].up);
	}
	return myForest[verticleX].up;
}

Forest::Forest(int howMany)
{
	myForest = new forestElement[howMany];
}


Forest::~Forest()
{
	delete[] myForest;
}
