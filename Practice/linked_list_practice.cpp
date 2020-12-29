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

class ListNode {
public:
	int val;
	ListNode* next;

	ListNode(int val)
	{
		this->val = val;
		next = NULL;
	}
};

ListNode* build_ll()
{
	int n;
	cin >> n;

	ListNode* head = NULL;
	ListNode* tail = NULL;

	while (n)
	{
		int d;
		cin >> d;

		ListNode* newListNode = new ListNode(d);

		if (head == NULL)
		{
			head = newListNode;
			tail = newListNode;
		}
		else
		{
			tail->next = newListNode;
			tail = tail->next;
		}
		--n;
	}

	return head;
}

void print_ll(ListNode* head)
{
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	return;
}

void _reverse(ListNode* head, ListNode* &newHead)
{
	if (head == NULL)
		return;

	if (head->next == NULL)
	{
		newHead = head;
		return;
	}

	_reverse(head->next, newHead);

	ListNode* q = head->next;
	q->next = head;
	head->next = NULL;

	return;
}

ListNode* reverse(ListNode* head)
{
	ListNode* newHead;
	_reverse(head, newHead);
	return newHead;
}

ListNode* reverse_iterative(ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode* prev = NULL;
	ListNode* cur = head;

	while (cur)
	{
		ListNode* next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	return prev;
}

ListNode* merge_two_sorted_ll(ListNode* head1, ListNode* head2)
{
	ListNode* result;

	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;

	if (head1->val < head2->val)
	{
		result = head1;
		result->next = merge_two_sorted_ll(head1->next, head2);
	}
	else
	{
		result = head2;
		result->next = merge_two_sorted_ll(head1, head2->next);
	}
	return result;
}

ListNode* pairwise_swap(ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode* newHead = head->next;
	ListNode* p = head;
	ListNode* q;
	ListNode* temp;

	while (true)
	{
		q = p->next;
		temp = q->next;

		q->next = p;

		if (temp == NULL || temp->next == NULL)
		{
			p->next = temp;
			return newHead;
		}

		p->next = temp->next;
		p = temp;
	}

	return newHead;
}

class ListNodeCompare {
public:
	bool operator()(ListNode* A, ListNode* B) {
		return A->val > B->val;
	}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
	priority_queue<ListNode*, vector<ListNode*>, ListNodeCompare> minHeap;

	int k = lists.size();

	for (int i = 0; i < k; i++)
		minHeap.push(lists[i]);

	ListNode* result = new ListNode(-1);
	ListNode* ptr = result;

	while (!minHeap.empty())
	{
		ListNode* cur = minHeap.top();
		minHeap.pop();

		ptr->next = cur;
		ptr = ptr->next;

		cur = cur->next;

		if (cur)
			minHeap.push(cur);

	}
	return result->next;
}

int minimalFilps(string bits)
{
	int n = bits.length();

	// two arrays will keep the count for number
	// of 0s' and 1s' to be flipped while
	// traversing from left to right and right to
	// left respectively
	vector<int> flipsFromLeft(n);
	vector<int> flipsFromRight(n);

	// Fill flipsFromLeft[]
	int flips = 0;
	for (int i = 0; i < n; i++) {
		if (bits[i] == '0')
			flips++;
		flipsFromLeft[i] = flips;
	}

	cout << flipsFromLeft << endl;

	// Fill flipsFromRight[]
	flips = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (bits[i] == '1')
			flips++;
		flipsFromRight[i] = flips;
	}

	cout << flipsFromRight << endl;

	// initialize minFlip to highest int value. If sum
	// of leftflip and rightFlip is smaller than minflips,
	// then update minFlips
	int minFlips = INT_MAX;
	for (int i = 1; i < n; i++) {
		if (flipsFromLeft[i - 1] + flipsFromRight[i] < minFlips)
			minFlips = flipsFromLeft[i - 1] + flipsFromRight[i];
	}

	return minFlips;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	// ListNode* head1 = build_ll();
	// ListNode* head2 = build_ll();
	// ListNode* head3 = build_ll();
	// vector<ListNode*> v = {head1, head2, head3};
	// print_ll(mergeKLists(v));
	string bits = "1011000";
	cout << minimalFilps(bits) << endl;
	return 0;
}