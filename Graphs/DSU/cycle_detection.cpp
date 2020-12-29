/*
By Ali Hasan

Concept (Abdul Bari) : https://www.youtube.com/watch?v=wU6udHRIkcc

Intro
Union-Find Algorithm can be used to check whether an UNDIRECTED graph contains cycle or not.

CONTENT

#
#
#

*/

#include<bits/stdc++.h>

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
			os << ", ";
	}
	return os;
}

int find(int i, vector<int>& parent) {
	if (parent[i] == -1)
		return i;
	return find(parent[i], parent);
}

void union_set(int s1, int s2, vector<int>& parent) {
	if (s1 != s2)
		parent[s2] = s1;
}

bool containsCycle(vector<pair<int, int>> edgeList, int vertices)
{
	vector<int> parent(vertices, -1);

	for (auto edge : edgeList) {
		int v1 = edge.first;
		int v2 = edge.second;

		int s1 = find(v1, parent);
		int s2 = find(v2, parent);

		if (s1 == s2) {
			deb2(v1 + 1, v2 + 1);
			cout << "Cycle found\n";
			return true;
		}

		//Union
		parent[s2] = s1;
	}
	return false;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	int vertices, edges;
	cin >> vertices >> edges;

	vector<pair<int, int>> edgeList;

	for (int i = 0; i < edges; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		edgeList.push_back({v1 - 1, v2 - 1});
	}

	cout << containsCycle(edgeList, vertices);
}