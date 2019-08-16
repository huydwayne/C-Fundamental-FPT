#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char drinkName[MAX][50];
char make[MAX][50];
int volume[MAX];
int price[MAX];
int duraton[MAX];

void printMenu(){
    printf("1. Add new\n");
    printf("2. Find drink by make\n");
    printf("3. Find drink by volume\n");
    printf("4. Print sorted list\n");
    printf("5. Quit\n");
    printf("Input number: ");
}

int getChoice(int min, int max){
    int num;
    do {
        scanf("%d", &num);
    } while (num < min && num > max);
    return num;
}
//---------------------------------------------//

void addDrink(int index){
	fflush(stdin);
	printf("Input drink name: ");
	scanf("%[^\n]", drinkName[index]);
	fflush(stdin);
	printf("Input make: ");
	scanf("%[^\n]", make[index]);
	fflush(stdin);
	printf("Input volume: ");
	scanf("%d", &volume[index]);
	fflush(stdin);
	printf("Input price: ");
	scanf("%d", &price[index]);
	fflush(stdin);
	printf("Input duration: ");
	scanf("%d", &duraton[index]);
}

void printDrinkList(int index){
	printf("\n\n	DRINK LIST\n");
	for (int i = 0; i <= index; i++){
		printf("%d.\n", i + 1);
		printf("  Name:\t\t%s\n", drinkName[i]);
		printf("  Make:\t\t%s\n", make[i]);
		printf("  Volume:\t%d\n", volume[i]);
		printf("  Price:\t%d\n", price[i]);
		printf("  Duration:\t%d\n\n", duraton[i]);
	}
}


int searchMake(char code[], int currentIndex){
	for (int i = 0; i <= currentIndex; i++){
		if (strcmp(code, make[i]) == 0){
			return i;
		}
	}
	return -1;
}
int* searchMakeBySomeWord(char* keyword, int currentIndex){
	int *indexOfResult = (int *) malloc(50 * sizeof(int));
	int count = 0;
	int checker;
	char *compare = NULL; 
	
	for (int i = 0; i <= currentIndex; i++){
		compare = strstr(make[i], keyword);
		if (strstr(make[i], keyword) != NULL) {
			indexOfResult[count++] = i;
		}
	}
	indexOfResult[count] = -1;
	return indexOfResult;
}

void swapString(char str1[], char str2[]){
	char temp[50];
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
}

void swapNumber(int *num1, int *num2){
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void printDrinkByVolume(int volumeMin, int volumeMax, int currentIndex){
	for (int i = 0; i <= currentIndex; i++){
		if (volume[i] >= volumeMin && volume[i] <= volumeMax){
			printf("%d.\n", i + 1);
			printf("  Name:\t\t%s\n", drinkName[i]);
			printf("  Make:\t\t%s\n", make[i]);
			printf("  Volume:\t%d\n", volume[i]);
			printf("  Price:\t%d\n", price[i]);
			printf("  Duration:\t%d\n\n", duraton[i]);
		}
	}	
}
void sortByPrice(int currentIndex){
	for (int i = 0; i < currentIndex; i++){
		for (int j = currentIndex; j > i; j--){
			if (price[j] < price[j - 1]){
				swapString(drinkName[j], drinkName[j - 1]);
				swapString(make[j], make[j - 1]);
				swapNumber(&volume[j], &volume[j - 1]);
				swapNumber(&price[j], &price[j - 1]);
				swapNumber(&duraton[j], &duraton[j - 1]);
			}	
		}
	}
}
void sortByVolume(int currentIndex){
	for (int i = 0; i < currentIndex; i++){
		for (int j = currentIndex; j > i; j--){
			if (volume[j] < volume[j - 1]){
				swapString(drinkName[j], drinkName[j - 1]);
				swapString(make[j], make[j - 1]);
				swapNumber(&volume[j], &volume[j - 1]);
				swapNumber(&price[j], &price[j - 1]);
				swapNumber(&duraton[j], &duraton[j - 1]);
			}	
		}
	}
}
//-----------------------------------//
int main(int argc, char *argv[]) {
    int choice;
    int currentIndex = -1;
    int num;
    int volumeMin, volumeMax;
    int count;
    int* searchResultIndex;
    char *str = (char *) malloc(50 * sizeof(char));

    do {
    	system("cls");
        printMenu();
        switch (choice = getChoice(1, 5)) {
            case 1:
                addDrink(++currentIndex);
                system("cls");
                break;
            case 3:
            	if (currentIndex == -1) {
            		printf("nothing to show!\n");
            		fflush(stdin);
            		getchar();
				}
            	
            	else {
            		system("cls");
            		printf("Input volume min: ");
            		scanf("%d", &volumeMin);
            		printf("Input volume max: ");
            		scanf("%d", &volumeMax);
	                printDrinkByVolume(volumeMin, volumeMax, currentIndex);
					fflush(stdin);
					getchar();
				}
                
                break;
            case 2:
                // search
                system("cls");
                fflush(stdin);
                printf("input some word to search: ");
                scanf("%[^\n]", str);
                searchResultIndex = searchMakeBySomeWord(str, currentIndex);   
				printf("\n\tSEARCH RESULT\n"); 
				if (searchResultIndex[0] != -1){
					for (int i = 0; i < MAX && searchResultIndex[i] != -1; i++){
						printf("%d.\n", i + 1);
						printf("  Name:\t\t%s\n", drinkName[searchResultIndex[i]]);
						printf("  Make:\t\t%s\n", make[searchResultIndex[i]]);
						printf("  Volume:\t%d\n", volume[searchResultIndex[i]]);
						printf("  Price:\t%d\n", price[searchResultIndex[i]]);
						printf("  Duration:\t%d\n\n", duraton[searchResultIndex[i]]);
					}
				} else {
					printf("\n Not found anything!");
				} 
				getchar();
				getchar();
//                free(str);
//                free(searchResultIndex);
                break;
            case 4:
                // print list
				system("cls");
				sortByPrice(currentIndex);
				sortByVolume(currentIndex);
				printDrinkList(currentIndex);
				
				fflush(stdin);
				getchar();
                break;
        }

    } while (choice != 5);
	return 0;
}
 


