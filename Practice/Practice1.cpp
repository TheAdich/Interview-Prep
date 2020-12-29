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

int binarySearch(vector<int> arr, int l, int r, int x)
{
  if (r >= l) {
    int mid = l + (r - l) / 2;

    // If the element is present at the middle
    // itself
    if (arr[mid] == x)
      return mid;

    // If element is smaller than mid, then
    // it can only be present in left subarray
    if (arr[mid] > x)
      return binarySearch(arr, l, mid - 1, x);

    // Else the element can only be present
    // in right subarray
    return binarySearch(arr, mid + 1, r, x);
  }

  // We reach here when element is not
  // present in array
  return -1;
}

vector<vector<int>> four_sum_ineff(vector<int> &arr, int target)
{
  int n = arr.size();

  vector<int> ans(4);

  set<vector<int>> set;

  sort(arr.begin(), arr.end());

  for (int i = 0; i < n - 3; i++)
  {
    for (int j = i + 1; j < n - 2; j++)
    {
      for (int k = j + 1; k < n - 1; k++)
      {
        int sum = arr[i] + arr[j] + arr[k];
        int reqd = target - sum;

        int lb = binarySearch(arr, k + 1, n - 1, reqd);

        if (lb == -1)
          continue;
        else
        {
          ans[0] = arr[i];
          ans[1] = arr[j];
          ans[2] = arr[k];
          ans[3] = arr[lb];
          // deb(i);
          // deb(j);
          // deb(k);
          // deb(lb);

          // cout << "ans: " << ans << endl;
          set.insert(ans);
        }
      }
    }
  }

  vector<vector<int>> result;

  for (auto i : set)
    result.push_back(i);

  // for (auto i : result)
  //   cout << i << endl;

  return result;
}

vector<vector<int>> four_sum(vector<int> &arr, int target)
{
  int n = arr.size();

  vector<int> ans(4);
  vector<vector<int>> result;

  sort(arr.begin(), arr.end());

  for (int i = 0; i < n - 3;)
  {
    int cur_i = arr[i];

    for (int j = i + 1; j < n - 2;)
    {
      int cur_j = arr[j];

      int left = j + 1;
      int right = n - 1;

      int sum = arr[i] + arr[j];
      int reqd = target - sum;

      int cur_left = 0;
      int cur_right = 0;

      while (left < right)
      {
        cur_left = arr[left];
        cur_right = arr[right];

        if (arr[left] + arr[right] == reqd)
        {
          ans[0] = arr[i];
          ans[1] = arr[j];
          ans[2] = arr[left];
          ans[3] = arr[right];

          cur_left = arr[left];
          cur_right = arr[right];

          while (arr[left] == cur_left)
            ++left;
          while (arr[right] == cur_right)
            --right;
          result.push_back(ans);
        }

        else if (arr[left] + arr[right] < reqd)
        {
          while (arr[left] == cur_left)
            ++left;
        }
        else
        {
          while (arr[right] == cur_right)
            --right;
        }
      }

      ++j;
      while (arr[j] == cur_j)
        ++j;
    }

    ++i;
    while (arr[i] == cur_i)
      ++i;
  }

  for (auto i : result)
    cout << i << endl;

  return result;
}

static bool compare(pair<int, int> A, pair<int, int> B)
{
  return A.first < B.first;
}

vector<int> two_sum(vector<int>& arr, int target)
{
  int n = arr.size();

  vector<pair<int, int>> v;

  for (int i = 0; i < n; i++)
    v.push_back(make_pair(arr[i], i));

  sort(v.begin(), v.end(), compare);

  int left = 0;
  int right = n - 1;

  while (left < right)
  {
    if (v[left].first + v[right].first == target)
      return {v[left].second, v[right].second};
    else if (v[left].first + v[right].first <= target)
      ++left;
    else
      --right;
  }

  return { -1, -1};
}

bool is_anagrams(string s1, string s2)
{
  int n1 = s1.length();
  int n2 = s2.length();

  if (n1 != n2)
    return false;

  map<char, int> m;

  for (int i = 0; i < n1; i++)
    ++m[s1[i]];

  for (int i = 0; i < n2; i++)
    --m[s2[i]];

  for (auto i : m)
    if (i.second != 0)
      return false;

  return true;
}

vector<vector<int> > anagrams(const vector<string> &arr) {
  int n = arr.size();

  vector<vector<int>> result;

  for (int i = 0 ; i < n - 1 ; i++)
  {
    for (int j = i + 1 ; j < n ; j++)
    {
      if (is_anagrams(arr[i], arr[j]))
      {
        vector<int> ans(2);
        ans[0] = i + 1;
        ans[1] = j + 1;
        result.push_back(ans);
      }
    }
  }

  for (auto i : result)
    cout << i << endl;

  return result;
}

int max_subarray_zero_sum_extra_space(vector<int> arr)
{
  int n = arr.size();

  int max = 0;
  for (int i = 0; i < n - 1; i++)
  {
    int sum = arr[i];
    if (sum == 0)
      continue;
    for (int j = i + 1; j < n; j++)
    {
      sum += arr[j];

      if (sum == 0)
        max = std::max(max, j - i + 1);
    }
  }

  return max;
}

int max_subarray_zero_sum(vector<int> arr)
{
  int n = arr.size();

  int sum = 0;

  map<int, int> m;

  int max = 0;

  for (int i = 0; i < n; i++)
  {
    sum += arr[i];

    if (sum == 0)
      max = i + 1;

    else
    {
      if (m.find(sum) == m.end())
        m[sum] = i;
      else
        max = std::max(max, i - m[sum]);
    }
  }

  return max;
}

int maximumGap(vector<int> &arr)
{
  int n = arr.size();

  vector<pair<int, int>> v;

  for (int i = 0; i < n; i++)
    v.push_back(make_pair(arr[i], i));

  sort(v.begin(), v.end(), compare);

  int min = INT_MAX;

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    min = std::min(min, v[i].second);
    ans = std::max(ans, v[i].second - min);
  }

  return ans;
}

bool compare3(vector<int> A, vector<int> B)
{
  if (A[0] < B[0])
    return true;
  else if (A[0] == B[0] && A[1] < B[1])
    return true;
  else
    return false;
}

vector<int> is_merge(vector<int> A, vector<int> B)
{
  if (A[1] >= B[0])
    return {A[0], B[1]};
  return { -1, -1};
}

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {

  int n = intervals.size();

  vector<vector<int>> result;

  sort(intervals.begin(), intervals.end());

  vector<int> temp_interval = intervals[0];

  for (int i = 0; i < n; i++)
  {
    if (intervals[i][0] <= temp_interval[1])
      temp_interval[1] = std::max(intervals[i][1], temp_interval[1]);
    else
    {
      result.push_back(temp_interval);
      temp_interval = intervals[i];
    }
  }

  result.push_back(temp_interval);

  for (auto i : result)
    cout << i << endl;

  return result;
}

int join_ropes(vector<int> arr)
{
  int n = arr.size();

  if (n == 0 || n == 1)
    return 0;

  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < n; i++)
    pq.push(arr[i]);

  int cost = 0;

  while (pq.size() > 1)
  {
    int A = pq.top();
    pq.pop();

    int B = pq.top();
    pq.pop();

    int newRope = A + B;
    cost += newRope;

    pq.push(newRope);
  }

  return cost;
}

// O(N^2 Log N)
vector<float> running_median_ineff(vector<float> arr)
{
  int n = arr.size();

  int index = 0;
  vector<float> ans;

  for (int i = 0; i < n; i++)
  {
    sort(arr.begin(), arr.begin() + i + 1);

    cout << i << ". ";
    vector<float>::iterator ptr;
    for (ptr = arr.begin(); ptr < arr.begin() + i + 1; ptr++)
      cout << *ptr << " ";

    cout << endl;
    // If length is odd
    // This means Index is even
    if (i % 2 == 0)
      ans.push_back(arr[index]);
    else
    {
      float x = (arr[index] + arr[index + 1]) / 2;
      ans.push_back(x);
      ++index;
    }
  }

  return ans;
}

vector<float> running_median(vector<float> arr)
{
  int n = arr.size();

  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

  vector<float> result;

  for (int i = 0; i < n; i++)
  {
    int a = arr[i];

    if (maxHeap.empty() || maxHeap.top() > a)
      maxHeap.push(a);
    else
      minHeap.push(a);

    if (maxHeap.size() > minHeap.size() + 1)
    {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    }
    else if (minHeap.size() > maxHeap.size() + 1)
    {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }

    if (maxHeap.size() == minHeap.size())
      result.push_back((minHeap.top() + maxHeap.top()) / 2.0 );
    else if
    (minHeap.size() > maxHeap.size()) result.push_back(minHeap.top());
    else
      result.push_back(maxHeap.top());
  }

  return result;
}



int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);

  freopen("output.txt", "w", stdout);
#endif
  //code
  // int n;
  // cin >> n;
  // priority_queue<int> maxheap;  //Lower Half
  // priority_queue<int, vector<int>, greater<int> > minHeap; //Upper Half

  // int a;

  // while (n--)
  // {
  //   cin >> a;
  //   if (maxheap.empty() || maxheap.top() > a)
  //   {
  //     maxheap.push(a);
  //   }
  //   else minheap.push(a);


  //   if (maxheap.size() > minheap.size() + 1)
  //   {
  //     minheap.push(maxheap.top());
  //     maxheap.pop();
  //   }
  //   else if (minheap.size() > maxheap.size() + 1)
  //   {
  //     maxheap.push(minheap.top());
  //     minheap.pop();
  //   }

  //   if (minheap.size() == maxheap.size()) cout << (minheap.top() + maxheap.top()) / 2 << "\n";
  //   else if (minheap.size() > maxheap.size()) cout << minheap.top() << "\n";
  //   else cout << maxheap.top() << "\n";
  // }

  // return 0;

  vector<float> v = {5, 2, 3, 1, 6};

  // cout << "Priority Queue: ";
  // cout << join_ropes(v);

  // cout << running_median_ineff(v);
  // cout << endl;
  cout << running_median(v);

  // vector<vector<int>> v;

  // for (int i = 0 ; i < n ; i++)
  // {
  //   vector<int> temp;
  //   for (int j = 0; j < 2; j++)
  //   {
  //     int x;
  //     cin >> x;
  //     temp.push_back(x);
  //   }
  //   v.push_back(temp);
  // }

  // mergeIntervals(v);

}