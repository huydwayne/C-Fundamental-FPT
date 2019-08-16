#include <stdio.h>
#include <math.h>

int prime( int n ) {
	
int m = sqrt(n); /* m: square root of n */
int i; /* variable having value from 2 to m */

for ( i=2; i <= m; i++) {
	if (n%i==0) return 0 ; 
} 
return 1; /* n is a prime */
}

main(){
	int n;
	do {
printf("Nhap n: ");
scanf("%d", &n);
}

while ( n < 2);

	for (int i=2; i<=n; i++ ) {
	
	if (prime(i) == 1 ) {
	printf("%d ", i);
	}	

	}
}

