#include <stdio.h>

double factorial ( int n) {
	double p = 1;
	int i;
	for (i=2; i <= n; i++) p *= i;
	return p;
}

main(){
	int n;
	do {
		printf("Nhap n: ");
		scanf("%d", &n);
	} while (n < 0);
	
	printf("%0.0lf", factorial(n));
}

