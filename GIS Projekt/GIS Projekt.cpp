#include "stdafx.h"
#include "Edge.h"
#include "PolishLetters.h"

int main()
{
	ifstream ifile("C:\\Users\\prudnik\\Desktop\\GIS\\file.txt");
	ofstream ofile("C:\\Users\\prudnik\\Desktop\\GIS\\result.txt");
	
	//string filename;

	//cout << PL("Podaj �cie�k� do pliku wej�ciowego: ");
	//cin >> filename;

	//ifile.open(filename);

	//if (!ifile.good())
	//{
	//	cout << PL("B��D: Nie uda�o si� otworzy� pliku wej�ciowego.") << endl;
	//	system("pause");
	//	return 0;
	//}

	//cout << PL("Podaj �cie�k� do pliku wyj�ciowego: ");
	//cin >> filename;

	//ofile.open(filename);

	//if (!ofile.good())
	//{
	//	cout << PL("B��D: Nie uda�o si� utworzy� pliku wyj�ciowego.") << endl;
	//	system("pause");
	//	return 0;
	//}



	vector<int> chosenVertices;
	vector<Edge> edges;
	vector<int> vertices;

	string line;
	getline(ifile, line, '\n');

	if (line == "")
	{
		cout << PL("B��D: Nie znaleziono zbioru wierzcho�k�w w pierwszej linijce pliku.") << endl;
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
			cout << PL("B��D: Niepoprawna warto�� \"") << element << PL("\". Identyfikator wierzcho�ka musi by� liczb�.") << endl;
			system("pause");
			return 0;
		}

		if (vertex < 0)
		{
			cout << PL("B��D: Niepoprawna warto�� \"") << vertex << PL("\". Identyfikator wierzcho�ka musi by� liczb� nieujemn�.") << endl;
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

		istringstream iss(line);
		vector<string> row;

		while (iss >> element)
		{
			row.push_back(element);
		}
		
		try
		{
			vertex1 = stoi(row[0]);
		}
		catch (exception)
		{
			cout << PL("B��D: Niepoprawna warto�� \"") << row[0] << PL("\". Identyfikator wierzcho�ka musi by� liczb�.") << endl;
			system("pause");
			return 0;
		}

		try
		{
			vertex2 = stoi(row[1]);
		}
		catch (exception)
		{
			cout << PL("B��D: Niepoprawna warto�� \"") << row[1] << PL("\". Identyfikator wierzcho�ka musi by� liczb�.") << endl;
			system("pause");
			return 0;
		}

		try
		{
			weight = stod(row[2]);
		}
		catch (exception)
		{
			cout << PL("B��D: Niepoprawna warto�� \"") << row[2] << PL("\". Waga kraw�dzi musi by� liczb�.") << endl;
			system("pause");
			return 0;
		}

		if (weight <= 0)
		{
			cout << PL("B��D: Niepoprawna warto�� \"") << weight << PL("\". Waga kraw�dzi musi by� wi�ksza od 0.") << endl;
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
		cout << PL("B��D: Nie znaleziono �adnych kraw�dzi w pliku wej�ciowym.") << endl;
		system("pause");
		return 0;
	}

	//Find unique vertices
	sort(vertices.begin(), vertices.end());
	vertices.erase(unique(vertices.begin(), vertices.end()), vertices.end());
	



	if (chosenVertices.size() > vertices.size())
	{
		cout << PL("B��D: Zbi�r wybranych wierzcho�k�w jest wi�kszy od zbioru wierzcho�k�w grafu.") << endl;
		system("pause");
		return 0;
	}

	if (chosenVertices.size() == 2)
	{
		//Find shortest path
	}
	if (chosenVertices.size() == vertices.size())
	{
		//Find MST
	}
	else
	{
		//Find MST for subset of vertices
	}



	//Save result to file
	for (int i = 0; i < edges.size(); i++)
	{
		//ofile << edges[i].vertex1 + 1 << " ";
		//ofile << edges[i].vertex2 + 1 << " ";
		//ofile << edges[i].weight << endl;
		ofile << vertices[i] << endl;
	}

	ofile.close();

	system("pause");
    return 0;
}
