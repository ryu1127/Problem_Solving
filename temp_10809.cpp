#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	char s[100];
	cin >> s;
	int len = strlen(s);
	printf("%d\n", len);
	for (int i = 'a'; i <= 'z'; i++) {
		for (int j = 0; j<len; j++) {
			if (i == s[j]) {
				cout << j << " ";
				break;
			}
			else if (j == len - 1) {
				cout << -1 << " ";
			}
		}
	}
	return 0;
}