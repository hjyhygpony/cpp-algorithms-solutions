#include <iostream>
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	int a[n + 1] = {0};

	int temp;

	for (int i = 0; i < m; i++) {
		cin >> temp;
		a[temp]++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < a[i]; j++) {
			cout << i << " ";
		}
	}

	return 0;
}