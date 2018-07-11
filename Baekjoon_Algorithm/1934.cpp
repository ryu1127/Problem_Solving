#include<stdio.h>
#include<algorithm>

using namespace std;

int GCD(int a, int b);

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int a, b;
		int g;
		scanf("%d%d", &a, &b);
		g = GCD(a, b);
		printf("%d\n", (a*b) / g);
	}
	return 0;
}

int GCD(int a, int b) {
	int g=1;
	int minValue;
	if (a >= b) minValue = b;
	else minValue = a;

	for (int i = minValue; i>0; i--) {
		if (a%i == 0 && b%i == 0) {
			g = i;
			return g;
		}
	}
	return g;
}

