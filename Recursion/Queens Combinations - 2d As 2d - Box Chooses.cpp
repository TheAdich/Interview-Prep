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

//Combination 1
//For every BOX -> Place or Don't Place
vector<vector<char>> grid;
void queen2dBoxChoose(int r, int c, int tq) {
	int gs = grid.size();
	if (tq == 0) {
		for (auto row : grid)
			cout << row << endl;
		cout << endl;
		return;
	}

	if (r >= gs || c >= gs)
		return;

	if (c == gs - 1) {
		grid[r][c] = 'q';
		queen2dBoxChoose(r + 1, 0, tq - 1);
		grid[r][c] = '-';
		queen2dBoxChoose(r + 1, 0, tq);
	} else {
		grid[r][c] = 'q';
		queen2dBoxChoose(r, c + 1, tq - 1);
		grid[r][c] = '-';
		queen2dBoxChoose(r, c + 1, tq);
	}
}

int main()
{
	int n;
	cin >> n;
	grid.resize(n, vector<char>(n, '-'));

	queen2dBoxChoose(0, 0, n);
}