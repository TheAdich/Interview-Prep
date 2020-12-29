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

using namespace std;

#define si(x)           scanf("%d",&x)
#define sl(x)           scanf("%lld",&x)
#define ss(s)           scanf("%s",s)
#define pi(x)           printf("%d",x)
#define pl(x)           printf("%lld",x)
#define ps(s)           printf("%s",s)

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

vector<string> result;
string path;

void _path_exist(vector<vector<pair<int, int>>> adjList, vector<bool>& visited, int cur, int dest) {
	if (cur == dest) {
		result.push_back(path);
		return;
	}

	visited[cur] = true;
	for (auto nbr : adjList[cur]) {
		if (visited[nbr.first] == false) {
			path = path + (char)(nbr.first + '0');
			_path_exist(adjList, visited, nbr.first, dest);
			path.pop_back();
		}
	}
	visited[cur] = false;
}

void path_exist(vector<vector<pair<int, int>>> adjList, int src, int dest) {
	int vertices = adjList.size();

	vector<bool> visited(vertices, false);
	path = path + (char)(src + '0');
	_path_exist(adjList, visited, src, dest);
}

int main()
{
	/**
	7
	8
	0 1 10
	1 2 10
	2 3 10
	0 3 10
	3 4 10
	4 5 10
	5 6 10
	4 6 10
	0
	6
	**/
	int vertices, edges;
	cin >> vertices >> edges;

	vector<vector<pair<int, int>>> adjList(vertices);

	for (int i = 0; i < edges; i++) {
		int v1, v2, wt;
		cin >> v1 >> v2 >> wt;
		adjList[v1].push_back({v2, wt});
		adjList[v2].push_back({v1, wt});
	}

	int src, dest;
	cin >> src >> dest;

	path_exist(adjList, src, dest);

	for (auto i : result)
		cout << i << endl;
}