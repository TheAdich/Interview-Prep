#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
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
			os << ", ";
	}
	return os;
}

void _perfect_friends(vector<vector<int>> adjList, vector<bool>& visited, int& count, int cur) {
	visited[cur] = true;

	for (auto nbr : adjList[cur]) {
		if (visited[nbr] == false) {
			++count;
			_perfect_friends(adjList, visited, count, nbr);
		}
	}
}

int perfect_friends(vector<vector<int>> adjList) {
	int vertices = adjList.size();

	vector<bool> visited(vertices, false);
	vector<int> comp_sizes;

	for (int i = 0; i < vertices; i++) {
		int count = 0;
		if (visited[i] == false) {
			++count;
			_perfect_friends(adjList, visited, count, i);
			comp_sizes.push_back(count);
		}
	}

	int n = comp_sizes.size();
	int ans = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			ans += comp_sizes[i] * comp_sizes[j];

	return ans;
}

int main()
{
	int vertices, edges;
	cin >> vertices >> edges;

	vector<vector<int>> adjList(vertices);

	for (int i = 0; i < edges; i++) {
		int v1, v2, wt;
		cin >> v1 >> v2;
		adjList[v1].push_back(v2);
		adjList[v2].push_back(v1);
	}

	cout << perfect_friends(adjList);
}