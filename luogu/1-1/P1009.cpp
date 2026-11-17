#include <iostream>
#include <cstring>

struct Bigint {
	int len;
	int a[100];
	//记录位数，每个数位
	Bigint(int x = 0) {
		memset(a, 0, sizeof(a)); //初始化分配空间

		for (len = 1; x; len++) {
			a[len] = x % 10;
			x /= 10;
			len--;
		}//？？？
	}
	int &operator[](int i) {
		return a[i];//重载[]，使得可以直接用x[i]来表示x.a[i]
	}
	void flatten(int L) {
		len = L;
		for (int i = 0; i < len; i++) {
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}//进位展平
		while (!a[len]) {
			len--;
		}//删去多余长度
	}
	void print() {
		for (int i = std::max(1, len); i >= 1; i--) {
			printf("%d", a[i]);
		}
	}
};

Bigint operator+(Bigint a, Bigint b) {
	Bigint c;
	int len = std::max(a.len, b.len);
	for (int i = 1; i <= len; i++) {
		c[i] += a[i] + b[i];
	}
	c.flatten(len + 1);
	return c;
}//加法

Bigint operator*(Bigint a, int b) {
	Bigint c;
	int len = a.len;
	for (int i = 1; i <= len; i++) {
		c[i] = a[i] * b;
	}
	c.flatten(len + 11);
	return c;
}//？乘法

int main() {
	Bigint ans(0), fac(1);
	int m;
	std::cin >> m;
	for (int i = 1; i <= m; i++) {
		fac = fac * i;
		ans = ans + fac;
	}
	ans.print();
	return 0;
}