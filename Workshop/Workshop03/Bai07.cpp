#include <stdio.h>

int sumDigits (int n)
{ int sum=0; /* initialize sum of digits */
do
{ int remainder = n%10 ; /* Get a digit at unit position */
n = n/10;
sum += remainder;
}
while (n > 0);
return sum;
}

main(){
	int S;
	int n;
	do {
		printf("Nhap number: ");
		scanf("%d", &n);
		if (n >= 0) {
			S = sumDigits(n);
			printf("%d\n", S);
		}
	} while (n>=0);
}
