#include<stdio.h>
int main() {

	int n;
	int a = 1;
	scanf("%d", &n);
	if (n == 0) a = 0;
	else a = (n / 5);
	int b;
	b = (n / 25);
	int c;
	c = (n / 125);
	int count = a + b + c;

	printf("%d", count);
	return 0;
}