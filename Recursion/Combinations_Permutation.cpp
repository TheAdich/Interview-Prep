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
		if (i != v.size() - 1)  os << "";
	}
	return os;
}

//For every box, item taken / not taken.
void combinations1(string asf, int boxes, int items) {
	if (asf.size() == boxes) {
		if (items == 0) {
			cout << asf << endl;
		}
		return;
	}
	combinations1(asf + 'i', boxes, items - 1);
	combinations1(asf + '-', boxes, items);
}

//For every item, consider all boxes
/**



1 _ _ _ 2 X
1 _ _ 2 _ X _ 1 _ _ 2
1 _ 2 _ _ X _ 1 _ 2 _
1 2 _ _ _ X _ 1 2 _ _
1 _ _ _ _ X _ 1 _ _ _ X _ _ 1 _ _ X _ _ _ 1 _ X _ _ _ _ 1
				_ _ _ _ _
Number of Level = Number of Items.
Every Level consider an Item.
**/
void permutation1(string asf, int items, char current) {
	if (items == 0) {
		cout << asf << endl;
		return;
	}
	for (int b = 0; b < asf.size(); b++) {
		if (asf[b] == '0') {
			asf[b] = current;
			permutation1(asf, items - 1, current + 1);
			asf[b] = '0';
		}
	}
}

//For every item, consider all boxes
/**



i _ _ _ i X
i _ _ i _ X _ i _ _ i
i _ i _ _ X _ i _ i _
i i _ _ _ X _ i i _ _
i _ _ _ _ X _ i _ _ _ X _ _ i _ _ X _ _ _ i _ X _ _ _ _ i
				_ _ _ _ _
Number of Level = Number of Items.
**/
void combinations2(string asf, int boxes, int items, int llb) {
	if (items == 0) {
		cout << asf << endl;
		return;
	}
	for (int b = llb; b < boxes; b++) {
		if (asf[b] == '-') {
			asf[b] = 'i';
			combinations2(asf, boxes, items - 1, b + 1);
			asf[b] = '-';
		}
	}
}

//For every box, consider a unseen / valid item
/**



Based on itemsVisitedArray check what can be placed at new index
0 0 0 0 0 X 1 0 0 0 0 X 2 0 0 0 0 X 3 0 0 0 0
  ^           ^           ^           ^
				  0 0 0 0 0
				    ^
**/
void permutation2(int cb, int boxes, vector<bool> items, int used, string asf) {
	if (cb == boxes) {
		if (used == 0) {
			cout << asf << endl;
		}
		return;
	}

	//Move to next box
	permutation2(cb + 1, boxes, items, used, asf + '0');
	//Choose something from Items
	for (int i = 0; i < items.size(); i++) {
		if (items[i] == false) {
			items[i] = true;
			permutation2(cb + 1, boxes, items, used - 1, asf + (char)('0' + i + 1));
			items[i] = false;
		}
	}
}

int main()
{
	int boxes, items;
	cin >> boxes >> items;
	string asf = "";
	// for (int i = 0; i < boxes; i++)
	//     asf += '0';
	// vector<bool> item(items, false);
	// permutation2(0, boxes, item, items, asf);
	// combinations1(boxes, items, asf);

	permutation2(0, boxes, {0, 0}, items, asf);
}