#include<stdio.h>

int main() {
	long long *a = new long long;
	printf("%s", ((long long)a % 5 ? "Yonsei" : "Korea"));
	delete a;
	return 0;
}