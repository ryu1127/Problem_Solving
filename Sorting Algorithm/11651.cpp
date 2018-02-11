#include<stdio.h>
#include<algorithm>

int main() {
	std::pair<int, int> a[100001];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].second, &a[i].first);
	}
	std::sort(a, a + n);
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", a[i].second, a[i].first);
	}
	return 0;


}