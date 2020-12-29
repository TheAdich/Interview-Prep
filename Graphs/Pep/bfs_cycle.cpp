/**
 * Muhammad Ali, one of my great heroes, had a great line
 * in the '70s when he was asked "How many sit-ups do you do?"
 * He said, "I don't count my sit-ups. I only start counting when
 * it starts hurting. When I feel pain, that's when I start counting
 * because that's when it really counts". That's what makes you a
 * champion. And that's the way it is with everything.
 * ~ Arnold Schwarzenegger
**/

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
			os << "";
	}
	return os;
}

bool _bfsPrint(vector<vector<pair<int, int>>>& adjList, vector<bool>& visited, int src) {
	int vertices = adjList.size();
	queue<int> q;

	q.push(src);

	while (!q.empty()) {
		int parent = q.front();
		q.pop();
		if (visited[parent] == true)
			return true;

		visited[parent] = true;

		for (auto nbr : adjList[parent]) {
			int child = nbr.first;

			if (visited[child] == false) {
				q.push(child);
			}
		}
	}
	return false;
}

bool bfsPrint(vector<vector<pair<int, int>>>& adjList) {
	int vertices = adjList.size();
	vector<bool> visited(vertices, 0);

	for (int i = 0; i < vertices; i++) {
		if (visited[i] == false)
			if (_bfsPrint(adjList, visited, i))
				return true;
	}
	return false;
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

	bfsPrint(adjList) ? cout << "true\n" : cout << "false\n";
}