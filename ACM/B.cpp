#include <iostream>

int length1, length2;
char string1[50];
char string2[50];
char stringLast[100];
using namespace std;
int main(){
	cin >> length1 >> length2;

	for (int i = 0; i < length1; i++ ) {
		cin >> string1[i];
	}
	
	for (int i = 0; i < length2; i++ ) {
		cin >> string2[i];
	}
	
	for (int i = 0; i < length1; i++ ) {
		cout << string1[i];
		cout << string2[i];
	}
	return 0;
}
