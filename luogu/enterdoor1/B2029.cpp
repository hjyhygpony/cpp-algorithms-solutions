#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
	double h, r, number;
	cin >> h >> r;
	number = 20000 / (3.14 * r * r * h);
	cout << ceil(number) << endl;
	return 0;
}