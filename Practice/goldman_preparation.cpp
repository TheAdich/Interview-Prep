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

template <class InputIterator>
void print(InputIterator start, InputIterator end)
{
   for (auto itr = start; itr != end; ++itr)
   {
      cout << *itr << " ";
   }
   cout << endl;
}


void input1DVector(vi &v)
{
   int n;
   cin >> n;

   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      v.push_back(x);
   }
}

void inputArray(int arr[], int n)
{
   for (int i = 0; i < n; i++)
      cin >> arr[i];
}

double median(int arr[], int n)
{
   if (n % 2 == 0)
      return (arr[n / 2] + arr[n / 2 - 1]) / 2;
   else
      return arr[n / 2];
}

double medianArrays(int a[], int b[], int n)
{
   if (n <= 0)
      return -1;

   if ( n == 1)
      return (a[0] + b[0]) / 2.0;

   if (n == 2)
   {
      // 5 7
      // 4 8
      // 4 5 7 8 -> ( 5 + 7 ) / 2
      int elem1 = std::min(a[0], b[0]);
      int elem2_3 = std::max(a[0], b[0]);
      int elem3_2 = std::min(a[1], b[1]);
      int elem4 = std::max(a[1], b[1]);

      return (elem2_3 + elem3_2) / 2.0;
   }

   //     0 1  2 3 4 5
   // [6] 1 8 {9 2} 6 4
   // [5] 8 9  {2}  6 4

   int mid = n / 2;
   int m1 = median(a, n);
   int m2 = median(b, n);

   if (m1 == m2)
      return m1;

   if (m1 < m2)
   {
      if (n % 2 == 0)
         return medianArrays(a + n / 2 - 1,
                             b, n - n / 2 + 1);
      return medianArrays(a + n / 2,
                          b, n - n / 2);
   }

   if (n % 2 == 0)
      return medianArrays(b + n / 2 - 1,
                          a, n - n / 2 + 1);
   return medianArrays(b + n / 2,
                       a, n - n / 2);
}

pair<int, int> find_max_min(int *arr, int i, int j)
{
   if (i == j)
      return make_pair(arr[i], arr[j]);

   else if (i == j - 1)
      return make_pair(std::max(arr[i], arr[j]), std::min(arr[i], arr[j]));

   else
   {
      int mid = (i + j) / 2;

      pair<int, int> p1 = find_max_min(arr, i, mid);
      pair<int, int> p2 = find_max_min(arr, mid + 1, j);

      int max = std::max(p1.first, p2.first);
      int min = std::min(p1.second, p2.second);

      return make_pair(max, min);
   }
}

int power(int n, int p)
{
   if (p == 1)
      return n;

   else
   {
      int a = power(n, p / 2);
      if (p % 2 != 0) // ODD
         return n * a * a;
      else return a * a;
   }
}

bool compare(pii a, pii b)
{
   return a.first / a.second > b.first / b.second;
}

double knapsack_greedy(pii p[], int n, int m)
{
   sort(p, p + n, compare);

   double max_prof = 0;
   int wt_left = m;

   int i = 0;

   while (true)
   {
      if (wt_left - p[i].se > 0)
      {
         wt_left -= p[i].se;
         max_prof += p[i].fi;
         ++i;
      }
      else
         break;
   }

   max_prof += (p[i].fi * wt_left) / (double)p[i].se;

   return max_prof;
}

void dec(int n)
{
   if (n == 1)
   {
      cout << 1 << endl;
      return;
   }

   cout << n << endl;
   dec(n - 1);

}

bool sorted(int arr[], int n)
{
   if (n == 1)
      return 1;

   if (arr[n] > arr[n - 1])
      return sorted(arr, n - 1);
   else
      return 0;
}

int firstOcc(int arr[], int n, int key)
{
   if (n == 0)
      return -1;

   if (arr[0] == key)
      return 0;

   int i = firstOcc(arr + 1, n - 1, key);
   if (i == -1)
      return -1;

   return i + 1;
}

void matrix_dp(vector<vector<int>> &v, int n)
{
   //2D Table
   int arr[n][n];

   //Initialise previous
   int prev = v[0][0];

   //Set table [0][0]
   arr[0][0] = v[0][0];

   //Set first ROW
   for (int i = 1; i < n; i++)
   {
      prev *= v[0][i];
      arr[0][i] = prev;
   }

   // print(arr[0], arr[0] + n);

   prev = v[0][0];
   //Set first COLUMN
   for (int i = 1; i < n; i++)
   {
      prev *= v[i][0];
      arr[i][0] = prev;
   }

   //Start filling from Second ROW and COLUMN
   for (int i = 1; i < n; i++)
   {
      for (int j = 1; j < n; j++)
      {
         //Come from TOP
         int top, left;
         top = left = 1;

         top = v[i][j] * arr[i - 1][j];

         //Come from LEFT
         left = v[i][j] * arr[i][j - 1];

         arr[i][j] = std::max(top, left);
      }
   }

   cout << "\nPRINTING\n";
   for (int i = 0; i < n; i++)
   {
      print(arr[i], arr[i] + n);
   }
}

bool isvalid(int i, int j, int n)
{
   return (i >= 0 && i < n && j >= 0 && j < n);
}


int mat(vector<vector<int>> &v, int i, int j, int n)
{
   if (i == n - 1 && j == n - 1)
      return v[i][j];

   else
   {
      int right, down;
      right = down = 1;

      if (isvalid(i, j + 1, n))
         right = v[i][j] * mat(v, i, j + 1, n);

      if (isvalid(i + 1, j, n))
         down = v[i][j] * mat(v, i + 1, j, n);

      return std::max(right, down);
   }
}

int matrixProduct(vector<vector<int>> &v, int r, int c)
{
   if (r == 0 && c == 0)
      return 0;

   int minCache[r][c];
   int maxCache[r][c];

   int prev = v[0][0];

   //Set table [0][0]
   minCache[0][0] = v[0][0];
   maxCache[0][0] = v[0][0];

   //Set first ROW
   for (int i = 1; i < r; i++)
   {
      prev *= v[0][i];
      minCache[0][i] = prev;
      maxCache[0][i] = prev;
   }

   // print(arr[0], arr[0] + n);

   prev = v[0][0];
   //Set first COLUMN
   for (int i = 1; i < c; i++)
   {
      prev *= v[i][0];
      minCache[i][0] = prev;
      maxCache[i][0] = prev;
   }

   for (int i = 1; i < r; i++)
   {
      for (int j = 1; j < c; j++)
      {
         int maxVal = INT_MIN;
         int minVal = INT_MAX;
         //From TOP
         int tempMaxTop = std::max(v[i][j] * maxCache[i - 1][j],
                                   v[i][j] * minCache[i - 1][j]);

         maxVal = std::max(maxVal, tempMaxTop);

         int tempMinTop = std::min(v[i][j] * maxCache[i - 1][j],
                                   v[i][j] * minCache[i - 1][j]);
         minVal = std::max(minVal, tempMinTop);

         //From LEFT
         int tempMaxLeft = std::max(v[i][j] * maxCache[i][j - 1],
                                    v[i][j] * minCache[i][j - 1]);

         maxVal = std::max(maxVal, tempMaxLeft);

         int tempMinLeft = std::min(v[i][j] * maxCache[i][j - 1],
                                    v[i][j] * minCache[i][j - 1]);

         minVal = std::min(minVal, tempMinLeft);

         minCache[i][j] = minVal;
         maxCache[i][j] = maxVal;
      }
   }

   for (int i = 0; i < r; i++)
   {
      print(maxCache[i], maxCache[i] + c);
   }

   return 1;

}

vi find_duplicates(vi v, int n)
{
   vi list;
   for (int i = 0; i < n; i++)
   {
      int elem = v[i];
      //If present element is positive
      //Go to the corresponding index and flip it
      if (v[abs(elem) - 1] >= 0)
      {
         v[abs(elem) - 1] = -v[abs(elem) - 1];
      }
      else list.push_back(abs(elem));
   }

   return list;
}

/**
   [ 4, 2, 1, 6, 5 ]
     ^
**/

int findLongestConseqSubseq(int arr[], int n)
{
   unordered_set<int> set;

   for (int i = 0; i < n; i++)
      set.insert(arr[i]);

   int max = INT_MIN;

   //Iterate through all the elements of set
   //We don't care about duplicates
   for (auto i : set)
   {
      //If previous of the current element exist
      // continue;
      //As consecutive array starts from it
      if (set.find(i - 1) != set.end())
         continue;

      int length = 0;
      int j = i;
      //If next element exist
      //Keep incrementing length
      while (set.find(j++) != set.end())
         ++length;

      max = std::max(max, length);
   }

   return max;
}

void setRowCol(vector<vector<int>> &v, int r, int c, int p, int q)
{
   //Set Row True
   for (int i = 0; i < r; i++)
      v[p][i] = 1;

   //Set Column True
   for (int i = 0; i < c; i++)
      v[i][q] = 1;
}

void zeroMatrix(vector<vector<bool>> &matrix, int r, int c)
{
   // Verify the input array is nonzero
   if (r == 0 || c == 0) return;

   // Determine whether the first row or first column is true
   bool rowZero = false, colZero = false;
   for (bool i : matrix[0]) {
      rowZero |= i;
   }
   for (int i = 0; i < c; i++) {
      colZero |= matrix[0][i];
   }

   // For each cell not in the first row/column, if it is true, set the
   // cell in the first row/same column and first column/same row to be
   // true
   for (int i = 1; i < r; i++) {
      for (int j = 1; j < c; j++) {
         if (matrix[i][j]) {
            matrix[i][0] = true;
            matrix[0][j] = true;
         }
      }
   }

   // Go through the first column and set each row to true where cell in
   // the first column is true
   for (int i = 1; i < r; i++) {
      if (matrix[i][0]) {
         for (int j = 1; j < c; j++) {
            matrix[i][j] = true;
         }
      }
   }

   // Repeat for the rows
   for (int j = 1; j < c; j++) {
      if (matrix[0][j]) {
         for (int i = 1; i < r; i++) {
            matrix[i][j] = true;
         }
      }
   }

   // Set first row/column to true if necessary
   if (rowZero) {
      for (int i = 0; i < c; i++) {
         matrix[0][i] = true;
      }
   }

   if (colZero) {
      for (int i = 0; i < r; i++) {
         matrix[i][0] = true;
      }
   }
}

int squareSubMatrix(vector<vector<int>> &v, int r, int c)
{
   int arr[r][c];

   //Set First ROW
   for (int i = 0; i < r; i++)
      arr[0][i] = v[0][i];

   //Set First COLUMN
   for (int i = 0; i < c; i++)
      arr[i][0] = v[i][0];

   int max = INT_MIN;

   for (int i = 1; i < r; i++)
   {
      for (int j = 1; j < c; j++)
      {
         int topElement = arr[i - 1][j];
         int leftElement = arr[i][j - 1];
         int upperLeftElement = arr[i - 1][j - 1];

         if (v[i][j] == 1)
            arr[i][j] = std::min(topElement, std::min(leftElement, upperLeftElement)) + 1;
         else
            arr[i][j] = 0;

         max = std::max(max, arr[i][j]);
      }
   }

   for (int i = 0; i < r; i++)
      print(arr[i], arr[i] + c);

   return max;
}

bool matrixSearch(vector<vector<int>> &v, int r, int c, int key)
{
   for (int i = 0; i < r; i++)
   {
      if (v[i][0] <= key && v[i][c - 1] >= key) //Last element
         return binary_search(v[i].begin(), v[i].end(), key);

   }

   return false;
}

bool matrixSearchOptimised(vector<vector<int>> &v, int r, int c, int key)
{
   int row = 0;
   int col = c - 1;

   while (row < r && c >= 0)
   {
      if (v[row][col] == key) return true;
      if (v[row][col] < key) ++row; //Go to next row
      else --col;
   }

   return false;
}

bool isValid(int keepTrack[], int n, int k)
{
   for (int i = 0; i < k; i++)
      if (keepTrack[i] >= n)
         return false;
   return true;
}

class Compare {
public:
   bool operator()(pii A, pii B) {
      return A.first > B.first;
   }
};

bool fun(pii A, pii B) {
   return A.first > B.first;
}

pii getMin(vector<vector<int>> &v, int keepTrack[], int n, int k)
{
   int min = INT_MAX;
   int minIndex = -1;

   for (int i = 0; i < k; i++)
   {
      if (v[i][keepTrack[i]] < min)
      {
         min = v[i][keepTrack[i]];
         minIndex = i;
      }
   }
   return make_pair(min, minIndex);

}

/**
Given matrix
          [1, 4, 7]
           ^
          [2, 5, 8]
           ^
          [3, 6, 9]
           ^
**/

class Compare {
public:
   bool operator()(pii A, pii B) {
      return A.first > B.first;
   }
};

vi mergeKSorted(vector<vector<int>> &v, int n, int k)
{
   //Node.first -> Element
   //Node.second -> Which Row?

   //Priority Queue where a node is a pair of element
   priority_queue<pii, vector<pii>, Compare> minHeap;

   for (int i = 0; i < k; i++)
      minHeap.push(make_pair (v[i][0], i) );

   // [0, 0, 0]
   //Corresponding to each rows
   int keepTrack[k];

   for (int i = 0; i < k; i++)
      keepTrack[i] = 0;

   //ans: Merged sorted array
   vi ans;

   // While
   // There exists element in row k
   while (isValid(keepTrack, n, k))
   {
      /**
       1st Iteration

            (1,0)
            /   \
       (2,1)     (3,2)

       2nd Iteration
      **/
      auto minNode = minHeap.top();
      minHeap.pop();

      /**
      1st Iteration
      ans: 1
      **/
      ans.push_back(minNode.fi);

      //[1,0,0]
      ++keepTrack[minNode.se];

      /**
      Current matrix state
                [1, 4, 7]
                    ^
                [2, 5, 8]
                 ^
                [3, 6, 9]
                 ^
                 We push (4,0) to minHeap
      **/
      if (keepTrack[minNode.se] < n)
         minHeap.push(make_pair(v[minNode.se][keepTrack[minNode.se]],
                                minNode.se
                               ));
      // cout << "Pushing: " << "(" << v[minNode.se][keepTrack[minNode.se]]
      //      << ", " << minNode.se << "), \n";
   }
   // cout << ans;

   for (int i = 0; i < k; i++)
   {
      // i-> Row
      // keepTrack[i] -> column
      ++keepTrack[i];
      for (int j = keepTrack[i]; j < n; j++)
         minHeap.push(make_pair (v[i][j], i));
   }

   while (!minHeap.empty())
   {
      ans.push_back(minHeap.top().fi);
      minHeap.pop();
   }

   return ans;
}

int kthSmallest(vector<vector<int>> &v, int row, int col, int k)
{
   priority_queue<int, vector<int>, greater<int>> minHeap;

   int colTrav = 0;

   if (k <= row)
      colTrav = 1;

   else
      colTrav = ceil((double)k / row);

   for (int i = 0; i < row; i++)
      for (int j = 0; j < colTrav; j++)
         minHeap.push(v[i][j]);

   while (k != 1)
   {
      // cout << minHeap.top() << "\n";
      minHeap.pop();
      --k;
   }

   return minHeap.top();
}

struct HeapNode {
   int val;  // value to be stored
   int r;    // Row number of value in 2D array
   int c;    // Column number of value in 2D array
};

struct HeapNodeCompare {
   bool operator()(HeapNode A, HeapNode B) {
      return A.val > B.val;
   }
};

int kthSmallestUpdated(vector<vector<int>> &v, int n, int k)
{
   if (k <= 0 || k > n * n)
      return INT_MAX;

   priority_queue<HeapNode, vector<HeapNode>, HeapNodeCompare> minHeap;

   for (int i = 0; i < n; i++)
      minHeap.push({v[0][i], 0, i});

   HeapNode h;
   for (int i = 0; i < k; i++)
   {
      h = minHeap.top();
      minHeap.pop();

      int nextval = (h.r < (n - 1)) ? v[h.r + 1][h.c] : INT_MAX;

      deb(nextval);

      minHeap.push({nextval, (h.r) + 1, h.c});
   }

   return h.val;
}

struct triplet {
   int element;
   int i;
   int j;

   triplet(int element, int i, int j)
   {
      this->element = element;
      this->i = i;
      this->j = j;
   }
};

struct tripletCompare {
   bool operator()(triplet A, triplet B) {
      return A.element > B.element;
   }
};

vi zero_sum_subarray(vi v, int n)
{
   map<int, int> m;

   vi ans;

   int sum = 0;
   int repeatSum = 0;

   int lastIndex = 0;

   for (int i = 0; i < n; i++)
   {
      sum = sum + v[i];
      //If current sum does not exist in map
      //It means it's new.
      //Add to map
      if (m.find(sum) == m.end())
         m[sum] = i;
      else
      {
         lastIndex = i;
         repeatSum = sum;
         break;
      }
   }

   for (int i = m[repeatSum] + 1; i < lastIndex + 1; i++)
      ans.push_back(v[i]);

   return ans;
}

string spell[10] = {"Zero",
                    "One",
                    "Two",
                    "Three",
                    "Four",
                    "Five",
                    "Six",
                    "Seven",
                    "Eight",
                    "Nine"
                   };

void spelling(int n)
{
   if (n == 0)
      return;

   else
   {
      //Reach First charachter
      spelling(n / 10);
      cout << spell[n % 10] << " ";
   }
}

/**
      char arr[] = "4329";
      cout << digitize(arr, 4);
**/
int digitize(char s[], int n)
{
   if (n == 0)
      return 0;

   //Reach string end
   int smallans = digitize(s, n - 1);

   //Extract last digit
   int digit = s[n - 1] - '0';

   return smallans * 10 + digit;
}

void pipi(char arr[], vector<char> &out)
{
   if (arr[0] == '\0')
      return;

   //If you see pi
   if (arr[1] != '\0')
   {
      if (arr[0] == 'p' && arr[1] == 'i')
      {
         out.push_back('3');
         out.push_back('.');
         out.push_back('1');
         out.push_back('4');

         pipi(arr + 2, out);
      }
      else
      {
         out.push_back(arr[0]);
         pipi(arr + 1, out);
      }
   }
   else
   {
      out.push_back(arr[0]);
      return;
   }

}

// 4 x N Wall
int placeTiles(int n)
{
   if (n <= 0)
      return 0;

   if (n == 1 || n == 2 || n == 3)
      return 1;

   if (n == 4)
      return 2;

   return placeTiles(n - 1) + placeTiles(n - 4);
}

int binStringRecursion(int n)
{
   if (n == 1)
      return 1;

   if (n == 2)
      return 3;

   return binStringRecursion(n - 1) + binStringRecursion(n - 2);
}

/**
                  "abc", ""
                  /              \
            "bc",""            "bc","a"
            /     \            /       \
      "c",""    "c","a"    "",""     "", ""
**/
void subseqGeneration(string str, string output)
{
   if (str.length() == 0)
   {
      cout << output << endl;
      return;
   }

   subseqGeneration(str.substr(1), output);
   subseqGeneration(str.substr(1), output + str[0]);
}

int modBS(int arr[], int l, int r)
{
   if (r >= l)
   {
      int mid = (l + r) / 2;

      //Perfect case
      if (arr[mid] == 1 && arr[mid - 1] == 0)
         return mid;

      // 0 0 0 0 1 1 1 1 1 1
      //             ^
      // Go LEFT
      else if (arr[mid] == 1 && arr[mid - 1] == 1)
         return modBS(arr, l, mid);

      // 0 0 0 0 1 1 1 1 1 1
      //     ^
      // Go Right
      else
         return modBS(arr, mid + 1, r);
   }

   return -1;
}

void bracket(vector<char> out, int n, int open, int close)
{
   if (out.size() == 2 * n)
   {
      cout << out << endl;
      return;
   }

   if (open < n)
   {
      out.push_back('(');
      bracket(out, n, open + 1, close);
   }

   if (close < open)
   {
      out.push_back(')');
      bracket(out, n, open, close + 1);
   }

   return;
}

char keypadArray[][10] = {"", "",
                          "ABC", "DEF",
                          "GHI", "JKL", "MNO",
                          "PQRS", "TUV", "WXYZ"
                         };

void keypad(char input[], char out[], int i, int j)
{
   if (input[i] == '\0') {
      out[j] = '\0';
      cout << out << endl;
      return;
   }

   int digit = input[i] - '0';
   if (digit == 1 || digit == 0)
      keypad(input, out, i + 1, j);

   for (int k = 0; keypadArray[digit][k] != '\0' ; k++) {
      out[j] = keypadArray[digit][k];
      keypad(input, out, i + 1, j + 1);
   }

   return;
}

string swapIndices(string str, int a, int b)
{
   char temp = str[b];
   str[b] = str[a];
   str[a] = temp;

   return str;
}

void permutation(string input, string output = "")
{
   if (input.length() <= 0)
   {
      cout << output << endl;
      return;
   }

   long int len = input.length();

   for (int k = 0 ; k < len ; k++)
   {
      permutation(swapIndices(input, 0, k).substr(1), output + input[k]);
   }
}

void anagramsChutiya(string in, string in2, int i)
{
   //Base Case
   if (in[i] == '\0')
   {
      if (in == in2)
         cout << in << " and " << in2 << " are Anagrams";
      return;
   }

   for (int j = i; in[j] != '\0'; j++)
   {
      //Replace i th charachter with j th
      // a b c
      // ^   ^
      // i   j

      swap(in[i], in[j]);
      anagramsChutiya(in, in2, i + 1);
      swap(in[i], in[j]);
   }
}

void buildOrderHelper(int i, vector<vector<int>> v, map<int, int> &visited, vector<int>& ans)
{
   visited[i] = 1;

   for (auto j : v[i])
   {
      if (visited[j] == 2) continue;

      if (visited[j] == 0)
      {
         visited[j] = 1;
         buildOrderHelper(j, v, visited, ans);
      }
   }

   visited[i] = 2;
   ans.push_back(i);
}

void buildOrder(vector<vector<int>> v, int row)
{
   // 1 -> Temp
   // 2 -> Permanent
   map<int, int> visited;
   vector<int> ans;

   for (int i = 0; i < row; i++)
      visited[i] = 0;

   for (int i = 0; i < row; i++)
      if (visited[i] != 2)
         buildOrderHelper(i, v, visited, ans);

   cout << ans;
}

class Person {
public:
   float age;
   string name;
};

class PersonCompare {
public:
   bool operator()(Person A, Person B) const {
      return A.age > B.age;
   }
};

void joinRopes(int ropes[], int n)
{
   priority_queue<int, vi, greater<int>> minHeap;

   for (int i = 0; i < n; i++)
      minHeap.push(ropes[i]);

   int cost = 0;

   while (minHeap.size() > 1)
   {
      int A = minHeap.top();
      minHeap.pop();

      int B = minHeap.top();
      minHeap.pop();

      int newRope = A + B;
      cost += newRope;

      minHeap.push(newRope);
   }

   cout << cost;
}

static bool compare3(vector<int> A, vector<int> B)
{
   return abs(A[0] + A[1]) < abs(B[0] + B[1]);
}

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
{
   int n = nums1.size();

   vector<vector<int>> arr;

   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
      {
         vector<int> temp;
         temp.push_back(nums1[i]);
         temp.push_back(nums2[j]);
         arr.push_back(temp);
      }

   sort(arr.begin(), arr.end(), compare3);

   for (int i = 0; i < arr.size(); i++)
      cout << arr[i] << endl;

   vector<vector<int>> subvector;
   copy ( arr.begin() , arr.begin() + k, std::back_inserter(subvector) );

   return subvector;
}

/**
   int price[] = { 100, 180, 260, 310, 40, 535, 695 };
   int n = sizeof(price) / sizeof(price[0]);

   cout << maxProfit(price, 0, n - 1);

   return 0;
**/

int stock_buy_sell_max_profit(vector<int>& v)
{
   int n = v.size();
   if (n == 1)
      return 0;

   vector<pair<int, int>> ans;

   for (int i = 0; i < n - 1; i++)
   {
      //Local Minima
      while ((i < n - 1) && (v[i + 1] <= v[i]))
         ++i;

      if (i == n - 1)
         break;

      int buy = i++;

      while ((i < n) && (v[i] >= v[i - 1]))
         ++i;

      int sell = --i;

      ans.push_back(make_pair(buy, sell));
   }

   int profit = 0;

   if (ans.empty())
      cout << "No Profit";
   else
      for (auto i : ans)
      {
         cout << "(" << i.fi << " " << i.se << ") ";

         profit += v[i.se] - v[i.fi];
      }
   return profit;
}

vector<int> largest_sum_contiguous_subarray(vector<int>& arr)
{
   int max_so_far = INT_MIN, sum = 0,
       start = 0, end = 0, s = 0;

   int n = arr.size();

   for (int i = 0; i < n; i++ )
   {
      sum += arr[i];

      if (max_so_far < sum)
      {
         max_so_far = sum;
         start = s;
         end = i;
      }

      if (sum < 0)
      {
         sum = 0;
         s = i + 1;
      }
   }

   vector<int> ans;

   for (int i = start; i <= end; i++)
      ans.push_back(arr[i]);

   return ans;
}

/**
               DEQUE

**/

/**
   vi v = {4, 3, 1, 2, 5, 3, 4, 7, 1, 9};
   int n = v.size();
   cout << maximum_sliding_window(v, 3);
**/
vector<int> maximum_sliding_window(vector<int>& v, int k)
{
   int n = v.size();

   deque<int> Q;

   vector<int> ans;

   //Initialise
   for (int i = 0 ; i < k ; i++)
   {
      while (!Q.empty() && v[i] >= v[Q.back()])
         Q.pop_back();
      Q.push_back(i);
   }

   for (int i = k ; i < n; i++)
   {
      ans.push_back(v[Q.front()]);

      if (Q.front() < i - k + 1)
         Q.pop_front();

      while (!Q.empty() && v[i] >= v[Q.back()])
         Q.pop_back();

      Q.push_back(i);
   }

   ans.push_back(v[Q.front()]);

   return ans;
}

/**
   Input: "abcabcbb"
   Output: 3
   Explanation: The answer is "abc", with the length of 3.
**/

int lengthOfLongestSubstring(string s)
{
   int n = s.length();

   if (n == 0 || n == 1)
      return n;

   int alpha[256];

   for (int i = 0; i < 256; i++)
      alpha[i] = 0;

   deque<char> Q;

   int max = INT_MIN;

   for (int i = 0; i < n; i++)
   {
      if (alpha[s[i]] == 1)
      {
         while (Q.front() != s[i])
         {
            alpha[Q.front()] = 0;
            Q.pop_front();
         }
         alpha[Q.front()] = 0;
         Q.pop_front();
      }

      alpha[s[i]] = 1;
      Q.push_back(s[i]);
      int size = Q.size();
      max = std::max(max, size);
   }

   return max;
}

int go(vector<int>& v)
{
   int n = v.size();

   int max_negative = INT_MAX;
   int flag = 0;
   int sum = 0;
   for (int i = 0; i < n; i++)
   {
      sum += v[i];
      if (sum <= 0)
      {
         flag = 1;
         max_negative = std::min(max_negative, sum);
      }
   }
   if (flag == 0)
      return 1;
   return abs(max_negative) + 1;
}

struct Ad {
   int x1;
   int x2;
   int val;
};

string compress(string s)
{
   int n = s.length(), i = n - 1;
   string ans;

   for (; i >= 0;) {
      if (i % 2 == 0 && s.substr(0, i / 2) == s.substr(i / 2, i / 2)) {
         ans += s[i];
         i = i / 2 - 1;
         continue;
      }
      break;
   }
   reverse(ans.begin(), ans.end());

   ans = s.substr(0, i + 1) + ans;
   return ans;
}

// 00000000001111111111
int binary_search10(vector<int> arr)
{
   int l = 0;
   int r = arr.size() - 1;

   while (l <= r)
   {
      int m = (l + r) / 2;

      if (l == r && arr[l] == 1)
         return l;

      if (arr[m] == 1 && arr[m - 1] == 0)
         return m;

      if (arr[m] == 0) //Go Right
         l = m + 1;

      else
         r = m - 1;
   }

   return -1;
}

bool isValidIndex(int r, int c, int i, int j)
{
   if (i >= 0 && i <= r - 1 && j >= 0 && j <= c - 1)
      return true;
   return false;
}

int gs(vector<vector<int>> v, int r, int c)
{
   int ans = 0;

   int rows[] = { -1, -1, 0, +1, +1, +1, 0, -1};
   int col[] =  {0, +1, +1, +1, 0, -1, -1, -1};

   int h = sizeof(rows) / sizeof(int);

   for (int i = 0; i < r; i++)
   {
      for (int j = 0; j < c; j++)
      {
         if (v[i][j] == 0)
            continue;
         else
            for (int k = 0; k < h; k++)
            {
               if (isValidIndex(r, c, i + rows[k], j + col[k]) &&
                     v[i + rows[k]][j + col[k]] == 1)
                  ans += 1;
            }
      }
   }

   return ans / 2;
}

int gs2(vector<vector<int>> v, int r, int c)
{
   set<int> set;

   for (int i = 0; i < r; i++)
   {
      int min = INT_MAX;
      int max = INT_MIN;
      for (int j = 0; j < c; j++)
      {
         min = std::min(min, v[i][j]);
         max = std::max(max, v[i][j]);
      }

      set.insert(min);
      set.insert(max);
   }

   for (int i = 0; i < c; i++)
   {
      int min = INT_MAX;
      int max = INT_MIN;
      for (int j = 0; j < r; j++)
      {
         min = std::min(min, v[j][i]);
         max = std::max(max, v[j][i]);
      }

      set.insert(min);
      set.insert(max);
   }

   for (auto i : set)
      cout << i << " ";
   cout << endl;
   return set.size();
}

/**
   [23, 2, 3, 12,  2, 2, 34, 55, 66, 79]

   2 Occurances = 3

   [23, 2, 3, 12,  2, 2, 34, _, _, _]

   [23, 2, 2, 3, 12, 2, 2, 2, 2, 34]

**/

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);

   freopen("output.txt", "w", stdout);
#endif

   int t = 1;
   while (t--) {

      int arr[] = {4, 2, 1, 6, 5};
      int n = sizeof(arr) / sizeof(int);
      cout << findLongestConseqSubseq(arr, n);

   }

}