#pragma once
class algorithms
{
public:
	algorithms();
	~algorithms();
	//static void algorithm_Prim(GraphM_NO* myGraph);//nie uzywac kto w boga wierzy
	static void algorithm_PrimV2(GraphM_NO* myGraph,bool shouldBePrinted);
	static void algorithm_Dijkstra(GraphM_NO* myGraph, bool shouldBePrinted);//zmienic na graphM-OR

	static void algorithm_Prim_List(GraphM_NO* myGraph, bool shouldBePrinted);
	static void algorithm_Dijkstra_List(GraphM_NO* myGraph, bool shouldBePrinted);

	static void algorithmKruskal(GraphM_NO* myGraph, bool shouldBePrinted);
	static void algorithmKruskalList(GraphM_NO* myGraph, bool shouldBePrinted);

	static void algorithmBelmanM(GraphM_NO* myGraph, bool shouldBePrinted);
	static void algorithmBelmanList(GraphM_NO* myGraph, bool shouldBePrinted);

	static void toExcel();

	//static void algorithm_DijkstraV2(GraphM_NO* myGraph, int verticleStart);//zmienic na graphM-OR

	

};

