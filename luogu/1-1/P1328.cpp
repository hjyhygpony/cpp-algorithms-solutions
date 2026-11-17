#include <iostream>
using namespace std;


int main() {

	int r[5][5] = {{0, 0, 1, 1, 0}, {1, 0, 0, 1, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 0, 1}, {1, 1, 0, 0, 0}};
	int n, na, nb;
	cin >> n >> na >> nb;
	int nA[n], nB[n];
	//输入出拳周期
	for (int i = 0; i < min(na, n); i++) {
		cin >> nA[i];
	}
	for (int i = 0; i < min(nb, n); i++) {
		cin >> nB[i];
	}
	//补充完整出拳周期
	for (int i = na ; i < n; i++) {
		nA[i] = nA[i % na];
	}
	for (int i = nb ; i < n; i++) {
		nB[i] = nB[i % nb];
	}
	//计分
	int sa = 0, sb = 0;
	for (int i = 0; i < n; i++) {
		sa += r[nA[i]][nB[i]];
		sb += r[nB[i]][nA[i]];
	}
	cout << sa << " " << sb;


	return 0;
}