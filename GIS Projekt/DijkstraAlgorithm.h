#pragma once

#include "stdafx.h"
#include "Edge.h"

class DijkstraAlgorithm
{
	int N;
	
	vector<double> dist;
	vector<int> prev;
	vector<int> Q;
	vector<Edge> graph;

public:
	DijkstraAlgorithm();
	~DijkstraAlgorithm();

	vector<Edge> GetShortestPath(vector<int> vertices, vector<Edge> edges, int start, int end);
	vector<Edge> GetPossibleEdges(int v);
	Edge GetEdge(int u, int v);
};
