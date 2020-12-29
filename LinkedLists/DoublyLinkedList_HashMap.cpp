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

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

template <typename T>
class DLL {

    Node<T>* head = NULL;
    Node<T>* tail = NULL;
public:

    void push_front(T c)
    {
        Node<T>* val = new Node<T>(c);

        if (head == NULL)
        {
            head = val;
            tail = val;
            return;
        }
        else
        {
            val->next = head;
            head->prev = val;
            head = val;

            return;
        }
    }

    void push_back(T c)
    {
        Node<T>* val = new Node<T>(c);

        if (head == NULL)
        {
            head = val;
            tail = val;
            return;
        }
        else
        {
            val->prev = tail;
            tail->next = val;
            tail = val;

            return;
        }
    }

    void delete_node(Node<T>* cur)
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

        delete(cur);

        return;
    }

    Node<T>* get_kth_element(int k)
    {
        Node<T>* temp = head;
        while (temp != NULL && temp->next != NULL && k != 1)
        {
            temp = temp->next;
            --k;
        }

        return temp;
    }

    Node<T>* get_node_head()
    {
        return head;
    }

    Node<T>* get_node_tail()
    {
        return tail;
    }

    void peek_back()
    {
        if (tail != NULL)
            cout << "\nList Back: " << tail->data << endl;
        else
            cout << "List empty\n";

        return;
    }

    void peek_front()
    {
        if (head != NULL)
            cout << "\nList Front: " << head->data << endl;
        else
            cout << "List empty\n";

        return;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);
#endif

    //Map
    map<char, Node<char>*> m;

    // Doubly Linked List
    DLL<char> dll;

    char c;
    cin >> c;

    while (c != '#')
    {
        dll.peek_front();

        // If not present in Map
        // Add that charachter with it's reference
        if (m.find(c) == m.end())
        {
            dll.push_back(c);
            m[c] = dll.get_node_tail();
        }

        // Get reference of that charachter from Map
        // Delete it
        else
        {
            // Already deleted once. It's a repeated charachter
            if (m[c] != NULL)
            {
                dll.delete_node(m[c]);
                m[c] = NULL;
            }
        }
        cin >> c;
    }

    dll.peek_front();


    // dll.push_back('a');
    // dll.push_back('b');
    // dll.push_back('c');
    // dll.push_back('d');
    // dll.push_back('e');
    // dll.push_back('f');
    // dll.delete_node(dll.get_kth_element(3));
    // dll.printDLL();
}