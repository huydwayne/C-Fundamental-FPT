#include <stdio.h>

double makeDouble(int ipart, int fraction){ 
	double d_f= fraction;
	while (d_f >= 1) {
	d_f = d_f/10;
	}
	
	if (ipart < 0 ){
		return ipart - d_f;
	};
	
	return ipart + d_f ; 
}	

main(){
	int ipart, fraction;
	double value;
	printf("nhap vao ipart: ");
	scanf ("%d", &ipart);
	do {
		printf("nhap vao fraction: ");
		scanf("%d", &fraction);
	} while (fraction < 0);
	value = makeDouble(ipart, fraction);
	printf("%lf", value);
}

