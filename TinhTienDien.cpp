#include <stdio.h>


// Char: 1 byte
/* Integer:
 - DOS: 16bit = 2 byte
 - Window: 32bit = 4byte*/
 // Float: 4 byte
 //Double: 8 byte
  // Sign là dau' : 0 la positive, 1 la negative
  // &: dùng de~ lay dia chi

int main(){
	
	int const PRICE_1 = 950;
	int const PRICE_2 = 1250;
	int const PRICE_3 = 1350;
	int const PRICE_4 = 1550;
	
	int amountConsumption;
	int bill = 0;
	
	printf("Hay nhap vao so kwh tieu thu: ");
	scanf("%d", &amountConsumption);
//	printf("%d", amountConsumption);
	
	if ( amountConsumption <= 100 ) 
		{
			bill = amountConsumption*PRICE_1;
		} 
		
		else if ( amountConsumption <=150 ) 
			{
				bill = 100*PRICE_1 + (amountConsumption - 100)*PRICE_2;
			}
			
			else if ( amountConsumption <= 200) 
				{
					bill = 100*PRICE_1 + 50*PRICE_2 + (amountConsumption - 150)*PRICE_3;
				}
				
				else if (amountConsumption > 200) 
					{
						bill = 100*PRICE_1 + 50*PRICE_2 + 50*PRICE_3 + (amountConsumption - 200)*PRICE_4;
					}
			
		
	printf(" So tien ban phai tra la: %d ",bill);
	return 0;
}	

//Khong can return 0
/*main(){
	
}*/
