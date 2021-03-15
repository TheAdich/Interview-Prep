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

const char* EmptyListException = "Empty List";
const char* NullPointerException = "NULL Pointer Exception";

class LinkedList {
	class Node {
	public:
		int data;
		Node* next = NULL;

		Node(int data) {
			this->data = data;
		}
	};

	Node* head = NULL;
	Node* tail = NULL;
	int size = 0;

public:
	int length() {
		return this->size;
	}

	bool isEmpty() {
		return this->size == 0;
	}

private:
	//add.===========================

	void addFirstNode(Node* node) {
		if (this->size == 0) {
			this->head = node;
			this->tail = node;
		} else {
			node->next = head;
			this->head = node;
		}
		++this->size;
	}

	void addLastNode(Node* node) {
		if (this->size == 0) {
			this->head = node;
			this->tail = node;
		} else {
			this->tail->next = node;
			this->tail = node;
		}
		++this->size;
	}
	//remove.===========================

	//We will never get empty list here.
	//Already made check for it.
	Node* removeFirstNode() {
		Node* rn = this->head;
		if (this->size == 1) {
			this->head = NULL;
			this->tail = NULL;
		} else {
			this->head = this->head->next;
		}
		rn->next = NULL;
		--this->size;
		return rn;
	}

	Node* removeLastNode() {
		Node* rn = this->tail;
		if (this->size == 1) {
			this->head = NULL;
			this->tail = NULL;
		} else {
			Node* secondLastNode = getNodeAt(this->size - 2);
			this->tail = secondLastNode;
			this->tail->next = NULL;
		}
		rn->next = NULL;
		--this->size;
		return rn;
	}

	Node* getNodeAt(int idx) {
		Node* itr = this->head;
		while (idx--) itr = itr->next;
		return itr;
	}

	Node* removeNodeAt(int idx) {
		if (idx == 0)
			return removeFirstNode();
		else {
			Node* prev = getNodeAt(idx - 1);
			Node* rnode = prev->next;
			Node* next = rnode->next;

			prev->next = next;
			rnode->next = NULL;

			--this->size;

			return rnode;
		}
	}

	void addNodeAt(int idx, Node* node) {
		if (idx == 0)
			addFirstNode(node);
		else if (idx == this->size)
			addLastNode(node);
		else {
			Node* prev = getNodeAt(idx - 1);
			Node* fwd = prev->next;
			prev->next = node;
			node->next = fwd;
			++this->size;
		}
	}

public:
	void addFirst(int data) {
		Node* node = new Node(data);
		addFirstNode(node);
	}

	void addLast(int data) {
		Node* node = new Node(data);
		addLastNode(node);
	}

	int removeFirst() throw(const char*) {
		if (this->size == 0) {
			throw EmptyListException;
		} else {
			Node* rnode = removeFirstNode();
			return rnode->data;
		}
	}

	int removeAt(int idx) throw(const char*) {
		if (idx < 0 || idx >= this->size) {
			throw NullPointerException;
		}
		Node* rn = removeNodeAt(idx);
		return rn->data;
	}

	int getFirst() throw(const char*) {
		if (this->size == 0)
			throw EmptyListException;
		return head->data;
	}

	int getLast() throw(const char*) {
		if (this->size == 0)
			throw EmptyListException;
		return tail->data;
	}

	void addAt(int idx, int data) throw(const char*) {
		if (idx < 0 || idx > this->size)
			throw NullPointerException;

		Node* nnode = new Node(data);
		addNodeAt(idx, nnode);
	}

	friend ostream& operator<<(ostream& os, const LinkedList& ll)
	{
		Node* itr = ll.head;
		if (ll.size == 0) {
			os << "[]";
		} else {

			os << "[" << itr->data;
			itr = itr->next;
			while (itr) {
				os << ", " << itr->data;
				itr = itr->next;
			}
			os << "]";
		}
		return os;
	}
};

int main()
{
	LinkedList ll;
	for (int i = 0; i < 10; i++) {
		ll.addLast(i * 10);
	}
	cout << ll;
}