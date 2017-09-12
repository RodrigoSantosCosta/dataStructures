#include <iostream>
using namespace std;

int main() {
	// User input
	int n, m;
	cin >> n;

	int s[n];
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	cin >> m;

	int q[m];
	for (int i = 0; i < m; ++i) {
		cin >> q[i];
	}

	// Resulting array
	int r[100];
	int r_total = 0;

	// Print out all in s that does not belong
	// to q, in ascending order
	bool found;
	for (int i = 0; i < n; ++i) {
		found = 0;

		// Note: Binary search would be
		// much faster for larger arrays.
		for (int j = 0; j < m; ++j) {
			if (s[i] == q[j]) {
				found = 1;
				break;
			}
		}

		if (!found) {
			r[r_total++] = s[i];
		}
	}

	for (int i = 0; i < r_total; ++i) {
		if (i) {
			cout << " ";
		}

		cout << r[i];
	}

	return 0;
}
