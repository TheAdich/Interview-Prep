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

class Heap {
	vector<int> v;
	bool minHeap;

	bool compare(int a, int b)
	{
		if (minHeap)
			return a < b;
		else
			return a > b;
	}

public:

	Heap(int default_size = 10, bool type = true)
	{
		v.reserve(default_size);
		v.push_back(-1);
		minHeap = type;
	}

	void push(int d)
	{
		v.push_back(d);

		int idx = v.size() - 1;

		int parent = idx / 2;

		while (idx > 1 && compare(v[idx], v[parent]))
		{
			swap(v[idx], v[parent]);
			idx = parent;
			parent = parent / 2;
		}
	}

	int top()
	{
		return v[1];
	}

	void heapify(int idx)
	{
		int parent = idx;
		int left = 2 * idx;
		int right = 2 * idx + 1;

		int min_idx = idx;
		int last = v.size() - 1;

		if (left <= last && compare(v[left], v[parent]))
			min_idx = left;
		else if (right <= last && compare(v[right], v[parent]))
			min_idx = right;


		if (min_idx != idx)
		{
			swap(v[idx], v[min_idx]);
			heapify(min_idx);
		}
	}

	void pop()
	{
		int last = v.size() - 1;
		swap(v[1], v[last]);
		v.pop_back();
		heapify(1);
	}

	bool empty()
	{
		return v.size() == 1;
	}
};

bool compare(int a, int b, bool minHeap)
{
	if (minHeap)
		return a < b;
	else
		return a > b;
}

void heapify(vector<int>& v, int idx, bool minHeap)
{
	int parent = idx;
	int left = 2 * idx;
	int right = 2 * idx + 1;

	int min_idx = idx;
	int last = v.size() - 1;

	if (left <= last && compare(v[left], v[parent], minHeap))
		min_idx = left;
	else if (right <= last && compare(v[right], v[parent], minHeap))
		min_idx = right;

	if (min_idx != idx)
	{
		swap(v[idx], v[min_idx]);
		heapify(v, min_idx, minHeap);
	}
}

void build_heap(vector<int> &v, bool minHeap = true)
{
	int n = v.size();

	for (int i = n / 2; i >= 1; i--)
		heapify(v, i, minHeap);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	// int n;
	// cin >> n;

	// Heap h(n, false);


	// for (int i = 0; i < n; i++)
	// {
	// 	int x;
	// 	cin >> x;
	// 	h.push(x);
	// }

	// while (!h.empty())
	// {
	// 	cout << h.top() << " ";
	// 	h.pop();
	// }

	vector<int> v = { -1, 9, 6, 5, 0, 8, 2, 1, 3};
	build_heap(v, true);

	cout << v;
}