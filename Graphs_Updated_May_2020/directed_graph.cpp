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

#define fi              first
#define se              second
#define ll              long long
#define deb(x)          cout << #x << "=" << x << endl
#define deb2(x, y)      cout << #x << "=" << x << "," << #y << "=" << y << endl
#define min3(x,y,z)      (x < y ? (x < z ? x : z) : (y < z ? y : z))
#define mod             1000000007

// C++ template to print vector container elements
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	for (int i = 0; i < v.size(); ++i) {
		os << v[i];
		if (i != v.size() - 1)  os << " ";
	}
	return os;
}

int V, E;
vector<vector<int>> graph;
vector<bool> visited;

void topoDFS(int node, vector<int>& topo) {
	visited[node] = true;
	for (int nbr : graph[node]) {
		if (visited[nbr] == false)
			topoDFS(nbr, topo);
	}
	topo.push_back(node);
}

vector<int> topologicalOrder() {
	vector<int> topo;
	for (int i = 5, k = 0; k < V; i = (i + 1) % V, k++) {
		if (visited[i] == false)
			topoDFS(i, topo);
	}
	return topo;
}

vector<int> kahnsAlgo() {
	vector<int> indegree(V, 0);
	for (int i = 0; i < V; i++) {
		for (int nbr : graph[i]) {
			++indegree[nbr];
		}
	}
	queue<int> q;
	for (int i = 0; i < V; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}
	vector<int> topo;
	while (!q.empty()) {
		int parent = q.front(); q.pop();
		topo.push_back(parent);
		for (int nbr : graph[parent]) {
			--indegree[nbr];
			if (indegree[nbr] == 0)
				q.push(nbr);
		}
	}
	return topo;
}

//329. Longest Increasing Path in a Matrix
int longestIncreasingPath(vector<vector<int>>& grid) {
	int row = grid.size();
	int col = grid[0].size();

	vector<vector<int>> indegree(row, vector<int>(col, 0));
	int dir[] = { -1, 0, +1, 0, -1};
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			for (int d = 0; d < 4; d++) {
				int nx = i + dir[d];
				int ny = j + dir[d + 1];
				if (nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] < grid[i][j]) {
					++indegree[i][j];
				}
			}
		}
	}

	queue<vector<int>> q;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (indegree[i][j] == 0) {
				q.push({i, j});
			}
		}
	}

	int result = 0;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			vector<int> parent = q.front(); q.pop();
			int px = parent[0];
			int py = parent[1];

			for (int d = 0; d < 4; d++) {
				int nx = px + dir[d];
				int ny = py + dir[d + 1];
				if (nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] > grid[px][py]) {
					--indegree[nx][ny];
					if (indegree[nx][ny] == 0)
						q.push({nx, ny});
				}
			}
		}

		++result;
	}
	return result;
}

int main()
{
	cin >> V >> E;
	graph.resize(V);
	visited.resize(V, false);
	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);

	}
	vector<vector<int>> arr = {
		{9, 9, 4},
		{6, 6, 8},
		{2, 1, 1}
	};
	cout << longestIncreasingPath(arr);
}