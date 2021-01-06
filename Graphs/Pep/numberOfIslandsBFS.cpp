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

class Pair {
public:
   int x;
   int y;
};

void islands(vector<vector<int>> &graph, int x, int y) {
   queue<Pair> q;
   q.push({x, y});

   while (!q.empty()) {
      //Remove
      //Mark*
      //Work
      //Add*

      Pair rem = q.front();
      q.pop();

      graph[rem.x][rem.y] = 2;

      if (rem.x - 1 >= 0 && graph[rem.x - 1][rem.y] == 0)
         q.push({rem.x - 1, rem.y});

      if (rem.y + 1 < COL && graph[rem.x][rem.y + 1] == 0)
         q.push({rem.x, rem.y + 1});

      if (rem.x + 1 < ROW && graph[rem.x + 1][rem.y] == 0)
         q.push({rem.x + 1, rem.y});

      if (rem.y - 1 >= 0 && graph[rem.x][rem.y - 1] == 0)
         q.push({rem.x, rem.y - 1});
   }

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

   // for (auto r : graph)
   //    cout << r << endl;

   // deb(count);
   cout << count << endl;
}