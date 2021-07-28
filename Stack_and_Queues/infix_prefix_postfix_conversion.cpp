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

string evaluatePostfix(string val1, string val2, string op) {
	return val1 + val2 + op;
}

string infixToPostfix(vector<string> &str) {
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
					operands.push(evaluatePostfix(val1, val2, op));
				}
			}
			operators.push(word);
		} else if (word == ")") {
			while (operators.top() != "(") {
				string val2 = operands.top(); operands.pop();
				string val1 = operands.top(); operands.pop();
				string op = operators.top(); operators.pop();
				string ans = evaluatePostfix(val1, val2, op);
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
		operands.push(evaluatePostfix(val1, val2, op));
	}

	return operands.top();
}

string evaluatePrefix(string val1, string val2, string op) {
	return op + val1 + val2;
}

string infixToPrefix(vector<string> &str) {
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
					operands.push(evaluatePrefix(val1, val2, op));
				}
			}
			operators.push(word);
		} else if (word == ")") {
			while (operators.top() != "(") {
				string val2 = operands.top(); operands.pop();
				string val1 = operands.top(); operands.pop();
				string op = operators.top(); operators.pop();
				string ans = evaluatePrefix(val1, val2, op);
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
		operands.push(evaluatePrefix(val1, val2, op));
	}

	return operands.top();
}

int evaluateStringInt(int val1, int val2, string op) {
	if (op == "*")
		return val1 * val2;
	if (op == "/")
		return val1 / val2;
	if (op == "+")
		return val1 + val2;
	if (op == "-")
		return val1 - val2;
	return 0;
}

pair<int, string> Postfix_Evaluation_And_Conversions(vector<string> &str) {
	initialise();
	stack<string> operands;
	stack<string> operators;
	stack<int> result;
	for (auto word : str) {
		if (isOperator(word)) {
			string val2 = operands.top(); operands.pop();
			string val1 = operands.top(); operands.pop();
			string evaluateString = "(" + val1 + word + val2 + ")";
			operands.push(evaluateString);
			int rval2 = result.top(); result.pop();
			int rval1 = result.top(); result.pop();
			result.push(evaluateStringInt(rval1, rval2, word));
		} else {
			operands.push(word);
			result.push(stoi(word));
		}
	}

	return {result.top(), operands.top()};
}

pair<int, string> Prefix_Evaluation_And_Conversions(vector<string> &str) {
	initialise();
	stack<string> operands;
	stack<string> operators;
	stack<int> result;
	for (int i = str.size() - 1; i >= 0; i--) {
		string word = str[i];
		if (isOperator(word)) {
			string val1 = operands.top(); operands.pop();
			string val2 = operands.top(); operands.pop();
			string evaluateString = "(" + val1 + word + val2 + ")";
			operands.push(evaluateString);
			int rval1 = result.top(); result.pop();
			int rval2 = result.top(); result.pop();
			result.push(evaluateStringInt(rval1, rval2, word));
		} else {
			operands.push(word);
			result.push(stoi(word));
		}
	}

	return {result.top(), operands.top()};
}

int main()
{
	string input;
	cin >> input;
	vector<string> str;
	for (int i = 0; i < input.size(); i++) {
		string s;
		s += input[i];
		str.push_back(s);
	}
	pair<int, string> infixPair = Prefix_Evaluation_And_Conversions(str);
	string infixString = infixPair.second;
	vector<string> infixArray;
	for (int i = 0; i < infixString.size(); i++) {
		string s;
		s += infixString[i];
		infixArray.push_back(s);
	}
	cout << infixPair.first << endl;
	cout << infixString << endl;
	cout << infixToPostfix(infixArray);
}