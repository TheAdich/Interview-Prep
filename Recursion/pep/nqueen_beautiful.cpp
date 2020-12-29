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

ostream& operator<<(ostream& os, const vector<vector<char>>& board)
{
	int row = board.size();
	int col = board[0].size();

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; j++) {
			os << board[i][j] << " ";
		}
		os << endl;
	}
	return os;
}

bool isSafe(vector<vector<char>>& board, int row, int col) {
	int n = board.size();

	// Check Vertically Up
	for (int i = row - 1, j = col; i >= 0; i--)
		if (board[i][j] == 'Q')	return false;

	// Check Left Up Diagonal
	for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
		if (board[i][j] == 'Q')	return false;

	// Check Right Up Diagonal
	for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
		if (board[i][j] == 'Q')	return false;

	// Check Vertically Down
	for (int i = row + 1, j = col; i < n; i++)
		if (board[i][j] == 'Q')	return false;

	// Check Left Down Diagonal
	for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--)
		if (board[i][j] == 'Q')	return false;

	// Check Right Down Diagonal
	for (int i = row + 1, j = col + 1; i < n && j < n; i++, j++)
		if (board[i][j] == 'Q')	return false;

	return true;
}

void nqueen(vector<vector<char>> board, int row) {
	if (row == board.size()) {
		cout << board << endl;
		return;
	}

	for (int col = 0; col < board.size(); col++) {
		if (isSafe(board, row, col)) {
			board[row][col] = 'Q';
			nqueen(board, row + 1);
			board[row][col] = '_';
		}
	}
}

int main()
{
	int row;
	cin >> row;

	vector<vector<char>> board(row, vector<char>(row, '_'));
	nqueen(board, 0);
}