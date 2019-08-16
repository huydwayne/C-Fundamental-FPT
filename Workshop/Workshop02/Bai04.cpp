#include <stdio.h>

main(){
	int x, y;
		
	do{
		printf ("Nhap x và y: ");
		scanf ("%d %d", &x, &y);
		int temp = x;
		x = y;
		y = temp;
		printf ("x = %d ; y = %d\n", x, y);
	
	} while (x!=0 && y!= 0);
}
