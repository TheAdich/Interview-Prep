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

class Pair {
public:
	int v;
	string psf;
};

bool bipartite(vector<vector<int>> graph, vector<int>& color, int cur) {
	queue<int> q;
	q.push(cur);

	color[cur] = 1;

	while (!q.empty()) {
		//Remove
		//Mark*
		//Work
		//Add*

		int parent = q.front();
		q.pop();

		for (auto nbr : graph[parent]) {
			// If neighbour not coloured
			if (color[nbr] == 0) {
				//Color it Opposite of parent;
				color[nbr] = 3 - color[parent];
				q.push(nbr);
			} else if (color[nbr] == color[parent]) {
				return false;
			}
		}
	}

	return true;
}

int main()
{
	int vertices, edges;
	cin >> vertices >> edges;

	vector<vector<int>> graph(vertices);

	for (int i = 0; i < edges; i++) {
		int v1, v2, wt;
		cin >> v1 >> v2 >> wt;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	vector<int> color(vertices);

	int isBipartite = false;
	for (int i = 0; i < vertices; i++) {
		if (color[i] == 0) {
			isBipartite = isBipartite && bipartite(graph, color, i);
		}
	}

	isBipartite ? cout << "true" : cout << "false";
}