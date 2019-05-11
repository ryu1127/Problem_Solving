#include<cstdio>
#include<iostream>

using namespace std;

int main() {
	int n;
	int i;
	cin >> n;
	if (n == 1) printf("*");
	else {
		for (int line = 1; line <= n; line++) {
			for (i = 1; i <= n - line; i++) {
				printf(" ");
			}
			printf("*");
			//1+2*(line-2)
			if (line != n) {
				for (i = 0; i < (1 + 2 * (line - 2)); i++) { 
					printf(" "); 
				}
				if(line!=1)	printf("*");
			}
			else {
				for (i = 0; i < (2*n)-2; i++) {
					printf("*");
				}
			}

			if (line != n) printf("\n");
		}
	}
	return 0;
}