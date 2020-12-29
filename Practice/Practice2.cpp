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

template <typename T>
ostream& operator<<(ostream& os, const pair<T, T>& p)
{
	os << "{" << p.first << ", " << p.second << "}\n";
	return os;
}

// Max, Min
pair<int, int> find_max_min(int arr[], int i, int j)
{
	if (i == j)
		return {arr[i], arr[j]};

	else if (i == j - 1)
	{
		if (arr[i] < arr[j])
			return {arr[j], arr[i]};
		else
			return {arr[i], arr[j]};
	}

	else
	{
		int mid = (i + j) / 2;

		pair<int, int> p1 = find_max_min(arr, i, mid);
		pair<int, int> p2 = find_max_min(arr, mid + 1, j);

		int max = INT_MIN;
		int min = INT_MAX;

		if (p1.first < p2.first)
			max = p2.first;
		else
			max = p1.first;

		if (p1.second < p2.second)
			min = p1.second;
		else
			min = p2.second;

		return {max, min};
	}
}

int binary_search(int arr[], int i, int j, int x)
{
	if (i == j)
	{
		if (arr[i] == x)
			return i + 1;
		else return -1;
	}

	int mid = (i + j) / 2;

	if (arr[mid] == x)
		return mid + 1;
	else if (arr[mid] < x)
		return binary_search(arr, mid + 1, j, x);
	else
		return binary_search(arr, i, mid, x);

}

vector<int> merge(vector<int> a, vector<int> b)
{
	int n = a.size();
	int m = b.size();

	int ptr_a = 0;
	int ptr_b = 0;

	vector<int> result;

	while (ptr_a < n && ptr_b < m)
	{
		if (a[ptr_a] < b[ptr_b])
			result.push_back(a[ptr_a++]);
		else
			result.push_back(b[ptr_b++]);
	}

	while (ptr_a < n)
		result.push_back(a[ptr_a++]);
	while (ptr_b < m)
		result.push_back(b[ptr_b++]);

	return result;
}

vector<int> k_sorted(vector<vector<int>> v, int k)
{
	if (k == 2)
		return merge(v[0], v[1]);

	vector<int> temp = v[0];
	for (int i = 1; i < k; i++)
		temp = merge(temp, v[i]);

	return temp;
}

bool valid(vector<int> v, int n)
{
	int k = v.size();
	for (int i = 0; i < k; i++)
		if (v[i] > n - 1)
			return false;

	return true;
}

int missingNumber(vector<int>& arr) {

	int sum_of_elems = std::accumulate(arr.begin(), arr.end(), 0);
	int n = arr.size();

	return n * (n + 1) / 2 - sum_of_elems;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	// int t = 1;
	// while (t--) {
	// 	int n;
	// 	cin >> n;

	// 	int x;
	// 	cin >> x;

	// 	int arr[n];

	// 	for (int i = 0; i < n; i++)
	// 		cin >> arr[i];

	// 	cout << binary_search(arr, 0, n - 1, x);
	// }

	//MERGE
	// int k;
	// cin >> k;

	// int n;
	// cin >> n;

	// vector<vector<int>> v;

	// for (int i = 0 ; i < k ; i++)
	// {
	// 	vector<int> temp;
	// 	for (int j = 0; j < n; j++)
	// 	{
	// 		int x;
	// 		cin >> x;
	// 		temp.push_back(x);
	// 	}
	// 	v.push_back(temp);
	// }

	// cout << k_sorted(v, k);

	vector<int> v = {9, 6, 4, 2, 3, 5, 7, 0, 1};
	cout << missingNumber(v);
}