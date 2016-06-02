#pragma once

class Edge {
public:
	int vertex1;
	int vertex2;
	double weight;

	bool operator==(const Edge& rhs)
	{
		return (vertex1 == rhs.vertex1 && vertex2 == rhs.vertex2 && weight == rhs.weight);
	}

	Edge() {}

	Edge(int vertex1, int vertex2, double weight)
	{
		this->vertex1 = vertex1;
		this->vertex2 = vertex2;
		this->weight = weight;
	}
};
