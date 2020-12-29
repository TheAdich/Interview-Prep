#include <bits/stdc++.h>
#include <queue>
using namespace std;

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

#define NEWLINE cout << endl;

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

	else
	{
		Node* root = new Node(d);
		root->left = buildTree();
		root->right = buildTree();
		return root;
	}
}

//Root Left Right
void preorderPrintTree(Node* root)
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
void postorderPrintTree(Node* root)
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
void inorderPrintTree(Node* root)
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

/**
Level defined as
	1          <-- Level 1
	2 3        <-- Level 2
	4 5        <-- Level 3
	6 7 8 9    <-- Level 4
	10 11      <-- Level 5
**/
void printLevelOrder(Node* root, int k)
{
	if (root == NULL)
		return;

	else if (k == 1)
	{
		cout << root->data << " ";
		return;
	}

	printLevelOrder(root->left, k - 1);
	printLevelOrder(root->right, k - 1);
}

int height(Node* root)
{
	if (root == NULL)
		return 0;

	else
	{
		return std::max(height(root->left), height(root->right)) + 1;
	}
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

void reverseLevelOrder(Node* root)
{
	if (root == NULL)
		return;

	queue<Node*> q;
	stack<Node*> s;

	q.push(root);

	while (!q.empty())
	{
		Node* parent = q.front();
		q.pop();

		s.push(parent);

		if (parent->right)
			q.push(parent->right);

		if (parent->left)
			q.push(parent->left);
	}

	while (!s.empty())
	{
		cout << s.top()->data << " ";
		s.pop();
	}
	return;
}

int countNodes(Node* root)
{
	if (root == NULL)
		return 0;

	else
	{
		int left = countNodes(root->left);
		int right = countNodes(root->right);
		return 1 + left + right;
	}
}

int sumNodes(Node* root)
{
	if (root == NULL)
		return 0;
	else
	{
		return root->data + sumNodes(root->left) + sumNodes(root->right);
	}
}

int diameterOfTree(Node* root)
{
	if (root == NULL)
		return 0;

	else
	{
		int h1 = height(root->left);
		int h2 = height(root->right);
		int op1 = h1 + h2 + 1;
		int op2 = diameterOfTree(root->left);
		int op3 = diameterOfTree(root->right);

		return std::max(op1, std::max(op2, op3));
	}
}

int _fastDiameter(Node* root, int& max)
{
	if (root == NULL)
		return 0;

	else
	{
		int h1 = _fastDiameter(root->left, max);
		int h2 = _fastDiameter(root->right, max);

		max = std::max(max, h1 + h2 + 1);

		return 1 + std::max(h1, h2);
	}
}

int fastDiameter(Node* root)
{
	int max = -1;
	_fastDiameter(root, max);
	return max;
}

int sumOfNodesTree(Node* root, int& temp)
{
	if (root == NULL)
		return 0;

	else if (root->left == NULL && root->right == NULL)
		return root->data;

	else
	{
		int l = sumOfNodesTree(root->left, temp);
		int r = sumOfNodesTree(root->right, temp);

		int temp = root->data;
		root->data = l + r;

		return temp + root->data;
	}
}

class HBPair {
public:
	int height;
	bool balance;
};

HBPair _isHeightBalanced(Node* root)
{
	HBPair p;

	if (root == NULL)
	{
		p.height = 0;
		p.balance = true;
		return p;
	}

	HBPair left = _isHeightBalanced(root->left);
	HBPair right = _isHeightBalanced(root->right);

	p.height = std::max(left.height, right.height) + 1;

	if ( abs(left.height - right.height) <= 1 && left.balance && right.balance )
		p.balance = true;
	else
		p.balance = false;

	return p;
}

bool isHeightBalanced(Node* root)
{
	return _isHeightBalanced(root).balance;
}

//Very clever solution
void BFSRightView(Node* root)
{
	if (root == NULL)
		return;

	queue<Node*> q;
	vector<int> ans;

	q.push(root);

	while (!q.empty())
	{
		int n = q.size();

		//Push all children of current level
		for (int i = 1; i <= n; i++)
		{
			Node* node = q.front();
			q.pop();

			//At right most element
			if (i == n)
				ans.push_back(node->data);

			// Add left node to queue
			if (node->left != NULL)
				q.push(node->left);

			// Add right node to queue
			if (node->right != NULL)
				q.push(node->right);
		}
	}

	cout << ans;
}

void rightViewOptimised(Node* root, int level, int& maxLevel)
{
	if (root == NULL)
		return;

	//Discovered a new level
	if (maxLevel < level) {
		cout << root->data << " ";
		maxLevel = level;
	}

	rightViewOptimised(root->right, level + 1, maxLevel);
	rightViewOptimised(root->left, level + 1, maxLevel);
}

void leftViewOptimised(Node* root, int level, int& maxLevel)
{
	if (root == NULL)
		return;

	//Discovered a new level
	if (maxLevel < level) {
		cout << root->data << " ";
		maxLevel = level;
	}

	leftViewOptimised(root->left, level + 1, maxLevel);
	leftViewOptimised(root->right, level + 1, maxLevel);
}

void verticalOrder(Node* root, int hd, map<int, vector<int>> &m)
{
	if (root == NULL)
		return;

	m[hd].push_back(root->data);

	verticalOrder(root->left, hd - 1, m);
	verticalOrder(root->right, hd + 1, m);
}

void printVerticalOrder(Node* root)
{
	map<int, vector<int>> m;

	verticalOrder(root, 0, m);

	for (auto i : m)
	{
		cout << i.first << ": ";

		for (auto j : i.second)
			cout << j << " ";

		cout << endl;
	}
}

// map<int, int> _topViewBFSHelper(Node* root)
// {
// 	queue<int> q;
// 	q.push(root);

// 	map<int, int> levelOrder;

// 	int priority = 0;

// 	while (!q.empty())
// 	{
// 		Node* parent = q.front();
// 		q.pop();

// 		levelOrder[parent->data] = priority++;

// 		if (root->left)
// 			q.push(root->left);

// 		if (root->right)
// 			q.push(root->right);
// 	}

// 	return levelOrder;
// }

// void topView(Node* root, int hd, map<int, vector<int>> &m)
// {
// 	if (root == NULL)
// 		return;

// 	m[hd] = root->data;

// 	topView(root->left, hd - 1, m);
// 	topView(root->right, hd + 1, m);
// }

// void printTopView(Node* root)
// {
// 	map<int, int> verticalOrder;

// 	topView(root, 0, verticalOrder);

// 	map<int,int> levelOrder = _topViewBFSHelper(root);

// 	for (auto i : verticalOrder)
// 	{
// 		cout << i.first << ": ";

// 		for (auto j : i.second)
// 		{
// 			int print = -1;

// 			for (auto k : levelOrder)
// 			{

// 			}
// 		}

// 		cout << endl;
// 	}
// }

// For every Horizontal Distance we maintain a MAP with value
// PAIR of (Height, Node Value)
// For every HD we check whether the Node at HD hd is at a height
// more than current or not.
// If yes we need to update our Map.
// Basically for every HD we need Node with MAX height.

void _printBottomView(Node* root, int height, int hd, map<int, pair<int, int>> &m)
{
	if (root == NULL)
		return;

	if (m.find(hd) == m.end())
		m[hd] = make_pair(height, root->data);
	else
	{
		if (m[hd].first < height)
			m[hd] = make_pair(height, root->data);
	}

	_printBottomView(root->left, height + 1, hd - 1, m);
	_printBottomView(root->right, height + 1, hd + 1, m);
}

void printBottomView(Node* root)
{
	map<int, pair<int, int>> m;

	_printBottomView(root, 0, 0, m);

	for (auto i : m)
		cout << i.first << ": " << i.second.second << "\n";
}

void printLevelOrder2(Node* root, int k)
{
	if (root == NULL)
		return;

	else if (k == 0)
	{
		cout << root->data << " ";
		return;
	}

	printLevelOrder2(root->left, k - 1);
	printLevelOrder2(root->right, k - 1);
	return;
}

int printAtDistanceK(Node* root, Node* target, int k)
{
	if (root == NULL)
		return -1;

	if (root == target)
	{
		printLevelOrder2(target, k);
		return 0;
	}

	int DL = printAtDistanceK(root->left, target, k);

	if (DL != -1)
	{
		if (DL + 1 == k)
		{
			cout << root->data << " ";
		}

		else
		{
			printLevelOrder2(root->right, k - 2 - DL);
		}
		return 1 + DL;
	}

	int DR = printAtDistanceK(root->right, target, k);

	if (DR != -1)
	{
		if (DR + 1 == k)
		{
			cout << root->data << " ";
		}

		else
		{
			printLevelOrder2(root->right, k - 2 - DR);
		}

		return 1 + DR;
	}

	return -1;
}

bool ancestorArray(Node* root, Node* target, stack<Node*>& anc)
{
	if (root == NULL)
		return false;

	if (root->data == target->data)
	{
		anc.push(root);
		return true;
	}

	bool left = ancestorArray(root->left, target, anc);
	bool right = ancestorArray(root->right, target, anc);

	if (left || right)
	{
		anc.push(root);
		return true;
	}

	return false;
}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q)
{
	if (root == NULL)
		return NULL;

	if (p == q)
		return p;

	//Find if both nodes actually exist
	stack<Node*> s1;
	stack<Node*> s2;

	int flag = 0;
	if (ancestorArray(root, p, s1))
		flag = 1;
	Node* prev = NULL;

	if (ancestorArray(root, q, s2) && flag == 1)
	{

		while (!s1.empty() && !s2.empty())
		{
			Node* el1 = s1.top();
			Node* el2 = s2.top();

			s1.pop();
			s2.pop();

			if (el1->data == el2->data)
				prev = el1;
			//Point where they diverge
			else
				break;
		}
	}

	return prev;

}

void preOrderIterative1(Node* root)
{
	stack<Node*> s;
	while (1)
	{
		while (root)
		{
			cout << root->data << " ";
			s.push(root);
			root = root->left;
		}

		if (s.empty())
			break;

		Node* temp = s.top();
		s.pop();
		root = temp->right;
	}
}

void preOrderIterative2(Node* root)
{
	stack<Node*> s;
	while (1)
	{
		while (root)
		{
			cout << root->data << " ";
			s.push(root);
			root = root->left;
		}

		if (s.empty())
			break;

		Node* temp = s.top();
		s.pop();
		root = temp->right;
	}
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/**
	SAMPLE INPUT
	1.

	1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1

	1
	2 3
	4 5
	6 7 8 9
	10 11

	2.

	8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 14 13 -1 -1 -1 -1

	8
	10 3
	1 6 14
	9 7 13

	3.

	1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

	1
	2 3
	4 5 6 7

	**/

	Node* root;
	root = buildTree();
	// preOrderIterative1(root);

	// int temp = 0;
	// sumOfNodesTree(root, temp);

	// cout << height(root);

	// cout << countNodes(root);
	int minValue = -1;
	rightViewOptimised(root, 0, minValue);
	// NEWLINE;
	// BFS(root);
	// NEWLINE;
	// // Node* target = root->left->left;
	// // printAtDistanceK(root, target, 3);

	// Node* node1 = root->left;
	// Node* node2 = root->left->right->right;

	// Node* ans = lowestCommonAncestor(root, node1, node2);

	// cout << "LCA of " << node1->data <<
	//      " and " << node2->data << " is: " << ans->data;
	// int max = -1;
	// printBottomView(root);
}