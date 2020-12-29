class Solution {
public:
  int minKnightMoves(int x, int y) {

    queue<vector<int>> q;
    q.push({0, 0, 0});
    set<pair<int, int>> visited;

    vector<vector<int>> directions =
    {{2, 1}, {2, -1}, { -2, 1}, { -2, -1}, { -1, 2}, {1, 2}, {1, -2}, { -1, -2}};

    visited.insert({0, 0});

    x = abs(x);
    y = abs(y);
    while (!q.empty())
    {
      vector<int> curr = q.front();
      q.pop();

      int xVal = curr[0];
      int yVal = curr[1];
      int dist = curr[2];

      if (x == xVal && yVal == y)
        return dist;

      if (xVal < -2 || yVal < -2) continue;
      if (xVal > x + 2 || yVal > y + 2) continue;

      for (int k = 0; k < directions.size(); k++)
      {
        int newXVal = xVal + directions[k][0];
        int newYVal = yVal + directions[k][1];

        if (visited.find({newXVal, newYVal}) == visited.end())
        {
          visited.insert({newXVal, newYVal});
          q.push({newXVal, newYVal, dist + 1});
        }
      }
    }
    return 0;
  }
};