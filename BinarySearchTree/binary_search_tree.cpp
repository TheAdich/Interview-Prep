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

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

Node* insert_BST(Node* root, int x)
{
	if (root == NULL)
		return new Node(x);

	else
	{
		if (x <= root->data)
			root->left = insert_BST(root->left, x);
		else
			root->right = insert_BST(root->right, x);
	}
	return root;
}

Node* build_BST()
{
	Node* root;

	int n;
	cin >> n;

	while (n)
	{
		int x;
		cin >> x;
		root = insert_BST(root, x);
		--n;
	}

	return root;
}

void preorder(Node* root) {
	if (root == NULL)
		return;

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node* root) {
	if (root == NULL)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void postorder(Node* root) {
	if (root == NULL)
		return;

	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

Node* search_BST(Node* root, int x) {
	if (root == NULL)
		return NULL;

	if (root->data == x)
		return root;

	if (x <= root->data)
		return search_BST(root->left, x);
	else
		return search_BST(root->right, x);
}

Node* delete_BST(Node* root, int x) {
	if (root == NULL)
		return NULL;

	else if (x < root->data) {
		root->left = delete_BST(root->left, x);
		return root;
	}
	else if (x > root->data) {
		root->right = delete_BST(root->right, x);
		return root;
	}

	else {
		// If 0 child
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		}

		// If 1 child LEFT
		if (root->left != NULL && root->right == NULL) {
			Node* temp = root->left;
			delete root;
			return temp;
		}
		// If 1 child RIGHT
		if (root->left == NULL && root->right != NULL) {
			Node* temp = root->right;
			delete root;
			return temp;
		}

		// If 2 Child
		// Replace current root by Minimum value
		// of Right Sub-Tree
		Node* replace = root->right;

		while (replace->left != NULL) {
			replace = replace->left;
		}

		root->data = replace->data;
		root->right = delete_BST(root->right, replace->data);
		return root;
	}
}

int search(int pre, int in[], int left, int right) {

	for (int i = left ; i <= right ; i++)
	{
		if (pre == in[i])
			return i;
	}
	return -1;
}

Node* _build_pre_in(int pre[], int in[], int n, int left, int right, int& pre_index) {

	if ( left > right)
		return NULL;

	// Left Right are for In_Order
	// PreOrder helps to search node in InOrder
	Node* root = new Node(pre[pre_index++]);

	if (left == right)
		return root;

	int in_index = search(root->data, in, left, right);

	root->left = _build_pre_in(pre, in, n, left, in_index - 1, pre_index);
	root->right = _build_pre_in(pre, in, n, in_index + 1, right, pre_index);

	return root;
}

Node* build_pre_in(int pre[], int in[], int n) {
	int pre_index = 0;
	return _build_pre_in(pre, in, n, 0, n - 1, pre_index);
}

void _get_kth_smallest_BST(Node* root, int& k) {
	if (root == NULL)
		return;

	_get_kth_smallest_BST(root->left, k - 1);
	if (root != NULL && k == 0)
	{
		cout << root->data;
		return;
	}
	_get_kth_smallest_BST(root->right, k - 1);
}

void get_kth_smallest_BST(Node* root, int k) {
	int count = k;
	get_kth_smallest_BST(root, count);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	Node* root = build_BST();
	inorder_build(root);
	_get_kth_smallest_BST(root, 2);
}