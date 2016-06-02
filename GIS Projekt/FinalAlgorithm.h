#pragma once
#include "Edge.h"

class FinalAlgorithm
{
public:
	FinalAlgorithm();
	~FinalAlgorithm(); 
	vector<Edge> GetFinalMST(vector<Edge> inputGraph , vector< pair<int, bool>> VerticesFlags);

private:
	vector<Edge> Graph;
	bool VerticesIsChosen(int vertice);
	vector<vector< Edge>> ChosedPaths;
	vector<vector< Edge>> PossiblePaths;
	vector <int> GraphVertices;
	vector <int> ChosedVertices;
	vector<int> VerticesOnPath;
	vector<int> RemainingVertices;
	int ChooseNextPathIndex();	
	vector<int> GetVerticesList(vector<Edge> inputGraph);
	bool CheckIfGraphHasNoCycle(int newEdgeIndex);
	vector< vector <Edge>> GetPossiblePaths(int verticeId);  //Djikstra
	vector <int> AddedVertices;
};

