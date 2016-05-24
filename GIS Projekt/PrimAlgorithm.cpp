#include "stdafx.h"
#include "PrimAlgorithm.h"


vector<int> PrimAlgorithm::GetVerticesList(vector<Edge> inputGraph)
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

//void PrimAlgorithm::DeleteElementFromList(vector<Edge> list, Edge element)
//{
//	list.erase(std::remove(list.begin(), list.end(), element), list.end());
//}

bool PrimAlgorithm::CheckIfGraphHasNoCycle(int newEdgeIndex)
{
	if (find(AddedVertices.begin(), AddedVertices.end(), PossibleEdges[newEdgeIndex].vertex1) == AddedVertices.end() || find(AddedVertices.begin(), AddedVertices.end(), PossibleEdges[newEdgeIndex].vertex2) == AddedVertices.end())
	{

		return true;
	}

	return false;
}

vector<Edge> PrimAlgorithm::GetPossibleEdges()
{
	vector<int> indexes;
	for (int i = 0; i < Graph.size(); i++)
	{
		if (Graph[i].vertex1 == AddedVertices.back() || Graph[i].vertex2 == AddedVertices.back())
		{
			PossibleEdges.push_back(Graph[i]);
			indexes.push_back(i);
			Graph.erase(Graph.begin() + i);
			i--;
		}
	}

	/*for (int i = 0; i < indexes.size(); i++)
	{
		Graph.erase(Graph.begin() + indexes[i]);
	}*/

	return PossibleEdges;
}

int PrimAlgorithm::ChooseNextEdgeIndex()
{
	double minWeight = PossibleEdges[0].weight;
	int index = 0;
	for (int i = 1; i < PossibleEdges.size(); i++)
	{
		if (PossibleEdges[i].weight < minWeight)
		{
			minWeight = PossibleEdges[i].weight;
			index = i;
		}
	}
	return index;
}

vector<Edge> PrimAlgorithm::GetMST(vector<Edge> inputGraph)
{
	GraphVertices = GetVerticesList(inputGraph);
	Graph = inputGraph;
	AddedVertices.push_back(GraphVertices[0]);
	while (AddedVertices.size() != GraphVertices.size())
	{
		PossibleEdges = GetPossibleEdges();
		int shortestedgeindex = ChooseNextEdgeIndex();
		if (CheckIfGraphHasNoCycle(shortestedgeindex))
		{
			if (find(AddedVertices.begin(), AddedVertices.end(), PossibleEdges[shortestedgeindex].vertex1) == AddedVertices.end())
			{
				AddedVertices.push_back(PossibleEdges[shortestedgeindex].vertex1);
				
			}
			else
			{
				AddedVertices.push_back(PossibleEdges[shortestedgeindex].vertex2);

			}
			ChosedEdges.push_back(PossibleEdges[shortestedgeindex]);

			PossibleEdges.erase(PossibleEdges.begin() + shortestedgeindex);
		}
		else
		{
			PossibleEdges.erase(PossibleEdges.begin() + shortestedgeindex);
		}

	}
	return ChosedEdges;
}


PrimAlgorithm::PrimAlgorithm()
{
}


PrimAlgorithm::~PrimAlgorithm()
{
}
