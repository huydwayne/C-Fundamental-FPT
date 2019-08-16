#include <stdio.h>
#include <ctype.h>
main(){
	char ch;
	int nVowels = 0;
	int nConsonants = 0;
	int nOthers = 0;
	
	do {
		ch = getchar();
		printf ("%c", ch);
		ch = toupper(ch);
		if (ch >= 'A' and ch <='Z'){
			switch (ch) {
				case 'A':
				case 'E':
				case 'I':
				case 'O':
				case 'U': nVowels++ ; break;
				
				default: nConsonants++;
			}
		}
		else nOthers++;
	} while (ch != '\n');
	printf ("%d\n", nVowels);
	printf ("%d\n", nConsonants);
	printf ("%d\n", nOthers);

	
}
