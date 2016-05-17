// GIS Projekt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Edge.h"

using namespace std;

int main()
{
	ifstream ifile("C:\\Users\\Pawel\\Desktop\\GIS\\file.txt");
	//ofstream ofile("C:\\Users\\Pawel\\Desktop\\GIS\\edges.csv");


	/////////////////////////////////////////
	//            READING DATA             //
	/////////////////////////////////////////


	vector<Edge> edges;
	vector<int> vertices;
	
	string line;
	getline(ifile, line, '\n');

	istringstream iss(line);
	string element;

	while (iss >> element)
	{
		vertices.push_back(stoi(element));
	}

	//Load data from file and save it to matrix
	while (!ifile.eof())
	{
		int node1, node2;
		double weight;

		getline(ifile, line, '\n');

		istringstream iss(line);
		vector<string> row;

		while (iss >> element)
		{
			row.push_back(element);
		}
		
		node1 = stoi(row[0]);
		node2 = stoi(row[1]);
		weight = stod(row[2]);

		edges.push_back(Edge(node1, node2, weight));
	}

	ifile.close();

	for (int i = 0; i < edges.size(); i++)
	{
		cout << edges[i].node1 << " " << edges[i].node2 << " " << edges[i].weight << endl;
	}


	string c;
	cin >> c;
    return 0;
}
