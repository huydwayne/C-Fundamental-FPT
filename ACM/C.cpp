#include <iostream>

int n, m;
int a[100000];
int count[100000];

using namespace std;

int main(){
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		a[i] = 0;
		count[i] = 0;
		cin >> a[i];
	}
	int index = 0;
	count[a[index]]++;
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
	for (int i = 0; i <= n; i++) {
		if (count[i] > 0) {
			index = i;
		}
	}
	cout << index;
	return 0;
}
