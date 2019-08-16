#include <stdio.h>

main(){
	int sum = 0;
	int x;
	
	do {
		printf ("Nhap x: ");
		scanf ("%d", &x);
		if (x == 0 ) {
			printf("Ket thuc chuong trinh\n");
		}
		sum+=x;
	} while (x!=0);
	
	printf("Sum la: %d", sum);
}
