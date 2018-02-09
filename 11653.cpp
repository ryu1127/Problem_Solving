#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int index = n;
	for (int i = 2; i * 2 <= index; i++) {
		while (1) {
			if (n == 1) {
				return 0;
			}
			if (n % i == 0) {
				printf("%d\n", i);
				n /= i;
			}
			else break;
		}   
	}
	if (n > 1) {
		printf("%d\n", n);
	}
	return 0;
}