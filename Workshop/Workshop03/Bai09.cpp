#include <stdio.h>
	
	
	int gcd( int a, int b)
		{ while ( a != b )
		if (a > b) a -=b;
		else b -= a;
		return a;
	}
	
	int lcm ( int a, int b)
		{ return a*b/ gcd(a,b);
	}
	
	main(){
		int a, b, d, m;
		
		do {
			printf(" Nhap vao a, b: ");
			scanf("%d %d", &a, &b);
		}
		while ( a <= 0 or b <= 0);
		
		d = gcd (a, b);
		m = lcm (a, b);
		
		printf("%d\n", d);
		printf("%d", m);
	}
