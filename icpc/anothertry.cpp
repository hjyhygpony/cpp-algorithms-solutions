#include <stdio.h>

int main() {
	int i, n, m, k, o, w;
	scanf("%d", &w);
	scanf("%d", &n);
//	n = 100000;

	m = n - n % 3;
	int tr[m];
	int a = 1, b = 2, c = 3;
	for (i = 0; i < m; i = i + 3) {
		int x = 0, y = 0, s = 0, t = 0;
		int flag = 0;
		printf("? %d %d\n", a, b);
		fflush(stdout);
		scanf("%d %d", &x, &y);
		//问第1位第2位
		printf("? %d %d\n", b, c);
		fflush(stdout);
		scanf("%d %d", &s, &t);
		//问第2位第3位
		if (x == s) {
			flag = flag + 1;
			tr[i + 1] = x;
			tr[i] = y;
			tr[i + 2] = t;
		}
		if (x == t) {
			flag = flag + 1;
			tr[i + 1] = x;
			tr[i] = y;
			tr[i + 2] = s;
		}
		if (y == s) {
			flag = flag + 1;
			tr[i + 1] = y;
			tr[i] = x;
			tr[i + 2] = t;
		}
		if (y == t) {
			flag = flag + 1;
			tr[i + 1] = y;
			tr[i] = x;
			tr[i + 2] = s;
		}
		if (flag == 2 && x != y && s != t) {
			printf("? %d %d\n", a, c);
			fflush(stdout);
			scanf("%d %d", &tr[i], &tr[i + 2]);
			if (tr[i + 1] == tr[i])
				tr[i + 1] = x;
		}
		a = a + 3;
		b = b + 3;
		c = c + 3;
	}
	int p, q;
	if (n % 3 == 2) {
		printf("? %d %d\n", 1, n - 1);
		fflush(stdout);
		scanf("%d %d", &p, &q);
		if (tr[0] == p) {
			k = q;
		} else {
			k = p;
		}
		printf("? %d %d\n", 1, n);
		fflush(stdout);
		scanf("%d %d", &p, &q);
		if (tr[0] == p) {
			o = q;
		} else {
			o = p;
		}
	}
	if (n % 3 == 1) {
		printf("? %d %d\n", 1, n);
		fflush(stdout);
		scanf("%d %d", &p, &q);
		if (tr[0] == p) {
			o = q;
		} else {
			o = p;
		}
	}
	i = 0;
	printf("!");
	while (i < m) {
		printf("%2d", tr[i]);
		fflush(stdout);
		i++;
	}
	if (n % 3 == 1) {
		printf("%2d", o);
		fflush(stdout);
	}
	if (n % 3 == 2) {
		printf("%2d %d", k, o);
		fflush(stdout);
	}

	return 0;
}