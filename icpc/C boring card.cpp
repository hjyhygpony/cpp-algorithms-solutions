#include <stdio.h>

int main() {
	int n = 0;
	int i, m, tr[n], p, q;
	int a = 1, b = 2, c = 3;
	scanf("%d", &n);
	int k = (n - 1), o = n;
	m = n - n % 3;
	for (i = 0; i <= m; i = i + 3) {
		int x = 0, y = 0, s = 0, t = 0, flag = 0;
		printf("? %d %d\n", a, b);
		//问第1位第2位
		scanf("%d %d", &x, &y);
		//识别前4个数的2个
		printf("? %d %d\n", b, c);
		//问第2位第3位
		scanf("%d %d", &s, &t);
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
			scanf("%d %d", &tr[i], &tr[i + 2]);
			if (tr[i + 1] == tr[i])
				tr[i + 1] = x;
		}
		a = a + 3;
		b = b + 3;
		c = c + 3;

	}
//	if (n % 3 == 2) {
//		printf("? 1 %d\n", k);
//		scanf("%d %d", &p, &q);
//		if (tr[0] == p) {
//			k = q;
//		} else {
//			k = p;
//		}
//		printf("? 1 %d\n", o);
//		scanf("%d %d", &p, &q);
//		if (tr[0] == p) {
//			o = q;
//		} else {
//			o = p;
//		}
//	}
//	if (n % 3 == 1) {
//		printf("? 1 %d", o);
//		scanf("%d %d", &p, &q);
//		if (tr[0] == p) {
//			o = q;
//		} else {
//			o = p;
//		}

	i = 0;
	printf("!");
	while (i <= m) {
		printf("%d", tr[i]);
		++i;
	}
//	if (n % 3 == 2) {
//		printf("%d %d", k, o);
//	}
//	if (n % 3 == 1) {
//		printf("%d", o);
//	}
	return 0;
}