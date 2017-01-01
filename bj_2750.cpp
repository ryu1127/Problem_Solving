#include<stdio.h>

void sort(int *array, int num);

int main()
{
	int num = 0;
	int a[1000];
	int c[1000];

	scanf("%d", &num);
	int *b = new int[num];
	for (int i = 0; i < num; i++) {
		scanf("%d", &b[i]);
	}
	printf("\n");
	sort(b, num);

	delete(b);
	return 0;

}

void sort(int *array, int num) {
	int temp;
	for (int i = 0; i < num - 1; i++) {
		for (int j = i; j < num - 1; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	for (int k = 0; k < num; k++) {
		printf("%d", array[k]);
	}
	
}