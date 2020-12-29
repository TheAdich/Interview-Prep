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

Unique Prefix Array

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov
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
	int freq = 1;
	unordered_map<char, Node*> children;
	bool terminal;

	Node(char data) {
		this->data = data;
		terminal = false;
	}
};

class Trie {
	Node* root;
	int count;
public:

	Trie() {
		root = new Node('\0');
		count = 0;
	}

	void insert(string word) {
		Node* temp = root;
		for (int i = 0; word[i] != '\0'; i++) {
			char ch = word[i];

			// If charachter found in one of the branch
			if (temp->children.find(ch) != temp->children.end()) {
				temp = temp->children[ch];
				++temp->freq;
			}

			//
			else {
				Node* newNode = new Node(ch);
				temp->children[ch] = newNode;
				temp = newNode;
			}
		}
		temp->terminal = true;
	}

	string unique_prefix(string word) {
		Node* temp = root;
		string output = "";

		for (int i = 0; word[i] != '\0'; i++) {
			char ch = word[i];

			output += ch;

			temp = temp->children[ch];

			if (temp->freq == 1)
				return output;
		}

		return "-1";
	}
};

int main()
{
	Trie trie;

	int n;
	cin >> n;
	vector<string> words;
	// Make prefix tree
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		words.push_back(word);
		trie.insert(word);
	}

	for (int i = 0; i < n; i++) {
		cout << trie.unique_prefix(words[i]) << endl;
	}

	// cout << trie.find("dog") << endl;
}