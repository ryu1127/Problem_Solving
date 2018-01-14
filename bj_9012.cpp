#include<cstdio>
#include<iostream>
#include<stack>
#include<string>
#include<cstring>

using namespace std;

int main() {

	int n;
	char c[100];
	scanf("%d", &n);

	for (int j = 0; j<n + 1; j++) {
		stack<int> s;
		fgets(c, 100, stdin);
		int len;
		len = strlen(c);
		c[len - 1] = '\0';
		int size = 0;
		while (c[size++]);
		for (int i = 0; i<size - 1; i++) {
			if (c[i] == '(') s.push(1);
			else if (c[i] == ')') {
				if (s.empty()) {
					printf("NO\n");
					break;
				}
				else s.pop();
			}
			if (i == size - 2) {
				if (s.empty()) printf("YES\n");
				else printf("NO\n");
			}
		}

	}
	return 0;
}