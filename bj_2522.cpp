#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	if (N < 1 || N>100) return 0;
	int total = N * 2;
	
	for (int i = 0; i < N; i++) {
		for (int j = i; j >= 0; j--) {
			printf("*");
		}
		printf("\n");
	}
	for (int i =N-1; i >0; i--) {
		for (int j = i; j > 0; j--) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}