/**
 * Muhammad Ali, one of my great heroes, had a great line
 * in the '70s when he was asked "How many sit-ups do you do?"
 * He said, "I don't count my sit-ups. I only start counting when
 * it starts hurting. When I feel pain, that's when I start counting
 * because that's when it really counts". That's what makes you a
 * champion. And that's the way it is with everything.
 * ~ Arnold Schwarzenegger
**/

/**
https://leetcode.com/problems/design-add-and-search-words-data-structure/
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
	unordered_map<char, Node*> children;
	bool terminal;

	Node(char data) {
		this->data = data;
		terminal = false;
	}
};

class Trie {
	Node* root = new Node('\0');

public:
	int count = 0;
	Trie() {}

	void insert(string word) {
		Node* temp = root;
		for (int i = 0; word[i] != '\0'; i++) {
			char ch = word[i];

			// If charachter found in one of the branch
			if (temp->children.find(ch) != temp->children.end()) {
				temp = temp->children[ch];
			}

			//
			else {
				Node* newNode = new Node(ch);
				temp->children[ch] = newNode;
				temp = newNode;
			}
		}
		temp->terminal = true;
		++count;
	}

	bool _find(Node* temp, string word) {
		for (int i = 0; word[i] != '\0'; i++) {
			char ch = word[i];

			if (ch == '.') {
				for (auto child : temp->children) {
					deb(child.first);
					bool success = _find(child.second, word.substr(i + 1));
					if (success)
						return true;
				}
			}
			if (temp->children.find(ch) != temp->children.end()) {
				temp = temp->children[ch];
			}
			else
				return false;
		}

		return temp->terminal;
	}

	bool find(string word) {
		return _find(root, word);
	}
};

int main()
{
	Trie trie;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		trie.insert(word);
	}

	if (trie.find("co..a"))
		cout << "YES";
	else
		cout << "NO";
}