/**
 * Muhammad Ali, one of my great heroes, had a great line
 * in the '70s when he was asked "How many sit-ups do you do?"
 * He said, "I don't count my sit-ups. I only start counting when
 * it starts hurting. When I feel pain, that's when I start counting
 * because that's when it really counts". That's what makes you a
 * champion. And that's the way it is with everything.
 * ~ Arnold Schwarzenegger
**/

//Sunday 24th January 2021
//Advanced Data Structures Introduction

//https://www.codechef.com/cptutorials?itm_medium=navmenu&itm_campaign=cptutorials

/**
1. Tree
	1.1 Segment Trees -> Only Coding Test
		1.11 Build, Query, Update
		1.12 Lazy Propagation (Not so important w.r.t interviews)
		1.13 Merge Sort Tree
		1.14 Persistence Tree (Not important)
		1.15 Time Complexity (Important)
		1.16 Fenwick Trees questions can be solved using ST. No need to learn it.

	1.2 Trie Prefix Trie

	1.3 Heaps (One of the MOST IMPORTANT)
		1.31 Kth order Statistics
		1.32 Heap Sort
		1.33 Online Queries
		1.34 Top k trending tweets (System Design)

	1.4 AVL Trees (Balanced Binary Search Tree)
		1.41 Just know usage
		1.42 Build (Not very reqd)

	1.5 B+ Tree
		1.51 Indexing in DBMS

	1.6 Red Black not important

	1.7 DP on Trees

2. Graph (Super-Set of Tree)
	Most important Advanced DS

	2.1 BFS
		2.11 0-1
		2.12 Matrix

	2.2 DFS
		2.21 DFS Tree

	2.3 Bi-Partite

	2.4 MST

	2.5 Shortest

	2.6 Articulation Point (Amazon direct)

	2.7 Krosarajul Algorithm

	2.8 DP on graph not required

3. C++ STL
	3.1 Policy Based Data Structures (Sprinklr, Dunzo, Directi Asked)
	(https://gcc.gnu.org/onlinedocs/libstdc++/manual/policy_data_structures.html)

	You have set of integers.
	Find kth largest element, or number of element less than any element x.

4. Doubly Linked List
	4.1 Cache
	4.2 Non Repeating Charachter in a stream.

5. Bit Manipulation HackerEarth (https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/tutorial/)

6. BitSet C++

7. Disjoint Set Algorithms, Union Find, Bi-Connectivity, Inverse Ackerman Function, Offline/Online queries, Cycle Detection, MST

Online -> Answer that query at that time
Offline -> Store all queries and do computation

//Other

8. Stack
	8.1 Min Stack
	8.2 Next Larger, etc

9. Grundy Game Theory
**/

/**
DP on Trees

Q. You have a Binary Tree, find the diameter (longest path any node to any node).

Q. You have BT, calculate it's vertex cover (subset of vertices such that every edge going from u to v of the graph either 'u' or 'v' in the set)

Q. Placing cameras in trees
**/

/**
You have an array UNSORTED, find kth largest element.

This is kth order statistics
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

	}
}