#include<stdio.h>
#include<vector>

using namespace std;

char temp[30];
char pw[15] = { 'Z' };
char res[15];
int l, c;

int compare(const void *a, const void *b) {
	return strcmp((char*)a, (char*)b);
}


void dfs(int depth) {
	
}

int main() {
	scanf("%d%d", &l, &c);
	if (l < 3 || c<3 || l>c || l>15 || c > 15) return 0;
	
	for (int i = 0; i < c+c-1; i++) {
		scanf("%c", temp[i]);
	}
	for (int i = 0; i < c; i++) {
		pw[i] = temp[i*2];
	}
	qsort(pw, c,sizeof(pw[0]),compare);
	
}

