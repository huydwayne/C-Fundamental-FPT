#include <stdio.h>

double fibo ( int n) {
int t1=1, t2=1, f=1, i ;
for ( i= 3; i<=n; i++) {
f= t1 + t2;
t1= t2;
t2=f;
}
return f;
}

	int validDate ( int d, int m, int y) {
		int maxd = 31;
		/* basic checking */
		if ( d < 1 || d > 31 || m < 1 || m > 12) return 0;
		/* update maxd of a month */
		if ( m==4 || m==6 || m==9 || m==11) maxd=30;
		else if (m==2) {
		/* leap year? */
		if ( y%400==0 || ( y%4==0 && y%100!=0)) {
			maxd=29;
		}
		else maxd = 28;
		}
		return d<=maxd;
	}
	
main(){
	int choice = 0;
	do {
		printf("1- Fibonacci Sequence\n");
		printf("2- Check a date\n");
		printf("3- Quit\n");
		printf("Select an operation: ");
		scanf("%d", &choice);
		switch (choice) {
			int n;
			case 1:
			do {
				printf("Nhap n: ");
				scanf("%d", &n);
			} while (n < 1);
			printf("%0.0lf\n", fibo(n));
			break;
			
			case 2:
			int d, m, y;
			printf("Nhap d m y : ");
			scanf("%d %d %d", &d, &m , &y);
			if (validDate(d, m, y)) {
			printf("Valid date\n");
			} else {
			printf("Invalid date\n");
			}
			break;
		
		}
	}while (choice > 0 && choice < 3);
}
