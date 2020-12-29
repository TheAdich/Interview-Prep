/*
There are N cities numbered from 0 to N-1. You have to choose 2 cities such that there is no path from first city to second city .
You are given information in the form of M pairs (X,Y) i.e there is an undirected road between city X and city Y.
Find out the number of ways in which cities can be chosen.

Input Format
The first line contains two integers, N and M separated by a single space. M lines follow. Each line contains integers separated by a single space X and Y denoting road between X and Y.

Constraints
1 <= N <= 100000 1 <= M <= 100000 0 <= X,Y <= N-1

Output Format
An integer that denotes the number of permissible ways to choose a pair of cities.

Sample Input
5 3
0 1
2 3
0 4
Sample Output
6
Explanation
0 1 4 cannot be reached by 2 hence (2,0) (2,1) (2,4) and also 0 1 4 cannot be reached by 3 so (3,0) (3,1) (3,4) hence 6 ways.

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
			deb2(v1, v2);
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
		edgeList.push_back({v1, v2});
	}

	cout << containsCycle(edgeList, vertices);
}