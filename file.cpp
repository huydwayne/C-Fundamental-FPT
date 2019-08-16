#include <stdio.h>
#include <conio.h>

void writeFile(char fileName[]){
	int n;
	FILE * f = fopen(fileName,"wt"); //wt: write-able text
	printf("Enter data  :\n");
	scanf("%d", &n);
	while (n!=0){
		fprintf(f, "%5d", n);
		scanf("%d", &n);
	}
	fclose(f);
}
void readFile (char fileName[]){

	FILE * f = fopen(fileName, "rt");
	int i = 0, n = 0, s=0;
	int a[100];
	while (!feof(f)){
		fscanf(f,"%5d", &a[n++]);
	}
	fclose(f);
	printf("Du lieu doc tu tap tin: \n");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
		s+=a[i];
	}
	printf("\n Tong cac so la: %d",s);
}
main(){
	char fileName[] = "test.txt";
	writeFile(fileName);
	readFile(fileName);
}
