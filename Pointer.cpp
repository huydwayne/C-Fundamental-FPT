#include <stdio.h>

int swap ( int *pA, int *pB){
	int temp;
	temp = *pA;
	*pA = *pB;
	*pB = temp;
}

main() {
	int x = 10;
	int y = 5;
	
	printf("address x = %u, x = %d\n", &x, x);
	printf("address y = %u, y = %d\n", &y, y);
	swap(&x , &y);
	printf("%d %d\n", x, y);
	int *p;
	printf("address p = %u, p = %d\n", &p, p);
	
	p = &x;
	printf("address p = %u, value: p = %d, *p = %d\n", &p, p, *p);
	*p = 100;
	printf("x = %d", x);
}
