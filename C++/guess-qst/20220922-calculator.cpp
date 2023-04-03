#include <iostream>
#include <fstream>
#include <cmath>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
stack<double> num;
stack<char> ops;
unordered_map<char, int> pr = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
void codes() {
	ifstream ifs(__FILE__);
	cout << ifs.rdbuf();
	ifs.close();
}
void eval() {
	auto y = num.top(); num.pop();
	auto x = num.top(); num.pop();
	auto op = ops.top(); ops.pop();
	double ans;
	if (op == '+') ans = x + y;
	else if (op == '-') ans = x - y;
	else if (op == '*') ans = x * y;
	else ans = x / y;
	num.push(ans);
}
double solve(string &str) {
	for (int i = 0; i < str.size(); i ++) {
		auto op = str[i];
		if (isdigit(op)) {
			int j = i, pit = 0;
			double tmp = 0;
			while (j < str.size() && (isdigit(str[j]) || str[j] == '.')) {
				if (str[j] == '.') {pit = 1; j ++; continue;}
				if (!pit) tmp = tmp * 10 + str[j ++] - '0';
				else tmp += (str[j ++] - '0') / pow(10, pit ++);
			}
			i = j - 1;
			num.push(tmp);
		} else if (op == '(') ops.push(op);
		else if (op == ')') {
			while (ops.top() != '(') eval();
			ops.pop();
		} else {
			while (ops.size() && ops.top() != '(' && pr[ops.top()] >= pr[op]) eval();
			ops.push(op);
		}
	}
	while (ops.size()) eval();
	return num.top();
}
int main() {
	string str;
	cin >> str;
	cout << solve(str) << endl;
	cout << endl << "codes:" << endl; codes();
	return 0;
}
