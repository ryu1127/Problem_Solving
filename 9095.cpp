#include<stdio.h>

int d[100001] = { 0 };
int cal(int i);

int main() {
	int testCase;
	scanf("%d", &testCase);
	
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;


	while (testCase--) {
		int number;
		scanf("%d", &number);
		int temp;
		temp = cal(number);
		printf("%d\n", temp);
	}
	return 0;

}

int cal(int i) {
	if (d[i] > 0) return d[i];
	d[i] = cal(i - 1) + cal(i-2) + cal(i-3);
	return d[i];
}