#include <stdio.h>

int main() {
	struct AA {
		float x;
		float y;
	} s, *p = &s;
	scanf("%f%f", p->x, p->y);
	printf("%f%f", s.x, s.y);
	return 0;
}