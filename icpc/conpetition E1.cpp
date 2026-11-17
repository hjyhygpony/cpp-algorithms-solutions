#include <stdio.h>
#include <math.h>

int main() {
	int n, minj, minz, s, S, m, a = 0, d = 0;                      //m用来判断循环，a是w[]角标，d从0开始输出w[]角标

	scanf ("%d\n", &n);
	printf("6");
//	int j[n], z[n], w[100000000], t = 0, f = 0, zhen = 0, jia = 0;
//	for (f = 0; f <= n; f++) {                                     //识别真和假数组
//		scanf("%d", &j[f]);
//	}
//	for (t = 0; t <= n; t++) {
//		scanf("%d", &z[t]);
//	}
//
//	for (int c = 0; c <= n; c++) {                                //整体循环
//
//		for (f = 0; f < n; f++) {                                 ////通过循环找出真假数组最小值minj、minz,最小值的位数jia、zhen
//			minj = j[0];
//			if (minj > j[f + 1]) {
//				minj = j[f + 1];
//				++jia;
//			}
//		}
//		for (t = 0; t < n; t++) {
//			minz = z[0];
//			if (minz > z[t + 1]) {
//				minz = z[t + 1];
//				++zhen;
//			}
//		}
//		s = abs(jia - zhen);                                  //w[s]储存交换的数的位置
//		if (zhen > jia) {
//			for (m = 0; m < 2 * s; m + 2) {
//				j[jia - 1] = j[jia];                            //minj右边的数放在minj的位置上
//				j[jia] = minj;                                  //minj向右移一位
//				w[a] = jia;
//				w[a + 1] = jia + 1;
//				jia = jia + 1;
//				a = a + 2;
//			}
//		}
//		if (zhen == jia) {
//			for (m = 0; m < 2 * s; m + 2) {
//				jia = w[a];
//				jia = w[a + 1];
//				a = a + 2;
//			}
//		}
//		if (zhen < jia) {
//			for (m = 0; m < 2 * s; m + 2) {
//				j[jia - 1] = j[jia - 2];                       //minj左边的数放在minj的位置上
//				j[jia - 2] = minj;                             //minj向左移一位
//				w[a] = jia;
//				w[a + 1] = jia - 1;
//				jia = jia - 1;
//				a = a + 2;
//			}
//		}
//		S = S + s;
//		for (int b = (zhen - 1); b < (n - 1); b++) {	           	 //b用来判断循环
//			j[b - 1] = j[b];                                  //删除数组中已经到达指定位置的元素（z[]&j[]）
//			z[b - 1] = z[b];
//		}
//	}
//	printf("%d\n", S);
//	for (int c = 0; c <= S; c++) {
//		printf("%d %d", w[d], w[d + 1]);
//		d = d + 1;
//	}
	return 0;
}