#pragma once
//NOT OREIENTED MATRIX GRAPH
#include <ctime>
#include "DoubleConectedList.h"
class GraphM_NO
{
private:
	int vertMST = 0;

	//czesc listowej reprezentacji
	DoubleConectedList ** myList;
	int edgesNumList;
	int vertsNumList;

	//czesc macierzowej reprezentacji
	int ** matrix;
	int vertsNum;
	int edgesNum;

public:

	void addEdge(int vertFrom, int vertTo, int value, bool isOriented);
	void createRandom(int numberOfVerticles, int percentOfEdges, bool isOriented);
	int whatIsEdge(int i, int j);	
	void printStart();

	//czesc listowej
	void print_startList();
	void printWithValuesList();
	void saveToFileList(std::string fileName);

	void addEdgeList(int vertFrom, int vertTo, int value, bool isOriented);	//dodaj do reprezentacji listowej
	int whatIsEdgeList(int i, int j);


	//GraphM_NO();
	GraphM_NO(bool isOriented);
	GraphM_NO(bool isOriented, int nothing);
	GraphM_NO(int verts, int edges);
	~GraphM_NO();

	int getVertM();
	int getVertL();
	void setVertL(int vertNumber);
	void setVertM(int vertNumber);

	int getEdgesM();
	int getEdgesL();
	void setEdgesM(int number);
	void setEdgesL(int number);

	int getVertMST();
};

