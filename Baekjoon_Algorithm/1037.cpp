#include<stdio.h>
#include<vector>

using namespace std;

int main() {
	int num;
	scanf("%d", &num);
	vector<int> ar;
	for (int i = 0; i < num; i++) {
		int temp;
		scanf("%d", &temp);
		ar.push_back(temp);
	}
	int N;
	int max = ar[0];
	int min = ar[0];
	for (int i = 0; i < ar.size(); i++) {
		if (max < ar[i]) max = ar[i];
		if (min > ar[i]) min = ar[i];
	}

	int size = ar.size();
	if (size == 1) {
		N = ar[0] * ar[0];
	}
	
	else {
		N = min*max;
	}
	printf("%d", N);
	return 0;
}