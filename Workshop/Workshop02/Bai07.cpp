#include <stdio.h>

main() {
	char c1, c2;
	int d;
	
	printf("Nhap char 1 va char 2: ");
	scanf ("%c %c", &c1, &c2);
	
	if (c1 > c2){
		char temp = c1;
		c1 = c2;
		c2 = temp;
	}
	
	printf("d: %d\n", d = c2 - c1);
	for (char i = c1; i <= c2; i++) {
		printf("%c: %d, %o, %X\n", i, i, i, i);
	}
}
