/*
By Ali Hasan

CONTENT

#Generic Graph
#Adding bidirectional edges to generic graph
#Breadth First Search Prnt
#Single Source Shortest Path using BFS
#Depth First Search Print + Connected Components
#DFS Topological Sort
#BFS Cycle Detection
#DFS Cycle Detection in Directed Graphs
*/

#include<bits/stdc++.h>

using namespace std;

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

#define deb(x)          cout << #x << "=" << x << endl
#define deb2(x, y)      cout << #x << "=" << x << "," << #y << "=" << y << endl

template<typename T>
class Graph {

	unordered_map<T, vector<T>> adjList;

public:
	Graph() {}

	void addEdge(T u, T v, bool bidir = true)
	{
		adjList[u].push_back(v);
		if (bidir == true)
			adjList[v].push_back(u);
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

	void bfsPrint(T src)
	{
		map<T, bool> visited;
		queue<int> q;

		//ENTER START ELEMENT
		q.push(src);
		visited[src] = true;

		while (!q.empty())
		{
			T node = q.front();
			cout << node << " ";
			q.pop();

			for (T i : adjList[node])
			{
				if (visited[i] == 0)
				{
					q.push(i);
					visited[i] = true;
				}
			}
		}
	}

	int sssp(T src, T dest)
	{
		map<T, bool> visited;
		map<T, int> distance;
		queue<T> q;

		//ENTER START ELEMENT
		q.push(src);
		visited[src] = true;
		distance[src] = 0;

		while (q.front() != dest)
		{
			T node = q.front();
			q.pop();

			for (T i : adjList[node])
			{
				if (visited[i] == 0)
				{
					q.push(i);
					visited[i] = true;
					distance[i] = distance[node] + 1;
					cout << "Distance of " << i << " from node " << node << " is " << distance[i] << endl;
				}
			}
		}

		return distance[dest];
	}

	void dfs1Helper(T src, map<T, bool> &visited)
	{
		cout << src << " ";
		visited[src] = true;

		for (auto nbrs : adjList[src])
			if (visited[nbrs] == false)
				dfs1Helper(nbrs, visited);
	}

	void dfs_connected_component()
	{
		map<T, bool> visited;

		int cnt = 0;
		for (auto i : adjList)
		{
			T node = i.first;
			if (!visited[node])
			{
				cout << "Component " << cnt++ << "-->";
				dfs1Helper(node, visited);
				cout << endl;
			}
		}
	}

	void dfsTSHelper(T src, map<T, bool>& visited, stack<T>& stack)
	{
		visited[src] = true;

		for (T vertex : adjList[src])
		{
			if (!visited[vertex])
			{
				visited[vertex] = true;
				dfsTSHelper(vertex, visited, stack);
			}
		}

		stack.push(src);
	}

	void dfsTopologicalSort()
	{
		map<T, bool> visited;
		stack<T> stack;

		for (auto i : adjList)
		{
			T node = i.first;
			if (!visited[node])
			{
				deb(node);
				dfsTSHelper(node, visited, stack);
			}
		}

		while (!stack.empty())
		{
			cout << stack.top() << " ";
			stack.pop();
		}
	}

	void TS_BFS(int n)
	{
		int indegree[n];
		vector<int> ans;

		for (int i = 0; i < n; i++)
			indegree[i] = 0;

		//Fill indegree array
		for (auto i : adjList)
			for (auto j : i.second)
				++indegree[j];

		for (int i = 0; i < n; i++)
			cout << i << ": " << indegree[i] << endl;

		queue<int> q;

		for (int i = 0; i < n; i++)
			if (indegree[i] == 0)
				q.push(i);

		while (!q.empty())
		{
			int popped = q.front();
			q.pop();

			ans.push_back(popped);

			for (auto i : adjList[popped])
			{
				--indegree[i];
				if (indegree[i] == 0) //Time to push
					q.push(i);
			}
		}

		for (auto i : ans)
			cout << i << ", ";
	}

	bool unweighted_shortest_path(T src, T dest, int n)
	{
		map<T, bool> visited;
		queue<int> q;

		q.push(src);

		int pre[n];

		for (int i = 0; i < n; i++)
			pre[i] = 0;

		while (!q.empty())
		{
			int popped = q.front();
			q.pop();

			for (auto i : adjList[popped])
			{
				if (!visited[i])
				{
					pre[i] = popped;
					q.push(i);
					visited[i] = true;

					if (i == dest)
						break;
				}
			}
		}

		stack<int> path;

		T temp = dest;

		for (int i = 0; i < n; i++)
		{
			path.push(temp);
			if (temp == src)
			{
				while (!path.empty())
				{
					cout << path.top() << " -> ";
					path.pop();
				}
				return true;
			}
			temp = pre[temp];
		}

		return false;
	}

	/*
	We say that a graph has a cycle if there is an edge between
	U and V such that
	i.   V is adjacent to U
	ii.  V is already visited
	iii. V is also in queue, which means that V also is left to traverse
	and vice-e-versa for V and U

	In simple words if we say that U meets a person that is
	already visited but that person also still left to traverse then
	there is a cycle

	In more simple words it's like there are two people who are
	trying to find maybe love. If a person A finds person B who is
	also looking for love then there is a cycle.

	But it may happen that person A is tring to find love but
	person B with whom he/she wants to create a cycle is not
	adjacent.
	*/

	bool bfsCycleDetection()
	{
		map<T, bool> visited;
		map<T, T> parent;


		for (auto i : adjList)
		{
			T node = i.first;
			for (auto vertex : adjList[node])
			{
				//Apne baap ko tag thodi karunga
				//Skip karke doosre ko tag karta hu
				if (vertex == parent[node])
				{
					continue;
				}
				if (!visited[vertex])
				{
					visited[vertex] = true;
					parent[vertex] = node;
				}
				else
				{
					cout << "Cycle from " << node << " to " << vertex;
					return true;
				}
			}
		}
		return false;
	}

	bool _DFS_directed_cycle(T node, map<T, bool>& visited, map<T, bool>& ancestor) {
		visited[node] = true;
		ancestor[node] = true;

		for (auto nbr : adjList[node]) {
			if (ancestor[nbr] == true)
				return true;

			else if (visited[nbr] != false) {
				bool found_cycle = _DFS_directed_cycle(nbr, visited, ancestor);
				if (found_cycle)
					return true;
			}
		}

		ancestor[node] = false;
		return false;
	}

	bool _DFS_directed_cycle() {
		map<T, bool> visited;
		map<T, bool> ancestor;

		bool cycle = false;
		for (auto i : adjList) {
			if (visited[i.first] == false)
				cycle = cycle || _DFS_directed_cycle(i.first, visited, ancestor);
		}

		return cycle;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	// Graph<int> g;

	// g.addEdge(5, 0, false);
	// g.addEdge(4, 0, false);
	// g.addEdge(5, 2, false);
	// g.addEdge(4, 1, false);
	// g.addEdge(2, 3, false);
	// g.addEdge(1, 3, false);
	// g.dfsTopologicalSort();
	// g.addEdge(2, 4);
	// g.addEdge(2, 3);
	// g.addEdge(3, 5);
	// g.addEdge(3, 4);

	// g.addEdge(6, 7);
	// g.addEdge(7, 8);

	// g.addEdge(10, 11);

	// g.addEdge(0, 1);
	// g.addEdge(1, 2);
	// g.addEdge(2, 3);
	// g.addEdge(3, 4);
	// g.addEdge(4, 5);

	// g.addEdge(1, 2, false);
	// g.addEdge(2, 3, false);

	// g.addEdge(4, 5, false);

	// g.addEdge(6, 7, false);
	// g.addEdge(7, 8, false);
	// g.addEdge(8, 9, false);

	// g.printAdjList();
	// g.dfs_connected_component();
	// g.unweighted_shortest_path(1, 7, 8);

	// g.addEdge("P","Q");
	// g.addEdge("Q","R");
	// g.addEdge("R","S");
	// g.addEdge("S","Q");

	// g.addEdge("K","O");

	// g.addEdge( "English" , "Programming Logic" , false);
	// g.addEdge( "Maths" , "Programming Logic" , false);
	// g.addEdge( "Programming Logic" , "HTML" , false);
	// g.addEdge( "Programming Logic" , "Python" , false);
	// g.addEdge( "Programming Logic" , "Java" , false);
	// g.addEdge( "Programming Logic", "JS", false);
	// g.addEdge( "Python" , "Web Dev" , false) ;
	// g.addEdge( "HTML" , "CSS" , false);
	// g.addEdge( "CSS" , "JS", false);
	// g.addEdge( "JS" , "Web Dev" , false);
	// g.addEdge( "Java", "Web Dev" , false);
	// g.addEdge( "Python", "Web Dev" , false);


	// cout<<endl;
	// g.printAdjList();
	// cout << endl;
	// cout<<"BFS"<<endl;
	// g.bfsPrint(0);
	// cout<<"sssp"<<endl<<g.sssp(3,5);
	// g.printAdjList();
	// g.dfsTopologicalSort();

	// cout<<g.bfsCycleDetection();

	Graph<int> g;

	g.addEdge(5, 0, false);
	g.addEdge(5, 2, false);
	g.addEdge(2, 3, false);
	g.addEdge(4, 0, false);
	g.addEdge(4, 1, false);
	g.addEdge(3, 1, false);

	g.dfsTopologicalSort();;
}