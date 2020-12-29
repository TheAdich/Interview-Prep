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

bool dfs(vector<int> graph[], int node, int parent, map<int, bool>& visited, map<int, bool>& color) {

	for (auto nbr : graph[node]) {

		if (visited[nbr] == false) {
			visited[nbr] = true;
			color[nbr] = !color[node];

			int sub_bipartite = dfs(graph, nbr, node, visited, color);

			if (!sub_bipartite)
				return false;
		}

		else if (nbr != parent && color[nbr] == color[node])
			return false;
	}

	return true;
}

bool bipartite(vector<int> graph[], int N) {
	map<int, bool> visited;
	map<int, bool> color;

	if (N == 1 || N == 2)
		return true;

	visited[0] = true;
	color[0] = true;

	int ans = dfs(graph, 0, -1, visited, color);

	for (auto i : color) {
		cout << i.first << " -> " << i.second << endl;
	}

	deb(ans);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	// N: Nodes
	// M: Edges
	int N, M;
	cin >> N >> M;

	vector<int> graph[N];

	while (M--) {
		int x, y;
		cin >> x >> y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 0; i < N; i++)
		cout << i << " -> " << graph[i] << endl;
	cout << endl;
	bipartite(graph, N);
	// Graph is Bipartite if no Odd Cycle.
	// No odd cycle means that graph is Bipartite

	//DFS by colouring nodes at each step
}