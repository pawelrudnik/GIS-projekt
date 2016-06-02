#include "stdafx.h"
#include "DijkstraAlgorithm.h"

#define INF INT_MAX

DijkstraAlgorithm::DijkstraAlgorithm()
{
}

DijkstraAlgorithm::~DijkstraAlgorithm()
{
}

vector<Edge> DijkstraAlgorithm::GetShortestPath(vector<int> vertices, vector<Edge> edges, int start, int end)
{
	N = vertices.size();
	dist.resize(N, INF);
	prev.resize(N, -1);

	graph = edges;
	Q = vertices;

	dist[start] = 0;

	int u = 0;
	int v = 0;
	double alt = 0;
	vector<Edge> possibleEdges;
	while (!Q.empty())
	{
		//Find vertex with shortest distance
		int min = Q[0];
		for (int i = 1; i < Q.size(); i++)
		{
			if(dist[Q[i]] < dist[min]) 
				min = Q[i];
		}

		u = min; //Set u as a vertex with smallest distance

		if (u == end) break; //If it is our target vertex then break

		Q.erase(remove(Q.begin(), Q.end(), u), Q.end()); //Delete vertex u from Q

		possibleEdges = GetPossibleEdges(u); //Find adjacent edges to  vertex u

		for(Edge edge : possibleEdges)
		{
			alt = dist[u] + edge.weight; //Calculate distance to adjacent vertex

			if (edge.vertex1 == u) //Get adjacent vertex from edge
				v = edge.vertex2;
			else
				v = edge.vertex1;

			if (alt < dist[v]) //If shorter path to v was found
			{
				dist[v] = alt;
				prev[v] = u;
			}
		}
	}

	u = end;

	while (prev[u] >= 0) //Go from end to start
	{
		chosenEdges.push_back(GetEdge(u, prev[u])); //Add edges on the path
		u = prev[u];
	}

	return chosenEdges;
}

vector<Edge> DijkstraAlgorithm::GetPossibleEdges(int v)
{
	vector<Edge> possibleEdges;
	for (int i = 0; i < graph.size(); i++)
	{
		if (graph[i].vertex1 == v || graph[i].vertex2 == v)
		{
			possibleEdges.push_back(graph[i]);
		}
	}

	return possibleEdges;
}

Edge DijkstraAlgorithm::GetEdge(int u, int v)
{
	for (int i = 0; i < graph.size(); i++)
	{
		if ((graph[i].vertex1 == u && graph[i].vertex2 == v) || (graph[i].vertex1 == v && graph[i].vertex2 == u))
		{
			return graph[i];
		}
	}

	return Edge(0, 0, 0); //In case of error
}
