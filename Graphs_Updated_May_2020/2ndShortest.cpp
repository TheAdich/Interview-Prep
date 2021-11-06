#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#define INF 1000000

using namespace std;

//http://poj.org/problem?id=3255
//https://www.programmerall.com/article/9117601551/

vector<vector<pair<int, int> > > graph;
vector<int> distFromStart;
vector<int> distFromEnd;

void dijkstra(int src, vector<int> &dist) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > minHeap;
	minHeap.push(make_pair(0, src));
	dist[src] = 0;
	while (!minHeap.empty()) {
		pair<int, int> node = minHeap.top(); minHeap.pop();
		int val = node.second;
		int wsf = node.first;

		for (int i = 0; i < graph[val].size(); i++) {
			pair<int, int> edge = graph[val][i];
			int nbr = edge.first;
			int wt = edge.second;
			if (dist[nbr] > wsf + wt)
			{
				dist[nbr] = wsf + wt;
				minHeap.push(make_pair(wsf + wt, nbr));
			}
		}
	}
}

int main()
{

	int V, e;
	scanf("%d%d", &V, &e);
	vector<vector<int> > edges(e, vector<int>(3, 0));

	for (int i = 0; i < e; i++) {
		scanf("%d%d%d", &edges[i][0], &edges[i][1], &edges[i][2]);
	}

	graph.resize(V + 1);
	for (int i = 0; i < e; i++) {
		vector<int> edge = edges[i];
		int u = edge[0], v = edge[1], w = edge[2];
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}

	distFromStart.resize(V + 1, INF);
	distFromEnd.resize(V + 1, INF);
	dijkstra(1, distFromStart);
	dijkstra(V, distFromEnd);

	int shortest = distFromStart[V];
	cout << shortest << endl;
	int result = INF;
	for (int i = 0; i < e; i++) {
		vector<int> edge = edges[i];
		int u = edge[0], v = edge[1], w = edge[2];
		int op1 = distFromStart[u] + w + distFromEnd[v];
		if (op1 == shortest)
			op1 = INF;
		int op2 = distFromStart[v] + w + distFromEnd[u];
		if (op2 == shortest)
			op2 = INF;
		result = min(result, min(op1, op2));
	}

	cout << result << endl;
}