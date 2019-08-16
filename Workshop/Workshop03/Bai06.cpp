#include <stdio.h>


int isFibonacci (int n)
{ int t1=1, t2=1, f=1;
if (n==1) return 1; /* n belongs to the Fibonacci sequence*/
while (f < n) /* Find out the Fibo number f to n */
{ f= t1 + t2;
t1=t2;
t2=f;
}
return n==f;
}

int main(){
	int n;
	do {
		printf("Nhap n: ");
		scanf("%d", &n);
	} while (n < 1);
	
	if (isFibonacci(n) == 1 ) {
		printf("it is a Fibonacci element");
	} else printf("it is not a Fibonacci element");
}
