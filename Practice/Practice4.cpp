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

template <typename T>
ostream& operator<<(ostream& os, const pair<T, T>& p)
{
	os << "{" << p.first << ", " << p.second << "}, ";
	return os;
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

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

Node* buildTree()
{
	int d;
	cin >> d;

	if (d == -1)
		return NULL;

	Node* root = new Node(d);
	root->left = buildTree();
	root->right = buildTree();

	return root;
}

void _BT_to_DLL(Node* root, Node* &head)
{
	if (root == NULL)
		return;

	static Node* prev = NULL;

	_BT_to_DLL(root->left, head);

	if (prev == NULL)
		head = root;

	else
	{
		root->left = prev;
		prev->right = root;
	}
	prev = root;

	_BT_to_DLL(root->right, head);

}

void BT_to_DLL(Node* root)
{
	Node* head = NULL;
	_BT_to_DLL(root, head);

	while (head != NULL)
	{
		cout << "<-" << head->data << "-> ";
		head = head->right;
	}
}

Node* _flatten(Node* root)
{
	if (root == NULL)
		return NULL;

	if (root->left == NULL && root->right == NULL)
		return root;

	// Flatten Left Subtree
	Node* leftTail = _flatten(root->left);

	// Flatten Right Subtree
	Node* rightTail = _flatten(root->right);

	if (leftTail != NULL)
	{
		leftTail->right = root->right;
		root->right = root->left;
		root->left = NULL;
	}

	return rightTail == NULL ? leftTail : rightTail;
}

void flatten(Node* root)
{
	_flatten(root);
}


void inorder(int a[], std::vector<int> &v,
             int n, int index)
{
	// if index is greater or equal to vector size
	if (index >= n)
		return;
	inorder(a, v, n, 2 * index + 1);

	// push elements in vector
	v.push_back(a[index]);
	inorder(a, v, n, 2 * index + 2);
}

// Function to find minimum swaps to sort an array
int minSwaps(std::vector<int> &v)
{
	std::vector<pair<int, int> > t(v.size());
	int ans = 0;
	for (int i = 0; i < v.size(); i++)
		t[i].first = v[i], t[i].second = i;

	sort(t.begin(), t.end());

	for (int i = 0; i < t.size(); i++)
	{
		// second element is equal to i
		if (i == t[i].second)
			continue;
		else
		{
			// swaping of elements
			swap(t[i].first, t[t[i].second].first);
			swap(t[i].second, t[t[i].second].second);
		}

		// Second is not equal to i
		if (i != t[i].second)
			--i;
		ans++;
	}
	return ans;
}

class Point {
public:
	vector<int> point_array;
	double dist;
};

class PointCompare {
public:
	bool operator()(Point A, Point B)
	{
		return A.dist < B.dist;
	}
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {

	vector<vector<int>> v;

	priority_queue<Point, vector<Point>, PointCompare> pq;

	int n = points.size();

	for (int i = 0; i < n; i++)
	{
		Point p{points[i], sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1])};
		pq.push(p);
	}

	while (K != 1)
	{
		v.push_back(pq.top().point_array);
		pq.pop();
		--K;
	}
	return v;
}

void parent_store(Node* root, Node* parent, map<int, vector<int>> &adjList)
{
	if (root == NULL)
		return;

	if (adjList.find(root->data) == adjList.end())
	{
		if (parent)
		{
			adjList[root->data].push_back(parent->data);
			adjList[parent->data].push_back(root->data);
		}
		parent_store(root->left, root, adjList);
		parent_store(root->right, root, adjList);
	}
}

vector<int> distance_k(Node* root, Node* target, int k)
{
	map<int, vector<int>> adjList;
	parent_store(root, NULL, adjList);

	for (auto i : adjList)
	{
		cout << i.first << " -> ";
		for (auto vertex : i.second)
			cout << vertex << ",";
		cout << endl;
	}

	cout << endl;

	vector<int> ans;
	queue<int> q;
	map<int, bool> visited;

	q.push(target->data);
	visited[target->data] = true;

	if (k == 0) {
		ans.push_back(target->data);
		return ans;
	}
	int level = 0;
	while (!q.empty())
	{
		++level;

		int n = q.size();

		for (int i = 0; i < n; i++)
		{
			int cur = q.front();
			q.pop();

			for (auto i : adjList[cur])
			{
				if (visited[i] == 0)
				{
					q.push(i);
					visited[i] = true;
				}
			}

		}

		if (level == k)
		{
			while (!q.empty())
			{
				ans.push_back(q.front());
				q.pop();
			}
		}
	}

	return ans;
}

void BFS(Node* root)
{
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		Node* f = q.front();

		if (f == NULL)
		{
			cout << endl;
			q.pop();

			if (!q.empty())
				q.push(NULL);
		}

		else
		{
			cout << f->data << " ";
			q.pop();

			if (f->left) {
				q.push(f->left);
			}
			if (f->right) {
				q.push(f->right);
			}
		}
	}
	return;
}

void _verticalOrder(Node* root, int hd, int level, map<int, vector<pair<int, int>>>& m)
{
	if (root == NULL)
		return;

	m[hd].push_back({root->data, level});

	_verticalOrder(root->left, hd - 1, level + 1, m);
	_verticalOrder(root->right, hd + 1, level + 1, m);
}

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}

vector<vector<int>> verticalOrder(Node* root) {
	if (root == NULL)
		return {};

	vector<vector<int>> res;

	map<int, vector<pair<int, int>>> m;

	_verticalOrder(root, 0, 0, m);

	for (auto i : m)
	{
		sort(i.second.begin(), i.second.end(), compare);
		// cout << i.first << ": " << i.second << endl;
		vector<int> temp;
		for (auto j : i.second)
			temp.push_back(j.first);

		res.push_back(temp);
	}

	for (auto i : res)
		cout << i << endl;
	return res;
}

string int_to_string(int n)
{
	int negative = 0;
	if (n < 0)
		negative = 1;

	n = abs(n);

	string s = "";

	while (n) {
		s = s + (char)('0' + n % 10);
		n = n / 10;
	}

	reverse(s.begin(), s.end());
	string ans = "-";

	if (negative)
	{
		ans = ans + s;
		return ans;
	}

	return s;
}

void add_left_to_stack(stack<Node*> &s, Node* root)
{
	while (root)
	{
		s.push(root);
		root = root->left;
	}
}

void InorderIterative(Node* root)
{
	stack<Node*> s;

	add_left_to_stack(s, root);

	while (!s.empty())
	{
		Node* temp = s.top();
		s.pop();
		cout << temp->data << " ";

		if (temp->right)
			add_left_to_stack(s, temp->right);
	}
}

int rightMostBit(int n)
{
	int mask = 1;

	int count = 0;
	while (n > 0)
	{
		++count;
		if ( (mask & n) == 1)
			return count;

		n = n >> 1;
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	cout << rightMostBit(18);

}