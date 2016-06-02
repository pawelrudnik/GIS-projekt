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
	graph = edges;
	Q = vertices;

	N = vertices.size();
	dist.resize(N, INF);
	prev.resize(N, -1);

	dist[start] = 0;

	int u = 0;
	int v = 0;
	double alt = 0;
	vector<Edge> possibleEdges;
	while (!Q.empty())
	{
		//Znajd¿ wierzcho³ek o najmniejszej odleg³oœci
		int min = Q[0];
		for (int i = 1; i < Q.size(); i++)
		{
			if(dist[Q[i]] < dist[min]) 
				min = Q[i];
		}

		u = min; //Ustaw u jako wierzcho³ek o najmniejszej odleg³oœci

		if (u == end) break; //Jeœli u jest naszym koñcem œcie¿ki to zakoñcz

		Q.erase(remove(Q.begin(), Q.end(), u), Q.end()); //Usuñ wierzcho³ek u ze zbioru Q

		possibleEdges = GetPossibleEdges(u); //ZnajdŸ krawêdzie wychodz¹ce z wierzcho³ka u

		for(Edge edge : possibleEdges) //Dla ka¿ej s¹siedniej krawêdzi
		{
			alt = dist[u] + edge.weight; //Wylicz odleg³oœæ do wierzcho³ka po³¹czonego t¹ krawêdzi¹

			if (edge.vertex1 == u) //Uzyskaj s¹siedni wierzcho³ek z tej krawêdzi
				v = edge.vertex2;
			else
				v = edge.vertex1;

			if (alt < dist[v]) //Jeœli znaleziono krótsz¹ œcie¿kê do v
			{
				dist[v] = alt; //Podmiñ odleg³oœæ
				prev[v] = u; //Dodaj poprzednika
			}
		}
	}

	u = end;

	vector<Edge> chosenEdges;
	while (prev[u] >= 0) //Id¿ od konca do pocz¹tku œcie¿ki
	{
		chosenEdges.push_back(GetEdge(u, prev[u])); //Dodaj krawêdzie do œcie¿ki
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

	return Edge(0, 0, 0); //W przypadku b³êdu
}
