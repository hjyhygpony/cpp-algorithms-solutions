#include <iostream>
using namespace std;

int main() {
	string strA, strB;
	cin >> strA >> strB;
	int len = max(strA.length(), strB.length());

	int intA[10000], intB[10000], intC[10000];

	for (int i = strA.length() - 1, j = 1; i >= 0; i--, j++) {
		intA[j] = strA[i] - '0';
	}
	for (int i = strB.length() - 1, j = 1; i >= 0; i--, j++) {
		intB[j] = strB[i] - '0';
	}

	for (int i = 1; i <= len; i++) {
		intC[i] = intC[i] + intA[i] + intB[i];
		intC[i + 1] = intC[i] / 10;
		intC[i] = intC[i] % 10;
	}

	if (intC[len + 1]) {
		len++;
	}

	for (int i = len; i >= 1; i--) {
		cout << intC[i];
	}

	return 0;
}