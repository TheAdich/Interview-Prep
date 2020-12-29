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

#define si(x)           scanf("%d",&x)
#define sl(x)           scanf("%lld",&x)
#define ss(s)           scanf("%s",s)
#define pi(x)           printf("%d\n",x)
#define pl(x)           printf("%lld\n",x)
#define ps(s)           printf("%s\n",s)

#define fi              first
#define se              second
#define ll              long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mk(arr,n,type)  type *arr=new type[n];

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

template<typename T>
class Graph {
	map<T, vector<T>> adjList;

public:

	void addEdge(T a, T b, bool bidir = true)
	{
		adjList[a].push_back(b);
		if (bidir == true)
			adjList[b].push_back(a);
	}

	void printAdjList()
	{
		for (auto i : adjList)
		{
			cout << i.first << " -> ";
			for (auto vertex : i.second)
				cout << vertex << ",";
			cout << endl;
		}
	}

	vector<T> BFS(T src)
	{
		queue<T> q;
		map<T, bool> visited;

		vector<T> res;

		q.push(src);
		visited[src] = true;

		while (!q.empty())
		{
			T cur = q.front();
			q.pop();

			res.push_back(cur);

			for (auto i : adjList[cur])
			{
				if (visited[i] == false)
				{
					q.push(i);
					visited[i] = true;
				}
			}
		}

		return res;
	}

	void BFS_SSSP_All_Nodes(T src)
	{
		queue<T> q;
		map<T, bool> visited;
		map<T, int> dist;

		q.push(src);
		visited[src] = true;
		dist[src] = 0;

		while (!q.empty())
		{
			T cur = q.front();
			q.pop();

			for (auto i : adjList[cur])
			{
				if (visited[i] == false)
				{
					q.push(i);
					visited[i] = true;
					dist[i] = dist[cur] + 1;
				}
			}
		}

		for (auto i : dist) {
			cout << "Distance of " << i.first << ": " << i.second << endl;
		}
	}

	vector<T> BFS_SSSP_Src_Dest(T src, T dest)
	{
		queue<T> q;
		map<T, bool> visited;
		map<T, int> dist;
		map<T, T> pred;

		q.push(src);
		visited[src] = true;
		dist[src] = 0;
		pred[src] = src;

		while (!q.empty())
		{
			T cur = q.front();
			q.pop();

			for (auto i : adjList[cur])
			{
				if (visited[i] == false)
				{
					q.push(i);
					visited[i] = true;
					dist[i] = dist[cur] + 1;
					pred[i] = cur;

					if (i == dest)
						break;
				}
			}
		}

		vector<T> path;
		// for (auto i : dist) {
		if (visited[dest])
		{
			cout << "Distance of " << dest << ": " << dist[dest] << endl;

			T temp = dest;

			while (temp != src)
			{
				path.push_back(temp);
				temp = pred[temp];
			}
			path.push_back(src);

			reverse(path.begin(), path.end());
			return path;
		}
		else
			cout << "Not found";
		// }
		return {};
	}


};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	Graph<int> g;

	g.addEdge(1, 2, true);
	g.addEdge(2, 3, true);
	g.addEdge(2, 6, true);
	g.addEdge(3, 7, true);
	g.addEdge(3, 4, true);
	g.addEdge(4, 8, true);
	g.addEdge(8, 7, true);
	g.addEdge(7, 6, true);
	g.addEdge(6, 5, true);
	g.addEdge(5, 1, true);
	g.addEdge(6, 9, true);
	g.addEdge(7, 9, true);
	g.addEdge(9, 10, true);

	g.printAdjList();
	cout << endl;
	cout << g.BFS_SSSP_Src_Dest(1, 10);

}

/**
	Graph<char> g;

	g.addEdge('A', 'B', true);
	g.addEdge('A', 'C', true);
	g.addEdge('A', 'D', true);
	g.addEdge('B', 'E', true);
	g.addEdge('C', 'E', true);
	g.addEdge('C', 'F', true);
	g.addEdge('D', 'F', true);
	g.addEdge('E', 'G', true);
	g.addEdge('F', 'G', true);

	g.printAdjList();
	g.DFS('C');
**/