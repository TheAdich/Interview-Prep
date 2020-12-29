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

int osrc;

void _hamiltonian(vector<vector<pair<int, int>>> adjList, set<int>& visited, string path, int cur) {
	if (visited.size() == adjList.size() - 1) {
		cout << path;

		bool closingEdge = false;

		for (auto nbr : adjList[cur]) {
			if (nbr.first == osrc) {
				closingEdge = true;
				break;
			}
		}

		closingEdge ? cout << "*\n" : cout << ".\n";
		return;
	}

	visited.insert(cur);
	for (auto nbr : adjList[cur]) {
		if (visited.find(nbr.first) == visited.end()) {
			_hamiltonian(adjList, visited, path + (char)(nbr.first + '0'), nbr.first);
		}
	}
	visited.erase(cur);
}

void hamiltonian(vector<vector<pair<int, int>>> adjList, int src) {
	int vertices = adjList.size();
	osrc = src;

	set<int> visited;
	string path;
	path = path + (char)(src + '0');
	_hamiltonian(adjList, visited, path, src);
}

int main()
{
	printf(5 + "learner india");
}