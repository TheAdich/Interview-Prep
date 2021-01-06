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

vector<char> infix_to_postfix(string str, map<char, int> priority, map<char, string> associativity) {

	vector<char> postfix;
	stack<char> s;

	for (auto ch : str) {
		if (ch >= 'a' && ch <= 'z') {
			postfix.push_back(ch);
		}
		else {
			while (!s.empty() && priority[s.top()] >= priority[ch]) {
				if (s.top() == ch && associativity[ch] == "RL")
					break;
				postfix.push_back(s.top());
				s.pop();
			}
			s.push(ch);
		}
	}

	while (!s.empty()) {
		postfix.push_back(s.top());
		s.pop();
	}

	return postfix;
}

int main()
{

	char str[1000];
	cin.getline(str, 1000);

	map<char, int> priority;
	priority['='] = 1;
	priority['+'] = priority['-'] = 2;
	priority['*'] = priority['/'] = 3;

	map<char, string> associativity;
	associativity['='] = "RL";
	associativity['+'] = associativity['-'] = "LR";
	associativity['*'] = associativity['/'] = "LR";

	cout << infix_to_postfix(str, priority, associativity);

	/**
		d*e-a=b/c=f*g-h
		Expected Output: d e * a - b c / f g * h - = =
	**/
}