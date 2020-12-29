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
			os << " ";
	}
	return os;
}

vector<string> getMazePathsJumps(int x, int y, int row, int col) {
	if (x > row || y > col)
		return {};

	if (x == row && y == col)
		return {""};

	vector<vector<string>> rightPaths;
	for (int i = 0; i < row; i++)
		rightPaths.push_back(getMazePathsJumps(x, y + i + 1, row, col));

	vector<vector<string>> downPaths;
	for (int i = 0; i < col; i++)
		downPaths.push_back(getMazePathsJumps(x + i + 1, y, row, col));

	vector<vector<string>> diagonalPaths;
	for (int i = 0; i < row; i++)
		diagonalPaths.push_back(getMazePathsJumps(x + i + 1, y + i + 1, row, col));

	vector<string> paths;

	for (int i = 0; i < rightPaths.size(); i++)
		for (auto path : rightPaths[i])
			paths.push_back("h" + to_string(i + 1) + path);

	for (int i = 0; i < downPaths.size(); i++)
		for (auto path : downPaths[i])
			paths.push_back("v" + to_string(i + 1) + path);

	for (int i = 0; i < diagonalPaths.size(); i++)
		for (auto path : diagonalPaths[i])
			paths.push_back("d" + to_string(i + 1) + path);

	return paths;
}

int main()
{
	int a, b;
	cin >> a >> b;

	vector<string> paths = getMazePathsJumps(0, 0, a - 1, b - 1);
	cout << "[";
	int n = paths.size();
	cout << paths[0];
	for (int i = 1; i < n; i++)
		cout << ", " << paths[i];

	cout << "]";
}