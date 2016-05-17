#include "stdafx.h"
#include "Edge.h"
#include "PolishLetters.h"

int main()
{
	ifstream ifile("C:\\Users\\Pawel\\Desktop\\GIS\\file.txt");
	ofstream ofile("C:\\Users\\Pawel\\Desktop\\GIS\\result.txt");
	
	//string filename;

	//cout << PL("Podaj œcie¿kê do pliku wejœciowego: ");
	//cin >> filename;

	//ifile.open(filename);

	//if (!ifile.good())
	//{
	//	cout << PL("B£¥D: Nie uda³o siê otworzyæ pliku wejœciowego.") << endl;
	//	system("pause");
	//	return 0;
	//}

	//cout << PL("Podaj œcie¿kê do pliku wyjœciowego: ");
	//cin >> filename;

	//ofile.open(filename);

	//if (!ofile.good())
	//{
	//	cout << PL("B£¥D: Nie uda³o siê utworzyæ pliku wyjœciowego.") << endl;
	//	system("pause");
	//	return 0;
	//}




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

		vertices.push_back(vertex);
	}

	//Load data from file and save it to vector of edges
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
		
		try
		{
			node1 = stoi(row[0]);
		}
		catch (exception)
		{
			cout << PL("B£¥D: Niepoprawna wartoœæ \"") << row[0] << PL("\". Identyfikator wierzcho³ka musi byæ liczb¹.") << endl;
			system("pause");
			return 0;
		}

		try
		{
			node2 = stoi(row[1]);
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
		
		edges.push_back(Edge(node1, node2, weight));
	}

	ifile.close();

	if (edges.empty())
	{
		cout << PL("B£¥D: Nie znaleziono ¿adnych krawêdzi w pliku wejœciowym.") << endl;
		system("pause");
		return 0;
	}




	//Save edges to file
	for (int i = 0; i < edges.size(); i++)
	{
		ofile << edges[i].node1 + 1 << " ";
		ofile << edges[i].node2 + 1 << " ";
		ofile << edges[i].weight << endl;
	}

	ofile.close();

	system("pause");
    return 0;
}
