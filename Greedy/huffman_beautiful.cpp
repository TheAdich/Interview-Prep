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
	char letter;
	int freq;
	TreeNode* left = NULL;
	TreeNode* right = NULL;

	TreeNode(char letter, int freq) {
		this->letter = letter;
		this->freq = freq;
	}
};

class Compare {
public:
	bool operator()(TreeNode* A, TreeNode* B) {
		return A->freq > B->freq;
	}
};

void preOrderTraverse(TreeNode* root, string output) {
	if (root == NULL)
		return;

	if (root->left == NULL || root->right == NULL) {
		cout << root->letter << ": " << output << endl;
		// cout << output << " ";
		return;
	}

	//Go left. Add 0 in path
	preOrderTraverse(root->left, output + '0');
	//Go right. Add 1 in path
	preOrderTraverse(root->right, output + '1');
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;

		//Create minHeap based on frequencies
		priority_queue<TreeNode*, vector<TreeNode*>, Compare> minHeap;
		for (int i = 0; str[i] != '\0'; i++) {
			int freq; cin >> freq;
			minHeap.push(new TreeNode(str[i], freq));
		}

		//Build Tree
		while (minHeap.size() > 1) {
			TreeNode* a = minHeap.top(); minHeap.pop();
			TreeNode* b = minHeap.top(); minHeap.pop();

			TreeNode* left = (a->freq < b->freq) ? a : b;
			TreeNode* right = (a->freq > b->freq) ? a : b;

			TreeNode* top = new TreeNode('$', a->freq + b->freq);

			top->left = left;
			top->right = right;

			minHeap.push(top);
		}

		TreeNode* root = minHeap.top(); minHeap.pop();
		preOrderTraverse(root, "");

	}
}