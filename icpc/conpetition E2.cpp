#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
	int n, v, p, q, score = 0;
	int org[v], zheng[p], fu[q], fin[n];

	//扫描原数组
	scanf("%d", &n);
	for (v = 0; v < n; v++) {
		scanf("%d/n", &org[v]);
	}

	//总值不在范围内的error1

	//求和
	int sum = 0;
	for (v = 0; v < n; v++) {
		sum = sum + org[v];
	}

	//判断
	if (sum > 9999999 || sum < 0) {
		printf("error");
	}

	//给正数组赋值
	v = 0;
	p = 0;
	while (p <= n && org[v] > 0) {
		zheng[p] = org[v];
		p++;
		v++;
	}

	//给负数组赋值
	v = 0;
	q = 0;
	if (q < n && org[v] < 0) {
		fu[q] = org[v];
		q++;
		v++;
	}

	//正数组排序
	int len;
	int i;
	for (i = 0; i < len - 1; i++) {
		int end = i;  //前end位为有序部分
		int temp = zheng[i + 1]; //临时变量存放

		while (end >= 0) {
			if (zheng[end] > temp) { //将temp变量与前面一位元素比较
				zheng[end + 1] = zheng[end]; //将比temp变量大的元素向后移动一位
				end--;    //继续向前比较
			} else { //找到比temp变量小的元素
				break;
			}
		}

		zheng[end + 1] = temp; //将temp变量插入有序部分
	}
	//负数组排序
	void insertsort(int fu[], int len) {
		int j;
		for (j = 0; j < len - 1; j++) {
			int end = j;  //前end位为有序部分
			int temp = fu[j + 1]; //临时变量存放

			while (end >= 0) {
				if (fu[end] > temp) { //将temp变量与前面一位元素比较
					fu[end + 1] = fu[end]; //将比temp变量大的元素向后移动一位
					end--;    //继续向前比较
				} else { //找到比temp变量小的元素
					break;
				}
			}

			fu[end + 1] = temp; //将temp变量插入有序部分
		}
	}

	p = 0;
	q = 0;
	int jud;
	int front, behind;
	score = score + zheng[p]; //先把正数最大加上
	p++;
	if (p + q < n &&) {

		front = p + q;

		//正循环
		if (jud < 9999999) {
			score = score + zheng[p];
			jud = score + zheng[p + 1];
			p++;

		}

		//负循环
		jud = score + fu[q];
		if (jud > 0) {
			score = score + fu[q];
			jud = score + fu[q + 1];
			q++;

		}
		behind = p + q;
	}



	return 0;
}