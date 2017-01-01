#include<stdio.h>
#include<vector>
#define MAX 1000001

using namespace std;

void gb_print(int a);
bool prime();
bool primes[MAX];

int main() {
	vector<int> gb;
	int sc;
	while (true) {
		scanf("%d", &sc);
		if (sc == 0) {
			break;
		}
		else gb.push_back(sc);
	}
	prime();
	for (int i = 0; i < gb.size(); i++) {
		gb_print(gb[i]);
	}
	return 0;
}

void gb_print(int a) {
	vector<int> prime_num;
	int b = a;
	int as1=0, as2=0;
	for (int i = 1; i <= a; i++) {
		if (primes[i] == true) {
			prime_num.push_back(i);
		}
	}
	for (int i = 0; i < prime_num.size()-1; i++) {
		for (int j = 0; j < prime_num.size(); j++) {
			if (prime_num[i] + prime_num[j] == a&& as2-as1<prime_num[j]-prime_num[i]) {
				as1 = prime_num[i];
				as2 = prime_num[j];
			}
		}
	}

	printf("%d = %d + %d\n", a, as1, as2);
}

bool prime() {		//i dont understand this.
	for (int i = 2; i < MAX; i++)
		primes[i] = true;
	for (int i = 2; i*i < MAX; i++)
		for (int j = 2; primes[i] && i*j < MAX; j++)
			primes[i*j] = false;
}

