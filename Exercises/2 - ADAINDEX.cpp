#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;

class Node {
	public:
		// Content
		string s;

		// Pointers
		Node *_next;
};

class List {
	public:
		Node *head;
		unsigned int total;

		// Constructor
		List() {
			total = 0;
		}

		void add(string s) {
			if (total) {
				Node *n = this->head;
				for (; n->_next; n = n->_next);

				Node *m = new Node();
				m->s = s;

				n->_next = m;
				++total;
			} else {
				Node *m = new Node();
				m->s = s;
				this->head = m;
				++total;
			}
		}
};

int main() {
	// User input
	int n, q, tmp, result;
	bool isPrefix;
	scanf("%d %d ", &n, &q);

	List words, queries;
	string input;
	stringstream output;

	for (int i = 0; i < n; ++i) {
		cin >> input;
		words.add(input);
	}

	for (int i = 0; i < q; ++i) {
		cin >> input;
		queries.add(input);
	}

	// Iterate through each query
	for (Node *n = queries.head; n; n = n->_next) {
		result = 0;

		// Iterate through all words
		for (Node *m = words.head; m; m = m->_next) {
			isPrefix = 1;
			tmp = n->s.length();

			// Query is bigger than word itself,
			// can't possibly be a prefix
			if (tmp > m->s.length())
				continue;

			// Check if query is a prefix of word
			auto ptr = n->s.begin();
			auto ptr2 = begin(m->s);
			for (int i = 0; i < tmp; ++i) {
				if (ptr++ != ptr2++)
					isPrefix = 0;
					break;
			}

			if (isPrefix)
				++result;

			/*if (m->s.substr(0, tmp) == n->s)
				++result;*/
		}

		if (n != queries.head)
			output << '\n';

		output << result;
	}

	cout << output.str();

	return 0;
}