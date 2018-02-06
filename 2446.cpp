#include<stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	if (N < 1 || N>100) return 0;
	int total = N * 2;

	for (int i = 0; i < N; i++) {
		
		for (int j = 0; j < i; j++) {
			printf(" ");
		}
		for (int k = i; k < total - i-1; k++) {
			printf("*");
		}
		printf("\n");
		
	}
	for (int i = N - 1; i > 0; i--) {
		for (int j = 1; j < i; j++) {
			printf(" ");
		}
		for (int k = i; k < total - i + 1 ; k++) {
			printf("*");
		}
		printf("\n");
		
	}

	return 0;
}