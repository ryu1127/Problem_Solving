#include<stdio.h>

int primeNumber(long long number);

using namespace std;

int main() {

	int m, n;
	scanf("%d%d", &m, &n);

	for (int i = m; i <= n; i++) {
		if (i == 1) continue;
		if (primeNumber(i)) {
			printf("%d\n", i);
		}
	}
	return 0;
}

int primeNumber(long long number) {
	for (long long i = 2; i*i <= number; i++) {
		if (number % i == 0) {
			return 0;
		}
	}
	return 1;
}