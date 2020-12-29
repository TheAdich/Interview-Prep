/**
 * Muhammad Ali, one of my great heroes, had a great line
 * in the '70s when he was asked "How many sit-ups do you do?"
 * He said, "I don't count my sit-ups. I only start counting when
 * it starts hurting. When I feel pain, that's when I start counting
 * because that's when it really counts". That's what makes you a
 * champion. And that's the way it is with everything.
 * ~ Arnold Schwarzenegger
**/

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
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
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

TreeNode* buildTree()
{
	int d;
	cin >> d;

	if (d == -1)
		return NULL;

	else
	{
		TreeNode* root = new TreeNode(d);
		root->left = buildTree();
		root->right = buildTree();
		return root;
	}
}

//Root Left Right
void preorderPrintTree(TreeNode* root)
{
	if (root == NULL)
		return;

	else
	{
		cout << root->data << " ";
		preorderPrintTree(root->left);
		preorderPrintTree(root->right);
	}
}

//Left Right Root
void postorderPrintTree(TreeNode* root)
{
	if (root == NULL)
		return;

	else
	{
		postorderPrintTree(root->left);
		postorderPrintTree(root->right);

		cout << root->data << " ";

	}
}

//Left Root Right
void inorderPrintTree(TreeNode* root)
{
	if (root == NULL)
		return;

	else
	{
		inorderPrintTree(root->left);
		cout << root->data << " ";
		inorderPrintTree(root->right);
	}
}

bool rootToNodePath(TreeNode* root, int val, string path "") {
	if (root == NULL)
		return false;

	if (root->data == val) {
		path += to_string(root->data);
		return true;
	}

	bool res = rootToNodePath(root->left, val, path) || rootToNodePath(root->right, val, path);
	if (res) {
		path += to_string(root->data);
	}
}

int main()
{

}