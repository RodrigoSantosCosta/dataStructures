#include <iostream>
#include <string>
using namespace std;

class Node {
	public:
		// Fake "pointers" received from user input
		string cur;
		string prev;
		string next;

		// Actual pointers
		Node *_next;
		Node *_prev;
};

class List {
	public:
		Node *head;
		unsigned int total;

		// Constructor
		List() {
			total = 0;
		}

		// Funcionality
		void add(Node *n) {
			if (total) {
				// Add at end of List
				Node *m = head;
				for (; m->_next; m = m->_next);
				m->_next = n;
				n->_prev = m;
				++total;

			} else {
				// Add at beginning of List
				head = n;
				++total;
			}
		}

		Node *get(unsigned int pos) {
			if (pos > total) {
				return NULL;
			}

			Node *n = head;
			for (int i = 0; i < pos; ++i) {
				n = n->_next;
			}

			return n;
		}
};

int main() {
	// User input
	List l;
	uint64_t cur, prev, next, pos;
	string line;
	bool sane = 1;

	while (1) {
		getline(cin, line);
		if (line.empty())
			break;

		Node *n = new Node();

		pos = line.find(' ');
		n->cur = (line.substr(0, pos));
		line.erase(0, pos + 1);

		pos = line.find(' ');
		n->prev = (line.substr(0, pos));
		line.erase(0, pos + 1);

		pos = line.find(' ');
		n->next = (line.substr(0, pos));
		line.erase(0, pos + 1);

		l.add(n);
	}

	// Processing
	int aux = 0;
	Node *start = l.get(0);
	Node *end = l.get(1);

	string forwards, backwards;

	// Traverse forward
	forwards += start->cur;
	for (Node *n = start; n != end; ++aux) {
		// Find next in list
		for (int i = 0; i < l.total; ++i) {
			if (n->next == l.get(i)->cur) {
				// Move forward
				n = l.get(i);

				// Add to the traversed string
				forwards += l.get(i)->cur;
				break;
			}
		}
		
		if (aux > l.total) {
			// Couldn't reach the end
			sane = 0;
			break;
		}
	}

	// Traverse backwards
	aux = 0;
	backwards += end->cur;
	for (Node *n = end; n != start; ++aux) {
		// Find previous in list
		for (int i = 0; i < l.total; ++i) {
			if (n->prev == l.get(i)->cur) {
				// Move forward
				n = l.get(i);

				// Add to the traversed string
				backwards.insert(0, l.get(i)->cur);
				break;
			}
		}
		
		if (aux > l.total) {
			// Couldn't reach the beginning
			sane = 0;
			break;
		}
	}

	//cout << forwards << endl << backwards << endl;

	if (forwards == backwards && sane) {
		cout << "sana";
	} else {
		cout << "insana";
	}

	return 0;
}
