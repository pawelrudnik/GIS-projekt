#pragma once
#include "Edge.h"
class PrimAlgorithm
{
private:
	vector<Edge> Graph;
	vector<Edge> ChosedEdges;
	vector<Edge> PossibleEdges;

	vector <int> GraphVertices;
	vector <int> AddedVertices;
	int ChooseNextEdgeIndex();
	vector<int> GetVerticesList(vector<Edge> inputGraph);
	//void DeleteElementFromList(vector <Edge> list, Edge element);
	bool CheckIfGraphHasNoCycle(int newEdgeIndex);
	vector<Edge> GetPossibleEdges();
public:
	vector<Edge> GetMST(vector<Edge> inputGraph);
	PrimAlgorithm();
	~PrimAlgorithm();
};

