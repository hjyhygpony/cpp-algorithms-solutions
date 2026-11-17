#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int a[n + 1][n + 1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = (i - 1) * n + j;
			//cout << "a" << i << j << "=" << a[i][j] << endl;
		}
	}

	int x, y, r;
	int z = 10;
	int temp = 0;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> r >> z;
		for (int j = 2 * r + 1; j > 0; j--) {
			if (z == 0) {
				//À≥ ±’Î
			} else if (z == 0) {
				//ƒÊ ±’Î

			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}




	return 0;
}