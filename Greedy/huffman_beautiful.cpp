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

#define fi              first
#define se              second
#define ll              long long
#define deb(x)          cout << #x << "=" << x << endl
#define deb2(x, y)      cout << #x << "=" << x << "," << #y << "=" << y << endl
#define mod             1000000007

// C++ template to print vector container elements
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	for (int i = 0; i < v.size(); ++i) {
		os << v[i];
		if (i != v.size() - 1)  os << " ";
	}
	return os;
}

class Node {
public:
	char val = '#';
	int freq;
	Node* left = NULL;
	Node* right = NULL;
	Node(char val, int freq) {
		this->val = val;
		this->freq = freq;
	}
	Node(char val, int freq, Node* left, Node* right) {
		this->val = val;
		this->freq = freq;
		this->left = left;
		this->right = right;
	}
};

class Compare {
public:
	bool operator()(Node* A, Node* B) {
		return A->freq > B->freq;
	}
};

vector<string> result;
void preOrder(Node* root, string asf) {
	if (root == NULL)
		return;
	if (root->val != '#') {
		result.push_back(asf);
		return;
	}
	preOrder(root->left, asf + '0');
	preOrder(root->right, asf + '1');
}

vector<string> huffmanCodes(string str, vector<int> f, int N)
{
	// minHeap of (frequency, char ASCII value)
	priority_queue<Node*, vector<Node*>, Compare> minHeap;
	for (int i = 0; str[i] != '\0'; i++) {
		minHeap.push(new Node(str[i], f[i]));
	}
	Node* root = NULL;
	while (!minHeap.empty()) {
		if (minHeap.size() == 1) {
			root = minHeap.top(); minHeap.pop();
		} else {
			Node* left = minHeap.top(); minHeap.pop();
			Node* right = minHeap.top(); minHeap.pop();
			Node* pushFreq = new Node('#', left->freq + right->freq, left, right);
			minHeap.push(pushFreq);
		}
	}

	preOrder(root, "");

	return result;
}

int main()
{
	cout << huffmanCodes("qwertyuiop", {1, 8, 32, 39, 49, 63, 72, 76, 80, 90}, 6);
}