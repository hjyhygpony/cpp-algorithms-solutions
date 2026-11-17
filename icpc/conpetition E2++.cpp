#include <stdio.h>

int main() {
	int n = 0, v = 0, p = 0, q = 0, recordp = 0, recordq = 0, score = 0;
	int org[v], zheng[p], fu[q];
	//扫描原数组
	scanf("%d ", &n);
	for (v = 0; v < n; v++) {
		scanf("%d/n", &org[v]);
	}

	//总值不在范围内的error1

	//求和
//	int sum = 0;
//	for (v = 0; v < n; v++) {
//		sum = sum + org[v];
//	}
//
//	//判断
//	if (sum > 9999999 || sum < 0) {
//		printf("error");
//	} else {



	//给正数组赋值
	v = 0;
	p = 0;
	q = 0;

	for (int v = 0; v < n; v++) {

		int temp = org[v];

		printf("\n *** org %d is: %d ***", v, temp);

		if (temp >= 0) {
			zheng[p] = temp;
			printf("give the zheng value :%2d p:%d", zheng[p], p);
			p++;
			continue;



		}
	}

	for (int v = 0; v < n; v++) {

		int temp = org[v];

		printf("\n *** sec org %d is: %d ***", v, temp);

		if (temp < 0) {

			fu[q] = temp;

			printf("give the fu value :%2d q:%d", fu[q], q);
			q++;
			continue;

		}


	}





	recordp = p;

	recordq = q;

	printf("\n recordp,  value :%d recordq value:%d \n", recordp, recordq);


	for (int i = 0; i < recordq; i++) {
		printf("\n -TEST first %2d\n", fu[i]);
	}


	//正数组排序
	int i, j, temp1;
	for (int i = 0; i < recordp - 1 ; i++) {
		//printf("zhengshu array zheng[]%d :%d", i, zheng[i]);
		for (j = 0; j < recordp - i - 1 ; j++) {
			if (zheng[j] > zheng[j + 1]) {
				temp1 = zheng[j];
				zheng[j] = zheng[j + 1];
				zheng[j + 1] = temp1;
			}
		}
	}
	for (int i = 0; i < recordp; i++) {
		printf("+TEST:%2d\n", zheng[i]);
	}


	for (i = 0; i < recordq; i++) {
		printf("\n -TEST before %2d\n", fu[i]);
	}

	//负数组排序
	int s, t, temp2;
	for (s = 0; s < recordq - 1; s++) {
		for (t = 0; t < recordq - s - 1 ; t++) {
			if (fu[t] < fu[t + 1]) {
				temp2 = fu[t];
				fu[t] = fu[t + 1];
				fu[t + 1] = temp2;


			}
		}
	}
	for (i = 0; i < recordq; i++) {
		printf("-TEST%2d\n", fu[i]);
	}





//		p = 0;
//		q = 0;
//		int jud;
//		int front, behind;
//		score = score + zheng[0]; //先把正数最大加上
//		jud = score + zheng[1];//!!!!万一没
//		printf("%d\n", zheng[p]);
//		p++;
//		do {
//
//			front = p + q;
//
//			//正循环
//			while (jud < 9999999 && p + 1 <= recordp) {
//				score = score + zheng[p];
//				jud = score + zheng[p + 1];
//				printf("%d\n", zheng[p]);
//				p++;
//
//
//
//
//			}
//
//			//负循环
//			jud = score + fu[q];
//			while (jud > 0 && q + 1 <= recordq) {
//				score = score + fu[q];
//				jud = score + fu[q + 1];
//				q++;
//				printf("%d\n", fu[q]);
//
//			}
//			behind = p + q;
//		} while (p + q < n    && front != behind);



	return 0;
}