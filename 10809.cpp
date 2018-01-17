#include <iostream>
#include <string>
#include <algorithm>
#include<string.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int len = s.length();
	for (int i = 'a'; i <='z'; i++) {
		for (int j = 0; j < len; j++) {
			if (i == s[j]) {
				cout << j << " ";
				break;
			}
			else if (j == len-1) {
				cout << -1 << " ";
			}
		}
	}
	return 0;
};