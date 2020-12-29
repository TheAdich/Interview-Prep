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

#define NEWLINE cout << endl;

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

Node* insertBST(Node* root, int data)
{
	if (root == NULL)
		return new Node(data);

	else
	{
		if (data <= root->data)
			root->left = insertBST(root->left, data);
		else
			root->right = insertBST(root->right, data);
	}
	return root;
}

Node* build()
{
	Node* root;

	int x;
	cin >> x;

	while (x != -1)
	{
		root = insertBST(root, x);
		cin >> x;
	}

	return root;
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

Node* searchBST(Node* root, int k)
{
	if (root == NULL || root->data == k)
		return root;

	else
	{
		if (k <= root->data)
			return searchBST(root->left, k);
		else
			return searchBST(root->right, k);
	}
}

Node* deleteBST()
{

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	Node* root = build();
	BFS(root);
	NEWLINE;
	searchBST(root, 7) != NULL ? cout << "Found\n" : cout << "Not found\n";
}