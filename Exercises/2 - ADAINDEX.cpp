#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;

class Node {
	public:
		string s;
		Node *next;
};

class List {
	public:
		Node *head;
		Node *tail;

		unsigned int total;

		// Constructor
		List() {
			total = 0;
		}

		// Add element at end of list
		void add(string s) {
			if (total) {
				Node *m = new Node();
				m->s = s;
				this->tail->next = m;
				this->tail = m;
				++total;
			} else {
				Node *m = new Node();
				m->s = s;
				this->head = m;
				this->tail = m;
				++total;
			}
		}
};

int main() {
	// User input
	int n, q, size, size2, result;
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
	Node *m;
	for (Node *n = queries.head; n; n = n->next) {
		result = 0;

		// Iterate through all words
		for (m = words.head; m; m = m->next) {
			isPrefix = 1;
			size = n->s.length();
			size2 = m->s.length();

			// Query is bigger than word itself,
			// can't possibly be a prefix
			if (size > size2)
				continue;

			// Check if query is a prefix of word
			// by iterating through the characters
			string::iterator ptr = n->s.begin();
			string::iterator ptr2 = m->s.begin();

			for (int i = 0; i < size; ++i) {
				if ((*ptr++) != (*ptr2++)) {
					isPrefix = 0;
					break;
				}
			}

			if (isPrefix) {
				++result;
			}
		}

		if (n != queries.head)
			output << '\n';

		output << result;
	}

	cout << output.str();

	return 0;
}