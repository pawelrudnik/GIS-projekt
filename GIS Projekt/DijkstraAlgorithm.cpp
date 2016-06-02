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
		//Znajd� wierzcho�ek o najmniejszej odleg�o�ci
		int min = Q[0];
		for (int i = 1; i < Q.size(); i++)
		{
			if(dist[Q[i]] < dist[min]) 
				min = Q[i];
		}

		u = min; //Ustaw u jako wierzcho�ek o najmniejszej odleg�o�ci

		if (u == end) break; //Je�li u jest naszym ko�cem �cie�ki to zako�cz

		Q.erase(remove(Q.begin(), Q.end(), u), Q.end()); //Usu� wierzcho�ek u ze zbioru Q

		possibleEdges = GetPossibleEdges(u); //Znajd� kraw�dzie wychodz�ce z wierzcho�ka u

		for(Edge edge : possibleEdges) //Dla ka�ej s�siedniej kraw�dzi
		{
			alt = dist[u] + edge.weight; //Wylicz odleg�o�� do wierzcho�ka po��czonego t� kraw�dzi�

			if (edge.vertex1 == u) //Uzyskaj s�siedni wierzcho�ek z tej kraw�dzi
				v = edge.vertex2;
			else
				v = edge.vertex1;

			if (alt < dist[v]) //Je�li znaleziono kr�tsz� �cie�k� do v
			{
				dist[v] = alt; //Podmi� odleg�o��
				prev[v] = u; //Dodaj poprzednika
			}
		}
	}

	u = end;

	vector<Edge> chosenEdges;
	while (prev[u] >= 0) //Id� od konca do pocz�tku �cie�ki
	{
		chosenEdges.push_back(GetEdge(u, prev[u])); //Dodaj kraw�dzie do �cie�ki
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

	return Edge(0, 0, 0); //W przypadku b��du
}
