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

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) {
		this->val = val;
		left = NULL;
		right = NULL;
	}
};

TreeNode* build_preorder()
{
	int d;
	cin >> d;

	if (d == -1)
		return NULL;

	TreeNode* root = new TreeNode(d);

	root->left = build_preorder();
	root->right = build_preorder();

	return root;
}

void preorder_print(TreeNode* root)
{
	if (root == NULL)
		return;

	cout << root->val << " ";
	preorder_print(root->left);
	preorder_print(root->right);
}

void inorder_print(TreeNode* root)
{
	if (root == NULL)
		return;

	inorder_print(root->left);
	cout << root->val << " ";
	inorder_print(root->right);
}

void add_left_branch_to_stack(TreeNode* root, stack<TreeNode*>&s)
{
	while (root)
	{
		s.push(root);
		root = root->left;
	}
}

void inorder_iterative(TreeNode* root)
{
	stack<TreeNode*> s;
	add_left_branch_to_stack(root, s);

	while (!s.empty())
	{
		TreeNode* temp = s.top();
		s.pop();
		cout << temp->val << " ";

		if (temp->right)
			add_left_branch_to_stack(temp->right, s);
	}
}

int height(TreeNode* root)
{
	if (root == NULL)
		return 0;

	// Hit Rock-Bottom
	int lh = height(root->left);
	int rh = height(root->right);

	// Return something to Parent
	return std::max(lh, rh) + 1;
}

int diameter(TreeNode* root)
{
	if (root == NULL)
		return 0;

	int hl = height(root->left);
	int hr = height(root->right);

	int op1 = hl + hr + 1;
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);

	return std::max(op1, std::max(op2, op3));
}

vector<int> fast_diameter(TreeNode* root)
{
	vector<int> ans(2);

	if (root == NULL)
		return {0, 0};

	vector<int> left = fast_diameter(root->left);
	vector<int> right = fast_diameter(root->right);

	ans[0] = std::max(left[0], right[0]) + 1;
	ans[1] = std::max(std::max(left[1], right[1]), left[0] + right[0] + 1);

	return ans;
}

// vector<int> v(2);
// {height, balanced}
// {int, bool}

vector<int> is_balanced(TreeNode* root)
{
	vector<int> ans(2);

	if (root == NULL)
		return {0, 1};

	vector<int> left = is_balanced(root->left);
	vector<int> right = is_balanced(root->right);

	ans[0] = std::max(left[0], right[0]) + 1;
	ans[1] = abs(left[0] - right[0]) <= 1 && left[1] && right[1] ? 1 : 0;

	return ans;
}

/**

				1
			  /   \
		    "2"	   3
		  /   \   /  \
		4	   5 6	  7
	     \    /
	     10  9

**/

TreeNode* LCA(TreeNode* root, int a, int b)
{
	if (root == NULL)
		return root;

	if (root->val == a || root->val == b)
		return root;

	TreeNode* something_on_left = LCA(root->left, a, b);
	TreeNode* something_on_right = LCA(root->right, a, b);

	if (something_on_left != NULL && something_on_right != NULL)
		return root;

	if (something_on_left == NULL)
		return something_on_right;
	return something_on_left;
}

void inorder(TreeNode* root, vector<int>&v)
{
	if (root == NULL)
		return;

	inorder(root->left, v);
	v.push_back(root->val);
	inorder(root->right, v);
}

bool get_path(TreeNode* root, TreeNode* target, vector<TreeNode*>& path)
{
	if (root == NULL)
		return false;

	path.push_back(root);

	if (root == target)
		return true;

	bool present_left = get_path(root->left, target, path);
	bool present_right = get_path(root->right, target, path);

	if (!present_left && !present_right)
	{
		path.pop_back();
		return false;
	}

	if (!present_left)
		return present_right;
	return present_left;

}

int burn_tree(TreeNode* root, TreeNode* leaf)
{
	vector<TreeNode*> path;
	get_path(root, leaf, path);

	int n = path.size();
	int ans = n - 1;

	for (int i = 0; i < n - 1; i++)
	{
		//If left node is in path
		if (path[i]->left == path[i + 1])
			ans = std::max(ans, n - 1 - i + height(path[i]->right));
		else if (path[i]->right == path[i + 1])
			ans = std::max(ans, n - 1 - i + height(path[i]->left));
	}

	return ans;
}

void print_all_path_leaf(TreeNode* root, vector<int>& path)
{
	if (root == NULL)
		return;

	path.push_back(root->val);

	if (root->left == NULL && root->right == NULL)
	{
		cout << path << endl;
		path.pop_back();
		return;
	}

	print_all_path_leaf(root->left, path);
	print_all_path_leaf(root->right, path);
	path.pop_back();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	// TreeNode* root = build_preorder();
	// // preorder_print(root);
	// TreeNode* target = root->left->right->left->right;
	// cout << burn_tree(root, target);

	TreeNode* root = build_preorder();
	vector<vector<int>> v;
	vector<int> path;
	print_all_path_leaf(root, path);
}