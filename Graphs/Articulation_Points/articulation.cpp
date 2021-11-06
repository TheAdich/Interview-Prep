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
struct Status {
	int discovery;
	int low;
};
map<int, Status> myMap;
vector<vector<int>> graph;
vector<int> ap;
vector<vector<int>> ae;
int idx = 0;
int rootCalls = 0;
void articulationPoints(int cur, int parent) {
	myMap[cur].discovery = myMap[cur].low = idx++;

	for (int nbr : graph[cur]) {
		//Neighbour Not Visited
		if (nbr != parent) {
			if (myMap.count(nbr) == 0) {
				if (parent == -1)
					++rootCalls;
				articulationPoints(nbr, cur);
				myMap[cur].low = std::min(myMap[cur].low, myMap[nbr].low);
				if (parent != -1 && myMap[cur].discovery <= myMap[nbr].low)
					ap.push_back(cur);
				if (parent == -1 && myMap[cur].discovery <= myMap[nbr].low && rootCalls > 1)
					ap.push_back(cur);
			} else {
				myMap[cur].low = std::min(myMap[cur].low, myMap[nbr].discovery);
			}
		}

	}
}

void articulationPoints(int src) {
	articulationPoints(src, -1);
	vector<int> result(graph.size(), 0);
	for (int point : ap)
		++result[point];
	for (int i = 0; i < graph.size(); i++)
		if (result[i] != 0)
			cout << "Point: " << i << " Breakes into: " << result[i] + 1 << endl;
}

void articulationEdges(int cur, int parent) {
	myMap[cur].discovery = myMap[cur].low = idx++;

	for (int nbr : graph[cur]) {
		//Neighbour Not Visited
		if (nbr != parent) {
			if (myMap.count(nbr) == 0) {
				articulationEdges(nbr, cur);
				myMap[cur].low = std::min(myMap[cur].low, myMap[nbr].low);
				if (myMap[cur].discovery < myMap[nbr].low)
					ae.push_back({cur, nbr});
			} else {
				myMap[cur].low = std::min(myMap[cur].low, myMap[nbr].discovery);
			}
		}

	}
}

void articulationEdges(int src) {
	articulationEdges(src, -1);
}

int main()
{
	int v, e;
	cin >> v >> e;

	graph.resize(v);
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	articulationPoints(0);
}