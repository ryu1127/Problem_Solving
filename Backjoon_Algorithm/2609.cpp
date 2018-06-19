#include<stdio.h>
#include<algorithm>

using namespace std;

int main() {
	int n1, n2;
	scanf("%d%d", &n1, &n2);
	int num;

	int as1=1, as2;

	num = min(n1, n2);
	while (true) {
		if (n1 % num == 0 && n2 % num == 0) {
			as1 = num;
			break;
		}
		else num--;
	}
	as2 = as1 * (n1 / as1) * (n2 / as1);
	printf("%d\n%d", as1, as2);
	return 0;

}