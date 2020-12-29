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

//Matrix Product
//Recursive
//Two branching. RIGHT and DOWN.
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

class Person {
public:
	string name;
	int age;

	Person() {}

	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
};

class PersonCompare {
public:
	bool operator()(Person A, Person B) {
		return A.age > B.age;
	}
};

int join_ropes_sort(int ropes[], int n)
{
	sort(ropes, ropes + n);

	int rope1 = ropes[0];
	int rope2 = 0;

	int cost = 0;

	for (int i = 1; i < n; i++)
	{
		rope2 = ropes[i];
		cost = cost + rope1 + rope2;
		rope1 = rope1 + rope2;
	}

	return cost;
}

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
		int n;
		cin >> n;

		int arr[n];

		// for (int i = 0; i < n; i++)
		// 	cin >> arr[i];

		priority_queue<int, vector<int>, less<int> > pq;

		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			pq.push(x);
		}

		for (int i = 0; i < n; i++)
		{
			int p = pq.top();
			cout << p << endl;
			pq.pop();
		}

		// cout << join_ropes_pq(arr, n);

		// priority_queue<Person, vector<Person>, PersonCompare > pq; //MinHeap

		// for (int i = 0; i < n; i++)
		// {
		// 	string name;
		// 	int age;
		// 	cin >> name >> age;
		// 	Person p(name, age);
		// 	pq.push(p);
		// }

		// int k = 3;

		// for (int i = 0; i < k; i++)
		// {
		// 	Person p = pq.top();
		// 	cout << p.name << " " << p.age << endl;
		// 	pq.pop();
		// }



	}
}