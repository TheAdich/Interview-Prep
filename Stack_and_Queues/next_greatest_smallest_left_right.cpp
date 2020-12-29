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

vector<int> nger(vector<int> arr) {
	int n = arr.size();

	stack<int> s;
	vector<int> ans(n, -1); // O(N)

	for (int i = 0; i < n; i++) {

		while (!s.empty() && arr[i] > arr[s.top()]) {
			ans[s.top()] = arr[i];
			s.pop();
		}

		s.push(i);
	}

	return ans;
}

vector<int> ngel(vector<int> arr) {
	int n = arr.size();

	stack<int> s;
	vector<int> ans(n, -1); // O(N)

	for (int i = n - 1; i >= 0; i--) {

		while (!s.empty() && arr[i] > arr[s.top()]) {
			ans[s.top()] = arr[i];
			s.pop();
		}

		s.push(i);
	}

	return ans;
}

vector<int> nsel(vector<int> arr) {
	int n = arr.size();

	stack<int> s;
	vector<int> ans(n, -1);

	for (int i = n - 1; i >= 0; i--) {

		while (!s.empty() && arr[s.top()] > arr[i]) {
			ans[s.top()] = arr[i];
			s.pop();
		}

		s.push(i);
	}

	return ans;
}

vector<int> nser(vector<int> arr) {
	int n = arr.size();

	stack<int> s;
	vector<int> ans(n, -1);

	for (int i = 0; i < n; i++) {

		while (!s.empty() && arr[s.top()] > arr[i]) {
			ans[s.top()] = arr[i];
			s.pop();
		}

		s.push(i);
	}

	return ans;
}

int main()
{
	/**
		9
		2 5 9 3 1 12 6 8 10
	**/

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	deb(nger(arr));
	deb(ngel(arr));
}