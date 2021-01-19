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
		os << v[i];
		if (i != v.size() - 1)
			os << " ";
	}
	return os;
}

/**
Undirected
**/

//BFS
/**
Cycle: If you find a node which is visited
**/
bool _undirectedBFS(int cur, vector<int> adj[], vector<bool>& visited) {
	queue<int> q;
	q.push(cur);

	while (!q.empty()) {
		//Remove
		int parent = q.front();
		q.pop();

		//Cycle Detected
		if (visited[parent] == true)
			return true;
		//Mark*
		visited[parent] = true;

		//Add
		for (auto nbr : adj[parent]) {
			if (visited[nbr] == false)
				q.push(nbr);
		}
	}

	return false;
}

bool undirectedBFS(int V, vector<int> adj[]) {
	vector<bool> visited(V, false);
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			if (_undirectedBFS(i, adj, visited))
				return true;
	return false;
}

//DFS
/**
Cycle: If you find a node which is
visited and is not your parent
return true to every call
**/

bool _undirectedDFS(int cur, int parent, vector<int> adj[], vector<bool>& visited) {
	visited[cur] = true;

	for (auto nbr : adj[cur]) {
		if (visited[nbr] == false) {
			bool foundCycle = _undirectedDFS(nbr, cur, adj, visited);
			if (foundCycle)
				return true;
		} else if (nbr != parent)
			return true;
	}
	return false;
}

bool undirectedDFS(int V, vector<int> adj[]) {
	vector<bool> visited(V, false);
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			if (_undirectedDFS(i, i, adj, visited))
				return true;
	return false;
}

/**
Directed
**/

//DFS
/**
Cycle: If you find a node which is
visited and in the path (ancestor array)
**/
bool _directedDFS(int cur, vector<int> adj[], vector<bool>& visited, vector<bool>& ancestor) {
	visited[cur] = true;
	ancestor[cur] = true;

	for (auto nbr : adj[cur]) {
		if (ancestor[nbr] == true)
			return true;
		else if (visited[nbr] == false) {
			bool foundCycle = _directedDFS(nbr, adj, visited, ancestor);
			if (foundCycle)
				return true;
		}
	}

	ancestor[cur] = false;
	return false;
}

bool directedDFS(int V, vector<int> adj[]) {
	vector<bool> visited(V, false);
	vector<bool> ancestor(V, false);

	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			if (_directedDFS(i, adj, visited, ancestor))
				return true;
	return false;
}
//BFS
/**
Cycle: You exhaust all nodes with indegree 0
and still have some unvisited nodes.
**/
bool directedBFS(int V, vector<int> adj[]) {
	int visited = 0;
	vector<int> indegree(V, 0);
	for (int i = 0; i < V; i++)
		for (auto nbr : adj[i])
			++indegree[nbr];
	deb(indegree);

	queue<int> q;

	for (int i = 0; i < V; i++)
		if (indegree[i] == 0)
			q.push(i);

	while (!q.empty()) {
		int rem = q.front(); q.pop();

		++visited;

		for (auto nbr : adj[rem]) {
			--indegree[nbr];
			if (indegree[nbr] == 0)
				q.push(nbr);
		}
	}

	return !(visited == V);
}

//Colorful DFS
/**
Color 0 = Not visited
Color 1 = Visited BUT not in Path
Color 2 = Visited BUT in Path
**/
bool _directedColouredDFS(int cur, vector<int> adj[], vector<int>& color) {
	color[cur] = 2;

	for (auto nbr : adj[cur]) {
		if (color[nbr] == 2)
			return true;
		else if (color[nbr] == 0) {
			bool foundCycle = _directedColouredDFS(nbr, adj, color);
			if (foundCycle)
				return true;
		}
	}

	color[cur] = 1;
	return false;
}

bool directedColouredDFS(int V, vector<int> adj[]) {
	vector<int> color(V, 0);

	for (int i = 0; i < V; i++)
		if (color[i] == 0)
			if (_directedColouredDFS(i, adj, color))
				return true;
	return false;
}

int main()
{
	int vertices, edges;
	cin >> vertices >> edges;

	vector<int> adj[vertices];

	//Undirected
	// for (int i = 0; i < edges; i++) {
	// 	int v1, v2;
	// 	cin >> v1 >> v2;

	// 	adj[v1].push_back(v2);
	// 	adj[v2].push_back(v1);
	// }

	//Directed
	for (int i = 0; i < edges; i++) {
		int v1, v2;
		cin >> v1 >> v2;

		adj[v1].push_back(v2);
	}

	cout << directedColouredDFS(vertices, adj);
}