#include <stdio.h>

int n, m;
int a[100000];
int count[100000];

int xuLy(){
	int index = 0;
	for (int i = index + 1; i < m ; i++){
		count[a[index]]++;
		if (a[index] + a[i] <= n) {
			count[a[index] + a[i]]++;
		}
		
		if ((i+1) == m && (index) < m) {
			index++;
			i = index;
		}
	}
	for (int i = 0; i < n; i++) {
		if (count[i] > 0) {
			index = i;
		}
	}
	return index;
}

int main(){
	scanf("%d", &n);
	scanf("%d", &m);
	
	for (int i = 0; i < m; i++) {
		a[i] = 0;
		count[i] = 0;
		scanf("%d", &a[i]);
	}
	printf("%d", xuLy());
	return 0;
}
