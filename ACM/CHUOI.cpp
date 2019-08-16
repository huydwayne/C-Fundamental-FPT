#include <fstream>
#include <iostream>
#define FI "CHUOI.INP"
#define FO "CHUOI.OUT"
#define MAX 20001

using namespace std;
int n;
char S[MAX];

void Nhap(){
	ifstream f;
	f.open( FI );
	
	f >> n;
	cout << n << endl;
	for (int i= 1; i <= n; i++) {
		f >> S[i];
	}
	
	for (int i = 1; i <= n; i++){
		cout << S[i];
	}
}

void xuly(){
	
	
}

void Xuat(){
	
}

main(){
	Nhap();
}
