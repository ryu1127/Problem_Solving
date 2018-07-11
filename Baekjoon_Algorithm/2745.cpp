#include<iostream>
#include<string>
#include<stdio.h>
#include<math.h>

using namespace std;

int main() {
	int b;
	string n;
	int result = 0;

	cin >> n;
	scanf("%d", &b);

	for (int i = 0; i < n.length(); i++) {
		int num = 0;

		if (n[i] >= 65 && n[i] <= 'Z') {
			num = n[i] - 55;
		}
		else {
			num = n[i] - 48;
		}
		result = result + num * (pow(b, n.length() - 1 - i));
	}
	printf("%d\n", result);
	return 0;
}