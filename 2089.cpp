#include<stdio.h>
#include<math.h>

int a, b;
int m;
int n[26] = { 0 };
int temp[26] = { 0 };
int index = 0;

int TenToB(int total);

int main() {
	
	scanf("%d%d", &a, &b);
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%d", &n[i]);
	}

	int total=0;

	//a진법 -> 10진법 변환
	for (int i = 0; i < m; i++) {
		total += n[i] * pow(a, m - i-1);
	}

	//10진법 -> b진법 변환
	TenToB(total);

	//print하기
	for (int i = index; i >= 0; i--) {
		printf("%d ", temp[i]);
	}

	return 0;
}

int TenToB(int total) {
	if ((total / b) >= b) {
		temp[index] = total % b;
		total = total / b;
		index++;
		TenToB(total);
	}
	else {
		temp[index] = total%b;
		index += 1;
		temp[index] = total / b;
		return 0;
	}
}
