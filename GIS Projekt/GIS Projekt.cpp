#include "stdafx.h"
#include "Edge.h"
#include "PolishLetters.h"
#include "DijkstraAlgorithm.h"
#include "PrimAlgorithm.h"
#include "FinalAlgorithm.h"

int main()
{
	ifstream ifile("C:\\Users\\Pawel\\Desktop\\GIS\\test_prim_100.txt");
	ofstream ofile("C:\\Users\\Pawel\\Desktop\\GIS\\result.txt");
	
	//string filename;

	//cout << PL("Podaj œcie¿kê do pliku wejœciowego: ");
	//cin >> filename;

	//ifile.open(filename);

	if (!ifile.good())
	{
		cout << PL("B£¥D: Nie uda³o siê otworzyæ pliku wejœciowego.") << endl;
		system("pause");
		return 0;
	}

	//cout << PL("Podaj œcie¿kê do pliku wyjœciowego: ");
	//cin >> filename;

	//ofile.open(filename);

	if (!ofile.good())
	{
		cout << PL("B£¥D: Nie uda³o siê utworzyæ pliku wyjœciowego.") << endl;
		system("pause");
		return 0;
	}



	vector<int> chosenVertices;
	vector<Edge> edges;
	vector<int> vertices;

	string line;
	getline(ifile, line, '\n');

	if (line == "")
	{
		cout << PL("B£¥D: Nie znaleziono zbioru wierzcho³ków w pierwszej linijce pliku.") << endl;
		system("pause");
		return 0;
	}


	istringstream iss(line);
	string element;
	int vertex;

	while (iss >> element)
	{
		try 
		{
			vertex = stoi(element);
		}
		catch(exception)
		{
			cout << PL("B£¥D: Niepoprawna wartoœæ \"") << element << PL("\". Identyfikator wierzcho³ka musi byæ liczb¹.") << endl;
			system("pause");
			return 0;
		}

		if (vertex < 0)
		{
			cout << PL("B£¥D: Niepoprawna wartoœæ \"") << vertex << PL("\". Identyfikator wierzcho³ka musi byæ liczb¹ nieujemn¹.") << endl;
			system("pause");
			return 0;
		}

		chosenVertices.push_back(vertex);
	}

	//Load data from file and save it to vector of edges
	while (!ifile.eof())
	{
		int vertex1, vertex2;
		double weight;

		getline(ifile, line, '\n');

		if (line == "") break;

		istringstream iss(line);
		vector<string> row;

		while (iss >> element)
		{
			row.push_back(element);
		}
		
		if (row.size() < 3)
		{
			cout << PL("B£¥D: Zbyt ma³a iloœæ elementów w wierszu.") << endl;
			system("pause");
			return 0;
		}

		try
		{
			vertex1 = stoi(row[0]);
		}
		catch (exception)
		{
			cout << PL("B£¥D: Niepoprawna wartoœæ \"") << row[0] << PL("\". Identyfikator wierzcho³ka musi byæ liczb¹.") << endl;
			system("pause");
			return 0;
		}

		try
		{
			vertex2 = stoi(row[1]);
		}
		catch (exception)
		{
			cout << PL("B£¥D: Niepoprawna wartoœæ \"") << row[1] << PL("\". Identyfikator wierzcho³ka musi byæ liczb¹.") << endl;
			system("pause");
			return 0;
		}

		try
		{
			weight = stod(row[2]);
		}
		catch (exception)
		{
			cout << PL("B£¥D: Niepoprawna wartoœæ \"") << row[2] << PL("\". Waga krawêdzi musi byæ liczb¹.") << endl;
			system("pause");
			return 0;
		}

		if (weight <= 0)
		{
			cout << PL("B£¥D: Niepoprawna wartoœæ \"") << weight << PL("\". Waga krawêdzi musi byæ wiêksza od 0.") << endl;
			system("pause");
			return 0;
		}
		
		vertices.push_back(vertex1);
		vertices.push_back(vertex2);

		edges.push_back(Edge(vertex1, vertex2, weight));
	}

	ifile.close();

	if (edges.empty())
	{
		cout << PL("B£¥D: Nie znaleziono ¿adnych krawêdzi w pliku wejœciowym.") << endl;
		system("pause");
		return 0;
	}

	//Find unique vertices
	sort(vertices.begin(), vertices.end());
	vertices.erase(unique(vertices.begin(), vertices.end()), vertices.end());
	
	if (chosenVertices.size() > vertices.size())
	{
		cout << PL("B£¥D: Zbiór wybranych wierzcho³ków jest wiêkszy od zbioru wierzcho³ków grafu.") << endl;
		system("pause");
		return 0;
	}



	//Zaczynamy odliczaæ czas
	clock_t tStart = clock();

	if (chosenVertices.size() == 2)
	{
		//Find shortest path
		DijkstraAlgorithm dijkstra;
		edges = dijkstra.GetShortestPath(vertices, edges, chosenVertices[0], chosenVertices[1]);
	}
	else if (chosenVertices.size() == vertices.size())
	{
		//Find MST
		PrimAlgorithm prim;
		edges = prim.GetMST(edges); // podmieniamy nasze krawedzie
	}
	else
	{
		//Find MST for subset of vertices
		vector<pair<int, bool>> verticesflags;
		for (int i = 0; i < vertices.size(); i++)
		{

			int pos = find(chosenVertices.begin(), chosenVertices.end(), vertices[i]) - chosenVertices.begin();
			if (pos >= chosenVertices.size())
			{//nie ma takiego
				verticesflags.push_back(make_pair(vertices[i], false));
			}
			else
			{
				verticesflags.push_back(make_pair(vertices[i], true));
			}
		}
		FinalAlgorithm finalal;
		edges = finalal.GetFinalMST(edges, verticesflags);
	}
	
	//Liczymy czas jaki up³yna³ od pocz¹tku obliczeñ
	double time_elapsed = (double)(clock() - tStart) / CLOCKS_PER_SEC;
	cout << PL("Znaleziono rozwi¹zanie w czasie: ") << time_elapsed << "s" << endl;



	//Save result to file
	for (int i = 0; i < edges.size(); i++)
	{
		ofile << edges[i].vertex1 << " ";
		ofile << edges[i].vertex2 << " ";
		ofile << edges[i].weight << endl;
	}

	ofile.close();

	system("pause");
    return 0;
}
