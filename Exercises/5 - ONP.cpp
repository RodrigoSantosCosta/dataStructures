#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	// User input
	int t;
	cin >> t;
	string expression[t];
	string result[t];

	for (int i = 0; i < t; ++i) {
		cin >> expression[i];
	}

	// For each expression
	for (int i = 0; i < t; ++i) {
		stack<char> s;

		// For each character
		for (string::iterator it = expression[i].begin(); it != expression[i].end(); ++it) {
			// Implementation of the shunting-yard algorithm
			if (*it == '^' || *it == '(') {
				s.push(*it);
			} else
			if (*it == '*' || *it == '/') {
				if (s.top() != '^')
					s.push(*it);
			} else
			if (*it == '+' || *it == '-') {
				if (s.top() != '^' && s.top() != '*' && s.top() != '/')
					s.push(*it);
			} else
			if (*it == ')') {
				// Pop out stack until opening parenthesis
				while (s.top() != '(') {
					result[i] += s.top();
					s.pop();
				}

				s.pop();
			} else {
				// Operand
				result[i] += *it;
			}
		}
		
		// End of input. Dump the stack into the result
		while (!s.empty()) {
			result[i] += s.top();
			//result[i].push_back(s.pop());
			s.pop();
		}
	}

	// Print out the new expressions
	for (int i = 0; i < t; ++i) {
		cout << result[i];

		if (i != t-1) {
			cout << endl;
		}
	}

	return 0;
}
