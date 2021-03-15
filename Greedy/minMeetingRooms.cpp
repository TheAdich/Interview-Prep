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

class Interval {
public:
	int start, end;
	Interval() {}
	Interval(int start, int end) {
		this->start = start;
		this->end = end;
	}
};


ostream& operator<<(ostream& os, const Interval& i)
{
	os << "(" << i.start << ", " << i.end << ")";
	return os;
}


class Compare {
public:
	bool operator()(Interval A, Interval B) {
		return A.end > B.end;
	}
};

int minMeetingRooms(vector<Interval> &intervals) {
	int n = intervals.size();

	sort(intervals.begin(), intervals.end(), [&](Interval A, Interval B) {return A.start < B.start;});
	priority_queue<Interval, vector<Interval>, Compare> minHeap;

	for (auto pair : intervals)
		cout << pair << " ";

	minHeap.push(intervals[0]);

	for (int i = 1; i < n; i++) {
		Interval curInterval = minHeap.top();
		Interval newInterval = intervals[i];
		deb(curInterval);
		deb(newInterval);
		if (newInterval.start < curInterval.end) {
			minHeap.push(newInterval);
		} else {
			minHeap.pop();
			minHeap.push(newInterval);
		}
	}

	return minHeap.size();
}

int main()
{
	int n;
	cin >> n;

	vector<Interval> activities(n);

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		activities[i] = {x, y};
	}
	cout << minMeetingRooms(activities);
}