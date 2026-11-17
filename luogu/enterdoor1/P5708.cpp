#include <stdio.h>
#include <math.h>

int main() {
	double a, b, c, p = 0, s = 0;
	scanf("%lf %lf %lf", &a, &b, &c);
	p = (a + b + c) / 2.0;
	s = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("%.1lf", s);
	return 0;
}