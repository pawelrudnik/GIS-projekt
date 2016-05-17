#pragma once

class Edge {
public:
	int node1;
	int node2;
	double weight;

	Edge() {}

	Edge(int node1, int node2, double weight)
	{
		this->node1 = node1;
		this->node2 = node2;
		this->weight = weight;
	}
};
