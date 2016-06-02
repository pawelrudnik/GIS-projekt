#include "stdafx.h"
#include "FinalAlgorithm.h"
#include "DijkstraAlgorithm.h"


FinalAlgorithm::FinalAlgorithm()
{

}


FinalAlgorithm::~FinalAlgorithm()
{

}

vector<Edge> FinalAlgorithm::GetFinalMST(vector<Edge> inputGraph , vector< pair<int, bool>> VerticesFlags)
{
	//vector< int, bool> vect;
	vector<int> unchosen;
	for (int i = 0; i < VerticesFlags.size(); i++)
	{
		if (VerticesFlags[i].second)
		{
			ChosedVertices.push_back(VerticesFlags[i].first);
		}
		else
		{
			unchosen.push_back(VerticesFlags[i].first);
		}
		GraphVertices.push_back(VerticesFlags[i].first);
	}
	RemainingVertices = ChosedVertices;
	
	Graph = inputGraph;
	AddedVertices.push_back(GraphVertices[0]);
	RemainingVertices.erase(std::remove(RemainingVertices.begin(), RemainingVertices.end(), GraphVertices[0]), RemainingVertices.end());	// usuwamy pierwszy wierzcholek z listy pozostalych
	PossiblePaths = GetPossiblePaths(AddedVertices.back());

	while (AddedVertices.size() != ChosedVertices.size())
	{
		int shortestPathIndex = ChooseNextPathIndex();
		if (!CheckIfGraphHasNoCycle(shortestPathIndex))
		{
			for (int i = 0; i < PossiblePaths[shortestPathIndex].size(); i++)
			{
				if (find(AddedVertices.begin(), AddedVertices.end(), PossiblePaths[shortestPathIndex][i].vertex1) == AddedVertices.end())
				{
					if (VerticesIsChosen(PossiblePaths[shortestPathIndex][i].vertex1));
					{
						if ((find(AddedVertices.begin(), AddedVertices.end(), PossiblePaths[shortestPathIndex][i].vertex1) == AddedVertices.end()))
						{
							AddedVertices.push_back(PossiblePaths[shortestPathIndex][i].vertex1);
							RemainingVertices.erase(std::remove(RemainingVertices.begin(), RemainingVertices.end(), PossiblePaths[shortestPathIndex][i].vertex1), RemainingVertices.end());	// usuwamy wierzcholek z listy pozostalych
						}
						//PossiblePaths = GetPossiblePaths(AddedVertices.back());

						break;
					}

				}
				else
				{
					if (VerticesIsChosen(PossiblePaths[shortestPathIndex][i].vertex2) && (find(AddedVertices.begin(), AddedVertices.end(), PossiblePaths[shortestPathIndex][i].vertex2) == AddedVertices.end()));
					{
						if ((find(AddedVertices.begin(), AddedVertices.end(), PossiblePaths[shortestPathIndex][i].vertex2) == AddedVertices.end()))
						{
							AddedVertices.push_back(PossiblePaths[shortestPathIndex][i].vertex2);
							RemainingVertices.erase(std::remove(RemainingVertices.begin(), RemainingVertices.end(), PossiblePaths[shortestPathIndex][i].vertex2), RemainingVertices.end());	// usuwamy wierzcholek z listy pozostalych
						}

						break;
					}

				}
				
			}
			for (int j = 0; j < PossiblePaths.size(); j++)
			{
				for (int i = 0; i < PossiblePaths[j].size(); i++)
				{

					if (find(unchosen.begin(), unchosen.end(), PossiblePaths[j][i].vertex1) != unchosen.end())	//jesli na najkrotszej sciezce jest wierzcholek niezaznaczony, tez dodajemy mozliwe drogi
					{
						unchosen.erase(std::remove(unchosen.begin(), unchosen.end(), PossiblePaths[j][i].vertex1), unchosen.end());
							PossiblePaths = GetPossiblePaths(PossiblePaths[j][i].vertex1);

					}

					if (find(unchosen.begin(), unchosen.end(), PossiblePaths[j][i].vertex2) != unchosen.end())
					{
						unchosen.erase(std::remove(unchosen.begin(), unchosen.end(), PossiblePaths[j][i].vertex2), unchosen.end());
						PossiblePaths = GetPossiblePaths(PossiblePaths[j][i].vertex2);

					}
				}

			}


			ChosedPaths.push_back(PossiblePaths[shortestPathIndex]);

			PossiblePaths.erase(PossiblePaths.begin() + shortestPathIndex);
		}
		else
		{
			PossiblePaths.erase(PossiblePaths.begin() + shortestPathIndex);
		}
	}

		vector<Edge> ChosedEdges;
		for (int i = 0; i < ChosedPaths.size(); i++)
		{
			for (int j = 0; j < ChosedPaths[i].size(); j++)
			{
				ChosedEdges.push_back(ChosedPaths[i][j]);
			}
		
	}
	return ChosedEdges;
}

bool FinalAlgorithm::VerticesIsChosen(int vertice)
{
	for (int i = 0; i < ChosedVertices.size(); i++)
	{
		if (vertice == ChosedVertices[i])
			return true;
	}
	return false;
}

int FinalAlgorithm::ChooseNextPathIndex()
{
	double minWeight = 0;
	for (int i = 0; i < PossiblePaths[0].size(); i++)
	{
		minWeight += PossiblePaths[0][i].weight;
	}
	
	int possibleMinWeight = 0;
	
	int index = 0;
	for (int i = 1; i < PossiblePaths.size(); i++)
	{
		for (int j = 0; j < PossiblePaths[i].size(); j++)
		{
			possibleMinWeight += PossiblePaths[i][j].weight;
		}
		if (possibleMinWeight < minWeight)
		{
			minWeight = possibleMinWeight;
			index = i;
		}
		possibleMinWeight = 0;
	}
	return index;
}

vector<int> FinalAlgorithm::GetVerticesList(vector<Edge> inputGraph)
{
	vector <int> vert;
	vert.push_back(inputGraph[0].vertex1);
	vert.push_back(inputGraph[0].vertex2);
	for (int i = 1; i < inputGraph.size(); i++)
	{

		if (find(vert.begin(), vert.end(), inputGraph[i].vertex1) == vert.end())
		{
			vert.push_back(inputGraph[i].vertex1);
		}
		if (find(vert.begin(), vert.end(), inputGraph[i].vertex2) == vert.end())
		{
			vert.push_back(inputGraph[i].vertex2);
		}
	}
	return vert;
}

bool FinalAlgorithm::CheckIfGraphHasNoCycle(int newEdgeIndex)
{
	for (int i = 0; i < PossiblePaths[newEdgeIndex].size(); i++)
	{
		if (find(AddedVertices.begin(), AddedVertices.end(), PossiblePaths[newEdgeIndex][i].vertex1) == AddedVertices.end() || find(AddedVertices.begin(), AddedVertices.end(), PossiblePaths[newEdgeIndex][i].vertex2) == AddedVertices.end())
		{
			return false;	// jak false to spoko (nie zawiera)
		}
	}

	return true;	//zawiera, wyjazd z nim
}

vector<vector<Edge>> FinalAlgorithm::GetPossiblePaths(int verticeId)  //djikstra
{
	// dla kazdego wierzcholka z listy mozliwych szukaj sciezek dla ostatniego z listy dodanych
	DijkstraAlgorithm d;
	
	for (int i = 0; i < RemainingVertices.size(); i++)
	{
		vector<Edge> vect = d.GetShortestPath(GraphVertices, Graph, verticeId, RemainingVertices[i]);
		if(vect.size() > 0)
		PossiblePaths.push_back(vect);
	}
	return PossiblePaths;
}
