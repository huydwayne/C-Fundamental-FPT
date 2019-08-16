#include <stdio.h>

int getRelPos ( double x, double y, double r) {
double d2=x*x + y*y; /* d 2 = x 2 + y 2 */
double r2= r*r; /* r 2 */
if (d2 < r2) return 1 ; /* d 2 &lt;r 2 ?the point is in the circle */
else if (d2==r2) return 0 ; /* d 2 =r 2 ?the point is on the circle */
return -1 ; /* d 2 &gt; r 2 ?the point is out of the circle */
}

main(){
	double x, y, r;
	int result;
	printf("Nhap x va y: ");
	scanf("%lf %lf", &x, &y);
	
	do{
		printf("Nhap r: ");
		scanf("%lf", &r);
	} while (r < 0);
	
	result = getRelPos(x,y,r);
	if (result == 1) {
		printf("The point is in the circle");
	}
	else if (result==0) {
		printf("The point is on the circle");
	}
	else printf("The point is out of the circle") ;
}


