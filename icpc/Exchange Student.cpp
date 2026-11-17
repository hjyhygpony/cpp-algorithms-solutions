#include <stdio.h>
#include <math.h>

int main() {
	int n;                                //m用来判断循环，a是w[]角标，d从0开始输出w[]角标

	scanf ("%d\n", &n);
	int j[n], z[n], w[n], c = 0, e = 0, t = 0, f = 0, zhen = 0, jia = 0, a = 0, d = 0, g = 0, b = 0, minj, minz, s, S,
	                      m = 0, h, i, k ;
	while (f < n) {
		scanf("%d", &j[f]);
		f = f + 1;
	}

	while (t < n) {
		scanf("%d", &z[t]);
		t = t + 1;
	}


	while (c < n) {                                    //整体循环
		jia = 0, zhen = 0;
		minj = j[0];
		for (f = 0; f < n; f++) {                      //通过循环找出真假数组最小值minj、minz,最小值的位数jia、zhen
			if (minj > j[f + 1]) {
				minj = j[f + 1];
				jia = jia + 1;
			}
		}
		minz = z[0];
		for (t = 0; t < n; t++) {
			if (minz > z[t + 1]) {
				minz = z[t + 1];
				zhen = zhen + 1;
			}
		}

		s = abs(jia - zhen);                           //计算每次交换次数

		if (zhen > jia) {
			m = 0;
			while (m < 2 * s) {
				j[jia - 1] = j[jia];                   //minj右边的数放在minj的位置上
				j[jia] = minj;                         //minj向右移一位
				w[a] = jia;
				w[a + 1] = jia + 1;
				jia = jia + 1;
				a = a + 2;
				m = m + 1;
			}
		}
		if (zhen < jia) {
			m = 0;
			while (m < 2 * s) {
				j[jia - 1] = j[jia - 2];              //minj左边的数放在minj的位置上
				j[jia - 2] = minj;                    //minj向左移一位
				w[a] = jia;
				w[a + 1] = jia - 1;
				jia = jia - 1;
				a = a + 2;
				m = m + 1;
			}
		}

		if (zhen != jia) {                            //删除数组中到达指定位置的元素（把其后每个元素向前覆盖一位）
			b = 0;
			h = n - jia;
			if (jia < n) {
				while (b < h) {
					j[jia - 1] = j[jia];
					jia = jia + 1;
					b = b + 1;
				}
			}
			b = 0;
			i = n - zhen;
			if (zhen < n) {
				while (b < i) {
					z[zhen - 1] = z[zhen];
					zhen = zhen + 1;
					b = b + 1;
				}
			}
		}
		S = S + s;                                   //计算总的交换次数
		c = c + 1;
	}
	printf("%d\n", S);
	fflush(stdout);

	while (e < S) {                                  //循环输出数组w[]
		printf("%d %d\n", w[d], w[d + 1]);
		fflush(stdout);
		d = d + 2;
		e = e + 1;
	}
	return 0;
}