/*
The stock span problem is a financial problem where we have a series of n daily price
quotes for a stock and we need to calculate span of stock’s price for all n days.
*/

#include <bits/stdc++.h>
#include <stack>
#include <utility>

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

void stockSpanProblem(int arr[], int n)
{
	stack<pair<int, int>> s;
	s.push(make_pair(arr[0], 0));

	int ans[n];

	for (int i = 0 ; i < n ; i++)
	{
		int top = s.top().first;
		int topIndex = s.top().second;

		if (arr[i] < top)
		{
			s.push(make_pair(arr[i], i));
			ans[i] = i - topIndex;
		}

		else
		{
			while (s.top().first < arr[i])
				s.pop();

			ans[i] = i - s.top().second;
			s.push(make_pair(arr[i], i));
		}
	}

	cout << "STOCK SPAN: \n";
	for (auto i : ans)
		cout << i << " ";
}

/**
	arr[]: {1,3,2,4}
	ans[]: {3,4,4,-1}
**/

vector<int> nge(vector<int> arr)
{
	int n = arr.size();

	vector<int> v;

	stack<int> s;

	for (int i = n - 1; i >= 0; --i)
	{
		if (s.empty())
			v.push_back(-1);
		else
		{
			if (s.top() > arr[i])
				v.push_back(s.top());
			else
			{
				while (!s.empty() && s.top() < arr[i])
					s.pop();

				if (s.empty())
					v.push_back(-1);
				else
					v.push_back(s.top());
			}
		}

		s.push(arr[i]);
	}

	reverse(v.begin(), v.end());

	return v;
}

/**
	arr[]: {1, 3, 2, 4}
	ans[]: {-1, -1, 3, -1}
**/

vector<int> ngl(vector<int> arr)
{
	int n = arr.size();

	vector<int> v;
	stack<int> s;

	for (int i = 0; i < n; i++)
	{
		if (s.empty())
			v.push_back(-1);
		else
		{
			if (s.top() > arr[i])
				v.push_back(s.top());
			else
			{
				while (!s.empty() && s.top() < arr[i])
					s.pop();

				if (s.empty())
					v.push_back(-1);
				else
					v.push_back(s.top());
			}
		}

		s.push(arr[i]);
	}

	return v;
}

vector<int> stock_span(vector<int> arr)
{
	int n = arr.size();

	stack<pair<int, int>> s;
	vector<int> v;

	for (int i = 0; i < n; i++)
	{
		if (s.empty())
			v.push_back(-1);
		else
		{
			if (arr[i] < s.top().first)
				v.push_back(s.top().second);
			else
			{
				while (!s.empty() && s.top().first < arr[i])
					s.pop();

				if (s.empty())
					v.push_back(-1);
				else
					v.push_back(s.top().second);
			}
		}

		s.push(make_pair(arr[i], i));
	}

	for (int i = 0; i < n; i++)
		v[i] = i - v[i];

	return v;
}

/**
	Next Smallest Left
**/

vector<int> nsl(vector<int> arr)
{
	int n = arr.size();

	stack<pair<int, int>> s;
	vector<int> v;

	for (int i = 0; i < n; i++)
	{
		if (s.empty())
			v.push_back(-1);
		else
		{
			if (arr[i] > s.top().first)
				v.push_back(s.top().second);

			// If arr[i] < s.top()
			else
			{
				while (!s.empty() &&  arr[i] <= s.top().first)
					s.pop();

				if (s.empty())
					v.push_back(-1);
				else
					v.push_back(s.top().second);
			}
		}
		s.push(mp(arr[i], i));
	}

	return v;
}

vector<int> nsr(vector<int> arr)
{
	int n = arr.size();

	stack<pair<int, int>> s;
	vector<int> v;

	int pseudo_index = n;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s.empty())
			v.push_back(pseudo_index);
		else
		{
			if (arr[i] > s.top().first)
				v.push_back(s.top().second);
			else
			{
				while (!s.empty() && arr[i] <= s.top().first)
					s.pop();
				if (s.empty())
					v.push_back(pseudo_index);
				else
					v.push_back(s.top().second);
			}
		}

		s.push(mp(arr[i], i));
	}

	reverse(v.begin(), v.end());

	return v;
}

// ALERT: NOT CORRECT
int area_histogram(vector<int> arr)
{
	int n = arr.size();

	vector<int> next_smallest_left = nsl(arr);
	vector<int> next_smallest_right = nsr(arr);
	vector<int> width;
	int area = INT_MIN;

	for (int i = 0; i < n; i++)
		width.push_back(arr[i] * (next_smallest_right[i] - next_smallest_left[i] - 1));

	for (int i = 0; i < n; i++)
		area = std::max(area, arr[i] * width[i]);

	return area;
}

int GFGgetMaxArea(vector<int> hist)
{
	int n = hist.size();
	// Create an empty stack. The stack holds indexes
	// of hist[] array. The bars stored in stack are
	// always in increasing order of their heights.
	stack<int> s;

	int max_area = 0; // Initialize max area
	int tp;  // To store top of stack
	int area_with_top; // To store area with top bar
	// as the smallest bar

	// Run through all bars of given histogram
	int i = 0;
	while (i < n)
	{
		// If this bar is higher than the bar on top
		// stack, push it to stack
		if (s.empty() || hist[s.top()] <= hist[i])
			s.push(i++);

		// If this bar is lower than top of stack,
		// then calculate area of rectangle with stack
		// top as the smallest (or minimum height) bar.
		// 'i' is 'right index' for the top and element
		// before top in stack is 'left index'
		else
		{
			tp = s.top();  // store the top index
			s.pop();  // pop the top

			// Calculate the area with hist[tp] stack
			// as smallest bar
			area_with_top = hist[tp] * (s.empty() ? i :
			                            i - s.top() - 1);

			// update max area, if needed
			if (max_area < area_with_top)
				max_area = area_with_top;
		}
	}

	// Now pop the remaining bars from stack and calculate
	// area with every popped bar as the smallest bar
	while (s.empty() == false)
	{
		tp = s.top();
		s.pop();
		area_with_top = hist[tp] * (s.empty() ? i :
		                            i - s.top() - 1);

		if (max_area < area_with_top)
			max_area = area_with_top;
	}

	return max_area;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	// int arr[] = {100, 80, 60, 70, 60, 75, 85};
	// int n = sizeof(arr) / sizeof(int);

	// stockSpanProblem(arr, n);

	// vector<int> v = {6, 2, 5, 4, 5, 1, 6};
	// vector<int> v = {1, 2, 2, 1};

	// cout << GFGgetMaxArea(v);

}