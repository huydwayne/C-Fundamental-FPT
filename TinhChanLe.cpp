#include <stdio.h>
#include <stdlib.h>

main(){
	int n;
	int sum = 0;
	printf("Nhap so n: ");
	scanf("%d", &n);
	while (n < 10 ) {
		printf("Nhap lai so n: ");
		scanf("%d", &n);
	}
	for (int i = 2; i<=n; i++) {
		if (i%2 == 0) {
//			printf("%d", i);
			sum+=i;
		}
	}
	printf("Tong cac so chan la: %d", sum);
	
}
