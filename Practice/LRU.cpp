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

    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class DLL {
public:
    int capacity = 0;
    Node* head = NULL;
    Node* tail = NULL;

    void push_front(int c)
    {
        Node* val = new Node(c);

        if (head == NULL)
        {
            head = val;
            tail = val;
        }
        else
        {
            val->next = head;
            head->prev = val;
            head = val;
        }
        ++capacity;
        return;
    }

    void push_back(int c)
    {
        Node* val = new Node(c);

        if (head == NULL)
        {
            head = val;
            tail = val;
            ++capacity;
            return;
        }
        else
        {
            val->prev = tail;
            tail->next = val;
            tail = val;
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

    void delete_front() {
        delete_node(head);
    }

    int peek_front()
    {
        if (head != NULL)
            return head->data;
        else
            return -1;
    }

    void printDLL()
    {
        while (head != NULL)
        {
            cout << head->data << "->";
            head = head->next;
        }
    }
};

class LRUCache {
    DLL dll;
    map<int, Node*> map;
    int size = 0;
public:

    LRUCache(int size) {
        this->size = size;
    }

    void refer(int x) {
        //Not found
        if (map.find(x) == map.end()) {

            if (dll.capacity >= size) {
                map.erase(dll.peek_front());
                dll.delete_front();
            }
        }
        else {
            dll.delete_node(map[x]);
            map.erase(x);
        }

        dll.push_back(x);
        map[x] = dll.tail;
    }

    void print() {
        dll.printDLL();
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
    l.print();

}