#include <iostream>
using namespace std;


int main() {
	char a[102][102];
	int result[102][102] = {0};
	int s, t;
	char c;
	scanf("%d %d", &s, &t);
//	getchar();

	//要不然用cin，要不然用getchar把回车消除掉！！！！
	//输入矩阵
	for (int i = 1; i <= s; i++) {
		for (int j = 1; j <= t; j++) {
			cin >> a[i][j];
//			scanf("%c", &a[i][j]);
		}
//		getchar();
	}


	//炸弹加数
	for (int i = 1; i <= s; i++) {
		for (int j = 1; j <= t; j++) {
			if (a[i][j] == '*') {
				result[i - 1][j - 1]++;
				result[i - 1][j]++;
				result[i - 1][j + 1]++;
				result[i][j - 1]++;
				result[i][j + 1]++;
				result[i + 1][j - 1]++;
				result[i + 1][j]++;
				result[i + 1][j + 1]++;
			}
		}
	}

	//输出结果
	for (int i = 1; i <= s; i++) {
		for (int j = 1; j <= t; j++) {
			if (a[i][j] != '*') {
				printf("%d", result[i][j]);
			} else {
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}