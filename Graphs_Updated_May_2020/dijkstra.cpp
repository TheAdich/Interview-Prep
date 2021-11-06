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
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>

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

int v;
vector<vector<vector<int>>> graph;
vector<int> visited;
vector<int> dist;
vector<int> parent;
struct Node {
	int val;
	int parent;
	int wsf;
	string psf;
};

class Compare {
public:
	bool operator()(Node A, Node B) {
		// if (A.wsf == B.wsf)
		//     return A.parent > B.parent;
		return A.wsf > B.wsf;
	}
};

void dijkstra_01(int src) {
	priority_queue<Node, vector<Node>, Compare> minHeap;
	minHeap.push({src, src, 0, to_string(src)});
	while (!minHeap.empty()) {
		Node node = minHeap.top(); minHeap.pop();

		if (visited[node.val] == true)
			continue;
		visited[node.val] = true;

		cout << node.val << " via " << node.psf << " @ " << node.wsf << endl;

		for (vector<int> edge : graph[node.val]) {
			int nbr = edge[0];
			int wt = edge[1];
			if (visited[nbr] == false)
				minHeap.push({nbr, node.val, node.wsf + wt, node.psf + to_string(nbr)});
		}
	}
}

void dijkstra_02(int src) {
	priority_queue<Node, vector<Node>, Compare> minHeap;
	minHeap.push({src, src, 0, to_string(src)});
	dist[src] = 0;
	parent[src] = src;
	while (!minHeap.empty()) {
		Node node = minHeap.top(); minHeap.pop();

		for (vector<int> edge : graph[node.val]) {
			int nbr = edge[0];
			int wt = edge[1];
			if (dist[nbr] > dist[node.val] + wt)
			{
				dist[nbr] = dist[node.val] + wt;
				parent[nbr] = node.val;
				minHeap.push({nbr, node.val, node.wsf + wt, node.psf + to_string(nbr)});
			}
		}
	}
	for (int i = 0; i < v; i++) {
		string psf = "";
		int cur = i;
		while (cur != parent[cur]) {
			psf = to_string(cur) + psf;
			cur = parent[cur];
		}
		psf = to_string(parent[cur]) + psf;
		cout << i << " via " << psf << " @ " << dist[i] << endl;
	}
}

int main()
{
	int e;
	cin >> v >> e;

	graph.resize(v);
	visited.resize(v, false);
	dist.resize(v, INT_MAX);
	parent.resize(v, -1);
	for (int i = 0; i < e; i++) {
		int v1, v2, wt;
		cin >> v1 >> v2 >> wt;
		graph[v1].push_back({v2, wt});
		graph[v2].push_back({v1, wt});
	}

	int src;
	cin >> src;

	dijkstra_02(src);
}