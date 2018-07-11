#include<stdio.h>

int main() {

	int ar[8];

	for (int i = 0; i < 8; i++) {
		scanf("%d", &ar[i]);
	}
	if (ar[0] == 1 && ar[1] == 2 && ar[2] == 3 && ar[3] == 4 && ar[4] == 5 && ar[5] == 6 && ar[6] == 7 && ar[7] == 8) printf("ascending");
	else if (ar[0] == 8 && ar[1] == 7 && ar[2] == 6 && ar[3] == 5 && ar[4] == 4 && ar[5] == 3 && ar[6] == 2 && ar[7] == 1) printf("descending");
	else printf("mixed");
	return 0;
}