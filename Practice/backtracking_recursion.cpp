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

const int D = 20;
char board[D][D] = {};

void clearBoard(char mat[][D], int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			mat[i][j] = '.';
		}
	}
}

void printMat(char mat[][D], int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << mat[i][j];
		}
		cout << endl;
	}
}

bool check(int n, int x, int y) {
	// check row or col
	for (int i = 0; i < n; ++i) {
		if (board[x][i] == 'Q') return false;
		if (board[i][y] == 'Q') return false;
	}

	// check diagonal
	for (int dist = 1; dist < n; ++dist) {
		int prRow = x - dist;
		int prCol = y - dist;
		if (prRow >= 0 && prRow <= n &&
		        prCol >= 0 && prCol <= n &&
		        board[prRow][prCol] == 'Q') {
			return false;
		}

		int secRow = x - dist;
		int secCol = y + dist;
		if (secRow >= 0 && secRow <= n &&
		        secCol >= 0 && secCol <= n &&
		        board[secRow][secCol] == 'Q') {
			return false;
		}
	}
	return true;
}

bool nqueen(int n, int r) {
	if (n == r) {
		// no row to place a queen
		// no queen to place
		printMat(board, n, n);
		return true;
	}
	for (int c = 0; c < n; ++c) {
		bool canPlace = check(n, r, c);
		if (canPlace) {
			board[r][c] = 'Q';
			// checks if recursion is successful in setting the remaining board
			bool success = nqueen(n, r + 1);
			if (success) {
				return true;
			}
			board[r][c] = '.';
		}
	}
	return false;
}

bool knightMove(int n, int r, int c, int moveNo)
{
	if (moveNo == n * n) {
		printMat(board, n, n);
		return;
	}

	int rowDir[] = { +1, +2, +2, +1, -1, -2, -2, -1};
	int colDir[] = { +2, +1, -1, -2, -2, -1, +1, +2};

	for (int i = 0 ; i < 8 ; i++)
	{
		int next_row = r + rowDir[i];
		int next_col = c + colDir[i];
		bool canPlace = check(n, nextRow, nextCol);
		if (canPlace) {
			board[nextRow][nextCol] = moveNo;
			bool success = knightMove(n, nextRow, nextCol, moveNo + 1);
			if (success) return true;
			board[nextRow][nextCol] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	board[0][0] = -1;

	bool success = knightMove(n, 0, 0, 1);
	if (success) {
		printMat(board, n, n);
	}
	else {
		cout << "Failed";
	}
}