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

class RadixNode {
	public:
		RadixNode *child[26];
		RadixNode *parent;
		unsigned int number;
};

class RadixTree {
	public:
		RadixNode *head;

		RadixTree() {
			head = new RadixNode();
		}

		void add(string s) {
			string::iterator i = s.begin();
			string::iterator end = s.end();

			RadixNode *n = head;

			for (; i != end; ++i) {
				// For each character
				int id = ( (int)(*i) ) - (97);

				if ( n->child[id] != NULL) {
					// RadixNode already exists
					// for this character
					n = n->child[id];
					n->number++;

				} else {
					// Instantiate new RadixNode
					// for this character
					RadixNode *m = new RadixNode();
					n->child[id] = m;
					m->parent = n;
					n = m;
					n->number++;
				}
			}
		}
};

int main() {
	// User input
	int n, q;
	int result = 0;
	scanf("%d %d ", &n, &q);

	RadixTree words;
	List queries;

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

	// For each query
	for (Node *n = queries.head; n; n = n->next) {
		string::iterator ptr = n->s.begin();
		string::iterator ptrEnd = n->s.end();
		RadixNode *rn = words.head;
		bool couldntFind = 0;

		// For each character
		for (; ptr != ptrEnd; ++ptr) {
			int id = ( (int)(*ptr) ) - (97);

			if (rn->child[id]) {
				// Travel down the tree
				rn = rn->child[id];
			} else {
				// Couldn't find next letter
				couldntFind = 1;
				break;
			}
		}

		if (couldntFind) {
			if (n != queries.head)
				output << '\n';

			output << 0;
			continue;
		}

		// Now we're at the point in the tree
		// where anything below us has the prefix
		// we want, and we already counted how many
		// times we've been here while adding the
		// strings, so all we need to do is:
		result = rn->number;

		// Add result to output
		if (n != queries.head)
			output << '\n';

		output << result;
	}

	cout << output.str();
	return 0;
}