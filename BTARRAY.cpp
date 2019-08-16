#include <stdio.h>
int n = 0;

nhapMang(int array[]){
	for (int i = 0; i < n; i++ ){
		printf("Nhap gia tri thu %d: ",i+1);
		scanf("%d", &array[i]);
	}
}

xuatMang(int array[]){
	printf("\n");
	for (int i = 0; i < n; i++ ){
		printf("Gia tri thu %d - vi tri trong mang %d la: %d\n", i+1, i, array[i]);
	}
}

tinhTong(int array[]){
	int sum = 0;
	for (int i = 0; i < n; i+=2) {
		sum+=array[i];
	}
	printf("\nTong cac vi tri chan la: %d", sum);
}

demTanXuat(int array[], int x) {
	int count = 0;
	for (int i = 0; i < n; i++){
		if (array[i] == x) {
			count++;
		}
	}
	printf("Gia tri %d xuat hien: %d lan", x, count);
}

sapXep ( int array[]) {
	for (int i = 0; i < n; i+=2){
		if ( array[i] < array[i+2] && ( i + 2 )< n){
			int temp = array[i];
			array[i] = array[i+2];
			array[i+2] = temp;
			i = -2;
		}
	}
	for (int i = 1; i < n; i+=2){
		if ( array[i] > array[i+2] && ( i + 2 )< n){
			int temp = array[i];
			array[i] = array[i+2];
			array[i+2] = temp;
			i = -1;
		}
	}
	xuatMang(array);
}

main(){
	printf("Nhap so luong phan tu trong mang: ");
	scanf("%d", &n);
	int array[n];
	
	nhapMang(array);
	xuatMang(array);
	tinhTong(array);

	int x = -1;
	printf("\nNhap gia tri ban muon dem tan xuat: ");
	scanf("%d", &x);
	demTanXuat(array, x);
	
	sapXep(array);

	
}
