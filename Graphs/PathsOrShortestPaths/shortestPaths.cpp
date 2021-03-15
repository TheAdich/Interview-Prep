/**
 * Muhammad Ali, one of my great heroes, had a great line
 * in the '70s when he was asked "How many sit-ups do you do?"
 * He said, "I don't count my sit-ups. I only start counting when
 * it starts hurting. When I feel pain, that's when I start counting
 * because that's when it really counts". That's what makes you a
 * champion. And that's the way it is with everything.
 * ~ Arnold Schwarzenegger
**/

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define deb(x)          cout << #x << "=" << x << endl
#define deb2(x, y)      cout << #x << "=" << x << "," << #y << "=" << y << endl

// C++ template to print vector container elements
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == 10000000)
			os << "INF";
		else
			os << v[i];
		if (i != v.size() - 1)
			os << " ";
	}
	return os;
}

/**
In an undirected graph, BFS gives shortest distance from Src to Dest.
**/

/**
Floyd Warshall
**/
void floydWarshall(int n, vector<vector<int>> graph) {
	for (int k = 0; k < n; k++)
		for (int u = 0; u < n; u++)
			for (int v = 0; v < n; v++)
				graph[u][v] = min(graph[u][v], graph[u][k] + graph[k][v]);

	for (auto row : graph)
		cout << row << endl;
}

int main()
{
	//Adjacency Matrix with Weights
	// int vertices;
	// cin >> vertices;

	// vector<vector<int>> graph(vertices, vector<int>(vertices));

	// for (int row = 0; row < vertices; row++)
	// 	for (int col = 0; col < vertices; col++) {
	// 		string s;
	// 		cin >> s;
	// 		if (s[0] == 'I')
	// 			graph[row][col] = 10000000;
	// 		else
	// 			graph[row][col] = stoi(s);
	// 	}
}