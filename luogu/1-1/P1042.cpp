#include <iostream>
#include <cmath>
using namespace std;


int main() {
	int w = 0, l = 0, i = 0;
	char a[62525];
	a[i] = getchar();
	while (a[i] != 'E') {
		i++;
		a[i] = getchar();
	}
	int n = i;
	for (i = 0; i <= n; i++) {
		if (a[i] == 'W') {
			w++;
		}
		if (a[i] == 'L') {
			l++;
		}
		if (w >= 11 || l >= 11) {
			if (fabs(w - l) >= 2 ) {
				printf("%d:%d\n", w, l);
				w = 0;
				l = 0;
			}
		}

	}
	printf("%d:%d\n", w, l);
	printf("\n");

	w = 0;
	l = 0;
	for (i = 0; i <= n; i++) {
		if (a[i] == 'W') {
			w++;
		}
		if (a[i] == 'L') {
			l++;
		}
		if (w >= 21 || l >= 21) {
			if (fabs(w - l) >= 2 ) {
				printf("%d:%d\n", w, l);
				w = 0;
				l = 0;
			}
		}

	}
	printf("%d:%d\n", w, l);

	return 0;
}