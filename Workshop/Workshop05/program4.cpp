#include <stdio.h>
#include <math.h>
//----------------------
//phuong trinh bac 2
void quadratic(double a, double b,double c)
{	double delta,x1,x2;
	delta = (b*b) - 4*(a*c);
	if (delta<0)
		printf("phuong trinh vo nghiem\n");
		else if (delta =0){
		x1=-b/ (2*a);
		printf("x1=x2=%.0lf\n",x1);
		}
	else if (delta > 0){
		x1 = (-b+sqrt(delta))/(2*a);
		x2 = (-b-sqrt(delta))/(2*a);
		printf("x1 = %.2lf\n x2 = %.2lf",x1,x2);
}
}
//-------------------------------
//validations
double validations(double deposit,double r,double n)
{
	double P = deposit*pow((1+r),n);
	return P;
}
main()
{
	int choice;
	do{
		printf("1- Quadratic equation \n");
		printf("2- Bank deposit problem \n");
		printf("3- Quit \n");
		scanf("%d",&choice);
	switch (choice){
		case 1:
			double a,b,c;
			printf("Nhap a b c :");
			scanf("%lf %lf %lf",&a,&b,&c);
			quadratic(a,b,c);
			break;
		case 2:
			double deposit,r,n;
			do{
			printf("Nhap tien gui :");
			scanf("%lf",&deposit);
			printf("\nNhap lai moi nam : ");
			scanf("%lf",&r);
			printf("\nNhap so nam gui : ");
			scanf("%lf",&n);
		}while (deposit<0 || r>1 || r<0||n<0);
			printf("%.2lf\n",validations(deposit,r,n));
			break;
		case 3 :
			return 0;
		}
		}while (choice > 0 && choice <4);
}
