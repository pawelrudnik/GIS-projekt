#pragma once

class Edge {
public:
	int vertex1;
	int vertex2;
	double weight;

	Edge() {}

	Edge(int vertex1, int vertex2, double weight)
	{
		this->vertex1 = vertex1;
		this->vertex2 = vertex2;
		this->weight = weight;
	}
};
