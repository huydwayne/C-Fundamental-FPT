#include <stdio.h>
#include <conio.h>

void xuatThang(){
	int n;
	printf("Nhap vao so n: ");
	scanf("%d", &n);
	printf("Thang la: ");
	switch(n) {
		case 1: 
		printf("January");
		break;
		
		case 2: 
		printf("February");
		break;
		
		case 3: 
		printf("March");
		break;
		
		case 4: 
		printf("April");
		break;
		
		case 5: 
		printf("May");
		break;
		
		case 6: 
		printf("June");
		break;
		
		case 7: 
		printf("July");
		break;
		
		case 8: 
		printf("August");
		break;
		
		case 9: 
		printf("September");
		break;
		
		case 10: 
		printf("October");
		break;
		
		case 11: 
		printf("November");
		break;
		
		case 12:
		printf("December");
		break;
	}
	
}

void demSoLe(){
	int x, y;
	int countSole = 0;
	do {
		printf("Nhap diem bat dau ( x ): ");
		scanf("%d", &x);
		printf("Nhap diem ket thuc ( y ): ");
		scanf("%d", &y);
	}
	while ( x > y);
		
	for (int i = x; i <= y; i++){
		if (i%2 == 1) countSole++;
	}
	printf("So luong cac so le la: %d", countSole);
}

void tinhXsochan(){
	int n, x;
	int count = 0;
	int sum = 0;
	do {
		printf("Nhap n (n >= 10): ");
		scanf("%d", &n);
		printf("Nhap x ( x > 0 ): ");
		scanf("%d", &x);
		printf("\n");
	} while ( n < 10 || x < 0 );
	
	for (int i = 1; i <= n; i++) {
		if ( i%2 == 0 ){
			sum += i;
			count++;
		}
		
		if (count == x) {
			i = n+1;
		}
	}
	
	printf("Tong so luong %d so chan tu 1 den %d la: %d", x, n, sum);
}


main(){
	int menuChoice=0;
	do {
		printf("\n1. Tinh x so chan \n");
		printf("2. Dem so le \n");
		printf("3. Xuat thang \n");
		printf("0. Thoat \n");
		printf("Nhap vao chuc nang ban muon su dung: ");
		scanf("%d", &menuChoice);
		switch (menuChoice) {
			case 1: 
			tinhXsochan();
			break;
			
			case 2:
			demSoLe();
			break;
			
			case 3:
			xuatThang();
			break;
			
			case 0:
			break;
		}
		getch();
	} while (menuChoice != 0 );
	
	printf("\nchuong trinh ket thuc!!!");

}


