#include<stdio.h>
#include<algorithm>

using namespace std;

int main() {
	int l, c;
	scanf("%d%d", &l, &c);
	char alpa[15];
	for (int i = 0; i < c; i++) {
		char temp;
		scanf("%c", &temp);
		alpa[i] = temp;
		if (i == c - 1) alpa[i + 1] = '\0';
	}
	
	return 0;

}