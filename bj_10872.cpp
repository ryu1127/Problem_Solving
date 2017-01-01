#include<stdio.h>

int main() {

	int n;
	int a=1;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) a *= i;
	printf("%d", a);
	return 0;
}