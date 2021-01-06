/**
 * Muhammad Ali, one of my great heroes, had a great line
 * in the '70s when he was asked "How many sit-ups do you do?"
 * He said, "I don't count my sit-ups. I only start counting when
 * it starts hurting. When I feel pain, that's when I start counting
 * because that's when it really counts". That's what makes you a
 * champion. And that's the way it is with everything.
 * ~ Arnold Schwarzenegger
**/

/**
   Amazing question demonstrating use of BFS and DFS approach to find
   if graph is BiPartite.
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

class Triplet {
public:
   int left;
   int right;
   int velocity;
};

bool bipartite_bfs(vector<vector<int>> graph, vector<int>& color, int cur) {
   queue<int> q;
   q.push(cur);

   while (!q.empty()) {
      // Remove
      // Mark*
      // Work
      // Add*

      int rem = q.front();
      q.pop();

      for (auto nbr : graph[rem]) {
         if (color[nbr] == 0) {
            color[nbr] = 3 - color[rem];
            q.push(nbr);
         } else if (color[nbr] == color[rem])
            return false;
      }
   }

   return true;
}

bool bipartite_dfs(vector<vector<int>> graph, vector<int>& color, int cur) {
   for (auto nbr : graph[cur]) {
      if (color[nbr] == 0) {
         color[nbr] = 3 - color[cur];

         bool sub_bipartite = bipartite_dfs(graph, color, nbr);
         if (!sub_bipartite)
            return false;
      } else if (color[nbr] == color[cur])
         return false;
   }
   return true;
}


int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);

   freopen("output.txt", "w", stdout);
#endif

   int t = 1;
   cin >> t;
   while (t--) {
      int vertices;
      cin >> vertices;

      vector<Triplet> arr;
      vector<vector<int>> graph(vertices);

      for (int i = 0; i < vertices; i++) {
         int l, r, v;
         cin >> l >> r >> v;
         arr.push_back({l, r, v});
      }

      for (int i = 0; i < vertices - 1; i++) {
         for (int j = i + 1; j < vertices; j++) {
            if (arr[i].velocity == arr[j].velocity && (arr[i].left <= arr[j].right && arr[i].right >= arr[j].left)) {
               graph[i].push_back(j);
               graph[j].push_back(i);
            }
         }
      }

      int ans = true;

      vector<int> color(vertices);

      for (int i = 0; i < vertices; i++) {
         if (color[i] == 0) {
            color[i] = 1;
            ans = ans && bipartite_dfs(graph, color, i);
         }
      }

      ans ? cout << "YES\n" : cout << "NO\n";
   }
}