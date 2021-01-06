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
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>

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

int ROW, COL;

void islands(vector<vector<int>> &graph, int x, int y) {
   if (x < 0 || x >= ROW || y < 0 || y >= COL || graph[x][y] == 1 || graph[x][y] == 2)
      return;

   graph[x][y] = 2;

   islands(graph, x - 1, y);
   islands(graph, x, y + 1);
   islands(graph, x + 1, y);
   islands(graph, x, y - 1);
}

int main()
{
   cin >> ROW >> COL;

   vector<vector<int>> graph(ROW, vector<int>(COL));

   for (int i = 0; i < ROW; i++)
      for (int j = 0; j < COL; j++)
         cin >> graph[i][j];

   int count = 0;

   for (int i = 0; i < ROW; i++)
      for (int j = 0; j < COL; j++)
         if (graph[i][j] == 0) {
            ++count;
            islands(graph, i, j);
         }

   cout << count << endl;
}