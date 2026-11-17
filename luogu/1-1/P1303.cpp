#include <iostream>
using namespace std;

int main() {
	string strA, strB;
	cin >> strA >> strB;
	int alen = strA.length(), blen = strB.length();


	int intA[100000], intB[100000], intC[100000];

	for (int i = alen - 1, j = 1; i >= 0; i--, j++) {
		intA[j] = strA[i] - '0';
	}
	for (int i = blen - 1, j = 1; i >= 0; i--, j++) {
		intB[j] = strB[i] - '0';
	}

	for (int i = 1; i <= alen; i++) {
		for (int j = 1; j <= blen; j++) {
			intC[i + j - 1] += intA[i] * intB[j];
		}
	}

	int len = alen + blen;

	for (int i = 1; i <= len; i++) {
		intC[i + 1] += intC[i] / 10;
		intC[i] %= 10;
	}


	while (!intC[len]) {
		len--;
	}

	for (int i = max(1, len); i >= 1; i--) {
		cout << intC[i];
	}

	return 0;
}