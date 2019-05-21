#pragma once
class Forest//las zbiorow rozlacznych
{
	struct forestElement {//dsn node
		int up;
		int rank;
	};
private:
	//DoubleConectedList* myForest;
	forestElement * myForest;
public:
	void makeSet(int v123);
	void unionSets(int v_from,int v_to);
	int findSet(int v123);
	//Forest();
	Forest(int howMany);
	~Forest();
};

