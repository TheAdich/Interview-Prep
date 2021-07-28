/**
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

// C++ template to print vector container elements
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	for (int i = 0; i < v.size(); ++i) {
		os << v[i];
		if (i != v.size() - 1)  os << " ";
	}
	return os;
}

map<string, int> priority;
//true -> left to right
//false -> right to left
map<string, bool> associativity;

void initialise() {
	priority["*"] = 3;
	priority["/"] = 3;
	priority["+"] = 2;
	priority["-"] = 2;
	priority["="] = 1;

	associativity["*"] = true;
	associativity["/"] = true;
	associativity["+"] = true;
	associativity["-"] = true;
	associativity["="] = false;
}

bool isOperator(string word) {
	if (word == "*" || word == "/" || word == "+" || word == "-" || word == "=")
		return true;
	return false;
}

string evaluate(string val1, string val2, string op) {
	if (op == "*")
		return to_string(stoi(val1) * stoi(val2));
	if (op == "/")
		return to_string(stoi(val1) / stoi(val2));
	if (op == "+")
		return to_string(stoi(val1) + stoi(val2));
	if (op == "-")
		return to_string(stoi(val1) - stoi(val2));
	return val1 + " = " + val2;
}

string infixEvaluate(vector<string> &str) {
	initialise();
	stack<string> operands;
	stack<string> operators;
	for (auto word : str) {
		if (word == "(")
			operators.push(word);
		else if (isOperator(word)) {
			if (!operators.empty()) {
				while (!operators.empty()
				        && operators.top() != "("
				        && priority[operators.top()] >= priority[word]) {
					string val2 = operands.top(); operands.pop();
					string val1 = operands.top(); operands.pop();
					string op = operators.top(); operators.pop();
					operands.push(evaluate(val1, val2, op));
				}
			}
			operators.push(word);
		} else if (word == ")") {
			while (operators.top() != "(") {
				string val2 = operands.top(); operands.pop();
				string val1 = operands.top(); operands.pop();
				string op = operators.top(); operators.pop();
				string ans = evaluate(val1, val2, op);
				operands.push(ans);
			}
			operators.pop();
		}
		else {
			operands.push(word);
		}
	}

	while (!operators.empty()) {
		string val2 = operands.top(); operands.pop();
		string val1 = operands.top(); operands.pop();
		string op = operators.top(); operators.pop();
		operands.push(evaluate(val1, val2, op));
	}

	return operands.top();
}

int main()
{
	vector<string> str;
	string word;
	while (cin >> word) {
		if (word.size() >= 2) {
			for (int i = 0; i < word.size(); i++) {
				string s;
				s += word[i];
				str.push_back(s);
			}
		}
		else
			str.push_back(word);
	}
	cout << infixEvaluate(str);
}