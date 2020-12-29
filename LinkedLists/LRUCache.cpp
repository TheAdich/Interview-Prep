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
	Node* next;
	Node* prev;
	Node(int data) {
		this->data = data;
		next = NULL;
		prev = NULL;
	}
};

class DLL {
	Node* head = NULL;
	Node* tail = NULL;
	int capacity = 0;
public:

	void push_back(int x) {

		Node* cur = new Node(x);

		if (head == NULL) {
			head = cur;
			tail = cur;
			++capacity;
			return;
		}
		else
		{
			tail->next = cur;
			cur->prev = tail;
			tail = cur;
			++capacity;
			return;
		}
	}

	void delete_node(Node* cur)
	{
		if (head == NULL || cur == NULL)
			return;

		if (head == cur)
			head = cur->next;

		if (tail == cur)
			tail = tail->prev;

		if (cur->next != NULL)
			cur->next->prev = cur->prev;

		if (cur->prev != NULL)
			cur->prev->next = cur->next;

		--capacity;
		delete(cur);

		return;
	}

	int peek_front() {
		if (head == NULL)
			return -1;
		else
			return head->data;
	}

	Node* peek_back_Node() {
		if (tail == NULL)
			return NULL;
		else
			return tail;
	}

	int peek_back() {
		if (tail == NULL)
			return -1;
		else
			return tail->data;
	}

	void delete_front() {
		delete_node(head);
	}

	void print_dll() {
		Node* temp = head;
		while (temp) {
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		return;
	}

	int get_capacity() {
		return capacity;
	}
};

class LRUCache {
	int page_faults = 0;
	int size = 0;

	DLL dll;
	map<int, Node*> map;
public:
	LRUCache(int size) {
		this->size = size;
	}

	void refer(int x) {
		if (map.find(x) == map.end()) {

			if (dll.get_capacity() >= size) {
				map.erase(dll.peek_front());
				dll.delete_front();
			}
			++page_faults;
		}
		else {
			dll.delete_node(map[x]);
			map.erase(x);
		}

		dll.push_back(x);
		map[x] = dll.peek_back_Node();
	}

	void compute_page_faults() {
		cout << "Page Faults: " << page_faults << endl;
	}

	void print_cache() {
		dll.print_dll();
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	LRUCache l(3);

	l.refer(1);
	l.refer(2);
	l.refer(3);
	l.refer(4);
	l.refer(1);
	l.refer(3);
	l.print_cache();
}