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

Node* preOrderBuild()
{
	int d;
	cin >> d;

	if (d == -1)
		return NULL;

	Node* root = new Node(d);

	root->left = preOrderBuild();
	root->right = preOrderBuild();

	return root;
}

void print_inorder(Node* head)
{
	if (head == NULL)
		return;

	print_inorder(head->left);
	cout << head->data << " ";
	print_inorder(head->right);
}

Node* find_target_node(Node* root, int target)
{
	if (root == NULL)
		return NULL;

	if (root->data == target)
		return root;

	Node* left = find_target_node(root->left, target);
	if (left != NULL)
		return left;

	Node* right = find_target_node(root->right, target);
	return right;
}

void parent_store(Node* root, Node* parent, map<Node*, vector<Node*>>& adjList)
{
	if (root == NULL)
		return;

	if (adjList.find(root) == adjList.end())
		if (parent)
		{
			adjList[root].push_back(parent);
			adjList[parent].push_back(root);
		}

	parent_store(root->left, root, adjList);
	parent_store(root->right, root, adjList);

}

vector<int> all_nodes_distance_k_from_target(Node* root, int target, int k)
{
	vector<int> result;

	Node* target_node = find_target_node(root, target);

	if (target_node != NULL)
	{
		map<Node*, vector<Node*>> adjList;

		//Convert Tree to a Graph
		parent_store(root, NULL, adjList);

		//Apply BFS for K level starting from target_node

		queue<Node*> q;
		map<Node*, bool> visited;

		q.push(target_node);
		visited[target_node] = true;

		int dist = 0;

		while (!q.empty())
		{
			if (dist == k) {
				while (!q.empty()) {
					result.push_back(q.front()->data);
					q.pop();
				}
			}

			int n = q.size();

			for (int i = 0; i < n; i++)
			{
				Node* temp = q.front();
				q.pop();

				for (auto j : adjList[temp])
				{
					if (visited[j] == false)
					{
						q.push(j);
						visited[j] = true;
					}
				}
			}

			++dist;
		}
	}

	if (result.size() == 0)
		return { -1};
	return result;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	Node* head = preOrderBuild();
	print_inorder(head);
	cout << endl;
	cout << all_nodes_distance_k_from_target(head, 3, 2);
}