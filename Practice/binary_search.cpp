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

// Function to print array arr[]
void printArray(int arr[], int arr_size)
{
	// Iterate and print every element
	for (int i = 0; i < arr_size; i++)
		cout << arr[i] << " ";
}

void sort01(int a[], int arr_size)
{
	int lo = 0;
	int hi = arr_size - 1;
	int mid = 0;

	// Iterate till all the elements
	// are sorted
	int i = 0;
	while (mid <= hi) {
		switch (a[mid]) {

		// If the element is 0
		case 0:
			swap(a[lo++], a[mid++]);
			break;

		// If the element is 1 .
		case 1:
			mid++;
			break;
		}
		cout << i++ << ": ";
		printArray(a, arr_size);
		cout << endl;
	}
}

int binary_search_iterative(vector<int> v, int x)
{
	int n = v.size();

	int i = 0;
	int j = n - 1;

	while (i <= j)
	{
		int mid = i + (j - i) / 2;

		if (v[mid] == x)
			return mid;

		else if (x > v[mid])
			j = mid - 1;
		else
			i = mid + 1;
	}

	return -1;
}

int first_occurance(vector<int> v, int x)
{
	int n = v.size();
	int i = 0;
	int j = n - 1;

	int res = -1;

	while (i <= j)
	{
		int mid = i + (j - i) / 2;

		deb(v[mid]);

		if (v[mid] == x)
		{
			res = mid;
			j = mid - 1;
		}

		else if (x > v[mid])
			i = mid + 1;
		else
			j = mid - 1;
	}

	return res;
}

int last_occurance(vector<int> v, int x)
{
	int n = v.size();
	int i = 0;
	int j = n - 1;

	int res = -1;

	while (i <= j)
	{
		int mid = i + (j - i) / 2;

		deb(v[mid]);

		if (v[mid] == x)
		{
			res = mid;
			i = mid + 1;
		}

		else if (x > v[mid])
			i = mid + 1;
		else
			j = mid - 1;
	}

	return res;
}

int count_times_rotated(vector<int> v)
{
	int n = v.size();
	int left = 0;
	int right = n - 1;

	while (left < right)
	{
		if (v[left] <= v[right]) {
			return v[left];
		}

		int mid = left + (right - left) / 2;

		if (v[mid] == std::min(v[mid], std::min(v[(mid + n - 1) % n], v[(mid + 1) % n])))
			return mid;
		if (v[left] <= v[mid])
			left = mid + 1;
		if (v[mid] <= v[right])
			right = mid - 1;
	}

	return -1;
}

int floor_sorted_array(vector<int> v, int x)
{
	int n = v.size();
	int left = 0;
	int right = n - 1;

	int res = -1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (v[mid] == x)
			return mid;

		if (v[mid] > x)
			right = mid - 1;
		if (v[mid] < x)
		{
			res = mid;
			left = mid + 1;
		}
	}

	return res;
}

int ceil_sorted_array(vector<int> v, int x)
{
	int n = v.size();
	int left = 0;
	int right = n - 1;

	int res = INT_MAX;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (v[mid] == x)
			return mid;

		//LEFT
		if (v[mid] > x)
		{
			res = mid;
			right = mid - 1;
		}
		if (v[mid] < x)
			left = mid + 1;

	}

	return res;
}

int minimum_difference_sorted_array(vector<int> v, int x)
{
	int n = v.size();

	int i = 0;
	int j = n - 1;

	while (i <= j)
	{
		int mid = i + (j - i) / 2;

		if (v[mid] == x)
			return mid;

		else if (x > v[mid])
			i = mid + 1;
		else
			j = mid - 1;
	}

	deb(i);
	deb(j);
	return std::min(v[i], v[j]);
}

int find_non_negatives(vector<int> v)
{
	int n = v.size();

	int left = 0;
	int right = n;

	while (left < right)
	{
		int mid = left + (right - left) / 2;

		if (v[mid] < 0)
			right = mid;
		else
			left = mid + 1;
	}

	return left;
}



int main()
{
	// int n;
	// cin >> n;

	// vector<int> v;

	// for (int i = 0; i < n; i++)
	// {
	// 	int x;
	// 	cin >> x;
	// 	v.push_back(x);
	// }

	// cout << find_non_negatives(v);

	for (int i = 1; i < 40; i++)
		cout << i << endl;
}