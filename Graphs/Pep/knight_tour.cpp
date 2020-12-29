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

bool isValid(int n, vector<vector<int>>& board, int x, int y) {
	return (x >= 0 && x < n &&
	        y >= 0 && y < n &&
	        board[x][y] == -1);
}

bool _knights_tour(int n, vector<vector<int>>& board, int x, int y, int count) {
	if (count == n * n) {
		board[x][y] = count;
		for (auto row : board)
			cout << row << endl;
		return true;
	}

	vector<vector<int>> move = {{ -2, +1}, { -1, +2}, { +1, +2}, { +2, +1}, { +2, -1}, { +1, -2}, { -1, -2}, { -2, -1}};

	board[x][y] = count;
	for (int i = 0; i < 8; i++) {
		int nextX = x + move[i][0];
		int nextY = y + move[i][1];

		if (isValid(n, board, nextX, nextY)) {
			bool success = _knights_tour(n, board, nextX, nextY, count + 1);
			if (success)
				return true;
			board[nextX][nextY] = -1;
		}
	}
	return false;
}

void knights_tour(int n, int x, int y) {
	vector<vector<int>> board(n, vector<int>(n, -1));

	_knights_tour(n, board, x, y, 1);
}

int main()
{
	int n;
	cin >> n;

	int x, y;
	cin >> x >> y;

	knights_tour(n, x, y);
}