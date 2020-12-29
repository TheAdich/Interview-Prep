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

// Function to check if (i, j) is valid matrix coordinate
bool isvalid(int i, int j, int N)
{
	return (i >= 0 && i < N && j >= 0 && j < N);
}

// Function to print the route taken
void printPath(vector<int> const &path, int last)
{
	for (int i : path)
		cout << i << " -> ";
	cout << last << endl;
}

void findPaths(vector<vector<int>> mat, vector<int> &path, int i, int j, int N)
{
	// if we have reached the last cell, print the route
	if (i == N - 1 && j == N - 1)
	{
		printPath(path, mat[i][j]);
		return;
	}

	// include current cell in path
	path.push_back(mat[i][j]);

	// move right
	if (isvalid(i, j + 1, N))
		findPaths(mat, path, i, j + 1, N);

	// move down
	if (isvalid(i + 1, j, N))
		findPaths(mat, path, i + 1, j, N);

	// remove current cell from the path
	path.pop_back();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	while (t--) {
		int n;
		cin >> n;

		vector<vector<int>> v;

		for (int i = 0; i < n; i++)
		{
			vi temp;
			for (int j = 0; j < n; j++)
			{
				int input;
				cin >> input;

				temp.push_back(input);
			}
			v.push_back(temp);
			temp.clear();
		}

		vector<int> path;

		// start from (0, 0) cell
		int x = 0, y = 0;

		findPaths(v, path, x, y, n);
	}
}