#include <stdio.h>

main(){
	int height;
	printf("Nhap do cao tam giac: ");
	scanf("%d", &height);
	int triangle = -1;
	int thutLe = height;
	
	printf("\n");
	for (int row = 1; row <= height ; row++ ){
		printf("\t");
//		
		for (int backspace = thutLe; backspace > 0; backspace--) {
			printf(" \b ");
		}
//		
		triangle+=2;
		for (int i = 1; i<=triangle; i++){
			printf("%d", 0);
		}
		printf("\n");
		thutLe--;
	}
//	printf ("%d", triangle);
}


	
