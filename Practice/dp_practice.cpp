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

#define PRINT printTable(dp)

void printTable(vector<vector<int>> dp)
{
	cout << "DP Table\n";
	for (int i = 0; i < dp.size(); i++)
	{
		for (int j = 0; j < dp[i].size(); j++)
			cout << setw(3) << dp[i][j] << " ";

		cout << endl;
	}
	cout << endl;
	return;
}

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

template <typename T>
ostream& operator<<(ostream& os, const pair<T, T>& p)
{
	os << "{" << p.first << ", " << p.second << "}, ";
	return os;
}

int recursive_knapsack_01(int profit[], int weight[], int cap, int n)
{
	if (cap == 0 || n == 0)
		return 0;


	if (weight[n - 1] > cap)
		return recursive_knapsack_01(profit, weight, cap, n - 1);

	else
	{
		int take_it = profit[n - 1] + recursive_knapsack_01(profit, weight, cap - weight[n - 1], n - 1);
		int leave_it = recursive_knapsack_01(profit, weight, cap, n - 1);

		return std::max(take_it, leave_it);
	}
}

int _memoised_knapsack_01(int profit[], int weight[], int cap, int n, vector<vector<int>>& dp)
{
	if (cap == 0 || n == 0)
		return dp[n][cap] = 0;

	if (dp[n][cap] != -1)
		return dp[n][cap];

	if (weight[n - 1] > cap)
		return dp[n][cap] = recursive_knapsack_01(profit, weight, cap, n - 1);
	else
	{
		int take_it = profit[n - 1] + recursive_knapsack_01(profit, weight, cap - weight[n - 1], n - 1);
		int leave_it = recursive_knapsack_01(profit, weight, cap, n - 1);

		return dp[n][cap] = std::max(take_it, leave_it);
	}
}

int memoised_knapsack_01(int profit[], int weight[], int cap, int n)
{
	vector<vector<int>> dp(n + 1, vector<int>(cap + 1, -1));
	_memoised_knapsack_01(profit, weight, cap, n, dp);

	return dp[n][cap];
}

int dp_knapsack_01(int profit[], int weight[], int cap, int n)
{
	vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));

	for (int i = 1; i < (n + 1); i++)
		for (int j = 1; j < (cap + 1); j++)
		{
			if (weight[i - 1] <= j)
				dp[i][j] = std::max(profit[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}

	return dp[n][cap];
}

int rodCutDP(int length[], int price[], int n)
{
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < n + 1; j++)
		{
			if (length[i - 1] <= j)
				dp[i][j] = std::max(price[i - 1] + dp[i][j - length[i - 1]],
				                    dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}

	return dp[n][n];
}

bool dp_subset_sum_problem(int arr[], int sum, int n)
{
	vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

	//Initialise 1st Row
	for (int i = 0; i < sum + 1; i++)
		dp[0][i] = false;

	//Initialise 1st Column
	for (int i = 0; i < n + 1; i++)
		dp[i][0] = true;

	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < sum + 1; j++)
		{
			if (arr[i - 1] <= j)
				dp[i][j] = dp[i][j - arr[i - 1]] || dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j];
		}
	PRINT;
	return dp[n][sum];
}

int recursive_LCS(string x, string y, int n, int m)
{
	if (n == 0 || m == 0)
		return 0;

	if (x[n - 1] == y[m - 1])
		return 1 + recursive_LCS(x, y, n - 1, m - 1);

	else
	{
		int op1 = recursive_LCS(x, y, n - 1, m);
		int op2 = recursive_LCS(x, y, n, m - 1);
		return std::max(op1, op2);
	}
}

int _memoised_LCS(string x, string y, int n, int m, vector<vector<int>>& dp)
{
	if (n == 0 || m == 0)
		return 0;

	if (dp[n][m] != -1)
		return dp[n][m];

	if (x[n - 1] == y[m - 1])
		return dp[n][m] = 1 + _memoised_LCS(x, y, n - 1, m - 1, dp);

	else
	{
		int op1 = _memoised_LCS(x, y, n - 1, m, dp);
		int op2 = _memoised_LCS(x, y, n, m - 1, dp);
		return dp[n][m] = std::max(op1, op2);
	}
}

int memoised_LCS(string x, string y, int n, int m)
{
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

	_memoised_LCS(x, y, n, m, dp);

	return dp[n][m];
}

int dp_LCS(string x, string y, int n, int m)
{
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < m + 1; j++)
		{
			if (x[i - 1] == y[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
		}

	string path = "";
	int i = n, j = m;
	while (i > 0 && j > 0)
	{
		if (x[i - 1] == y[j - 1])
		{
			path += x[i - 1]; // Put current character in result
			i--; j--;     // reduce values of i, j and index
		}

		else if (dp[i - 1][j] > dp[i][j - 1])
			i--;
		else
			j--;
	}

	reverse(path.begin(), path.end());
	cout << "LCS of " << x << " and " << y << " is " << path;

	return dp[n][m];
}

int count_longest_palindromic_substring(string s)
{
	int n = s.length();

	int count = 0;

	vector<vector<int>> dp(n, vector<int>(n, 0));

	//Length 1
	for (int i = 0; i < n; i++)
	{
		++count;
		dp[i][i] = 1;
	}

	//Length 2
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			++count;
			dp[i][i + 1] = 1;
		}
		else
			dp[i][i + 1] = 0;
	}

	for (int k = 3; k <= n; k++)
	{
		for (int i = 0; i < n - k + 1; i++)
		{
			int end = i + k - 1 ;
			if (dp[i + 1][end - 1] && s[i] == s[end]) {
				++count;
				dp[i][end] = true;
			}

		}
	}

	return count;
}

string longest_palindromic_substring(string s)
{
	int n = s.length();

	vector<vector<int>> dp(n, vector<int>(n, 0));

	int best_start = 0;
	int best_end = 0;
	int best_length = 1;

	//Length 1
	for (int i = 0; i < n; i++)
		dp[i][i] = 1;

	//Length 2
	for (int i = 0; i < n - 1; i++)
	{
		int len = 2;
		if (s[i] == s[i + 1])
		{
			dp[i][i + 1] = 1;
			if (best_length < len)
			{
				best_start = i;
				best_end = i + 1;
				best_length = 2;
			}
		}
	}

	for (int k = 3; k <= n; k++)
		for (int i = 0; i < n - k + 1; i++)
		{
			int end = i + k - 1;
			if (dp[i + 1][end - 1] && s[i] == s[end])
			{
				dp[i][end] = true;
				if (k >= best_length)
				{
					best_length = k;
					best_start = i;
					best_end = end;
				}
			}
		}

	PRINT;

	return s.substr(best_start, best_length);
}

int longest_increasing_subsequence(vector<int> v)
{
	int n = v.size();

	vector<int> dp(n, 0);

	dp[0] = 1;

	// Outer Loop keeps track of current Index
	for (int i = 1 ; i < n ; i++)
	{
		int cur = v[i];
		int max_lis = 0;

		for (int j = 0; j <= i; j++)
			if (v[j] < cur)
				max_lis = std::max(max_lis, dp[j]);

		dp[i] = 1 + max_lis;
	}

	return *max_element(dp.begin(), dp.end());
}

int maximum_sum_increasing_subsequence(vector<int> v)
{
	int n = v.size();

	vector<int> dp(n, 0);

	dp[0] = v[0];

	for (int i = 1; i < n; i++)
	{
		int cur = v[i];
		int max_sum = 0;

		for (int j = 0; j < i; j++)
		{
			if (v[j] < cur)
				max_sum = std::max(max_sum, dp[j]);

			dp[i] = cur + max_sum;
		}
	}

	return *max_element(dp.begin(), dp.end());
}

vector<vector<int>> threeSum(vector<int>& arr) {
	int n = arr.size();

	vector<vector<int>> result;

	sort(arr.begin(), arr.end());

	for (int i = 0 ; i < n - 2 ; i++)
	{
		// a + b + c = 0
		// a + b = 0 - c
		int sum = 0 - arr[i];

		int left = i + 1;
		int right = n - 1;

		while (left < right)
		{
			if (arr[left] + arr[right] == sum)
			{
				result.push_back({arr[i], arr[left], arr[right]});
				while (left < right && arr[left] == arr[left + 1]) left++;
				while (right > left && arr[right] == arr[right - 1]) right--;
				left++;
				right--;
			}
			else if (arr[left] + arr[right] < sum)
				left++;
			else
				right--;
		}
	}
	return result;
}

void mostCommonWord(string str, vector<string>& banned) {
	int n = str.length();

	map<string, int> m;

	for (int i = 0 ; i < n ; i++)
	{
		string temp = "";

		while (str[i] != ' ' && str[i] != '.' && str[i] != ',')
		{
			temp = temp + str[i];
			++i;
		}

		while (str[i] == ' ' || str[i] == '.' || str[i] == ',') ++i;
		--i;

		if (m.find(temp) != m.end())
			++m[temp];
		else
			m[temp] = 1;
	}


	int k = banned.size();

	for (int i = 0; i < k; i++)
	{
		m[banned[i]] = -1;
	}

	int max = 0;
	string ans;
	for (auto i : m)
	{
		if (i.second > max)
		{
			max = i.second;
			ans = i.first;
		}
	}

	for (auto i : m)
		cout << i.first << "->" << i.second << endl;

	cout << endl;
	cout << ans;
}

int Longest_Palindromic_Substring(string X)
{
	string Y = string(X.rbegin(), X.rend());

	int m = X.length();

	vector<vector<int>> dp(m + 1 , vector<int>(m + 1, 0));

	//Initialistion

	for (int i = 1; i < m + 1; i++)
		for (int j = 1; j < m + 1; j++)
		{
			if (X[i - 1] == Y[i - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
		}

	return dp[m][m];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	/**
		KNAPSACK
	**/

	// int n;
	// cin >> n;

	// int profit[n];
	// int weight[n];

	// for (int i = 0; i < n; i++)
	// 	cin >> profit[i];

	// for (int i = 0; i < n; i++)
	// 	cin >> weight[i];

	// int cap;
	// cin >> cap;

	// cout << dp_knapsack_01(profit, weight, cap, n);

	/**
		SUBSET SUM PROBLEM
	**/

	// int n;
	// cin >> n;

	// int arr[n];

	// for (int i = 0; i < n; i++)
	// 	cin >> arr[i];

	// int sum;
	// cin >> sum;

	// cout << dp_subset_sum_problem(arr, sum, n);
	cout << Longest_Palindromic_Substring("cbbd");

}