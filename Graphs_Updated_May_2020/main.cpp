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
#define min3(x,y,z)      (x < y ? (x < z ? x : z) : (y < z ? y : z))
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

int shortestDistance(vector<vector<int>> &grid) {
	int row = grid.size();
	int col = grid[0].size();

	vector<int> x(row, 0);
	vector<int> y(col, 0);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (grid[i][j] == 1) {
				x[i]++;
				y[j]++;
			}
		}
	}

	vector<int> manhattenX(row, 0);
	for (int i = 0; i < row; i++) {
		for (int j = i, k = 0; k < row; j = (j + 1) % row, k++) {
			manhattenX[i] += abs(j - i) * x[j];
		}
	}
	vector<int> manhattenY(col, 0);
	for (int i = 0; i < col; i++) {
		for (int j = i, k = 0; k < col; j = (j + 1) % col, k++) {
			manhattenY[i] += abs(j - i) * y[j];
		}
	}
	int result = INT_MAX;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (grid[i][j] == 0) {
				result = std::min(result, manhattenX[i] + manhattenY[j]);
			}
		}
	}
	return result == INT_MAX ? -1 : result;
}

int main()
{
	vector<vector<int>> arr = {
		{1, 1, 1},
		{1, 1, 1},
		{1, 1, 1}
	};
	cout << shortestDistance(arr);
}