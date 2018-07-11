#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int a[10001] = { 0 };
	int index;
	for (int i = 0; i < n; i++) {
		scanf("%d", &index);
		a[index] += 1;
	}
	for (int i = 0; i < n; i++) {
		while (a[i] > 0) {
			printf("%d\n", i);
			a[i] -= 1;
		}
	}
	return 0;
}