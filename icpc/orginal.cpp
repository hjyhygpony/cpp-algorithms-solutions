#include <stdio.h>

int main() {
	int i, n;
	scanf("%d", &n);
	int tr[n];
	int a = 1, b = 2, c = 3;
	for (i = 1; i <= n; i = i + 3) {
		int x = 0, y = 0, s = 0, t = 0;
		int flag = 0;
		printf("'?' %d %d\n", a, b);
		//问第1位第2位
		scanf("%d %d", &x, &y);
		//识别前4个数的2个
		printf("'?'' %d %d\n", b, c);
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
			printf("'?' %d %d", a, c);
			scanf("%d %d", &tr[i], &tr[i + 2]);
			if (tr[i + 1] == tr[i])
				tr[i + 1] = x;
		}
		a = a + 3;
		b = b + 3;
		c = c + 3;
	}
	i = 1;
	while (i <= n) {
		printf("%d", tr[i]);
		i++;
	}
	return 0;
}