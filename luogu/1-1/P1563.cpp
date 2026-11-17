#include <iostream>
using namespace std;

struct node {
	int head;
	string name;
} a[10005];

int main() {
	int n, m;
	int j = 0;
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> a[i].head >> a[i].name;
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		int atemp = a[j].head;
		int jud = x + atemp;
		if (jud % 2 == 0) {
			j = (j + n - y) % n;
		} else {
			j = (j + y) % n;
		}

	}
	cout << a[j].name;
	return 0;
}
