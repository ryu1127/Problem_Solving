#include<stdio.h>
#include<math.h>

int main() {

	int M, N;
	int sm, sn;
	int as1 = 0, as2 = 0;
	scanf("%d%d", &M, &N);
	if (M > 10000 || N > 10000 || M > N) return 0;
	sm = sqrt(M);
	sn = sqrt(N);

	if (sm == sn&& sm*sm == M) {
		as2 = sm*sm;
		as1 = as2;
		printf("%d\n%d", as1, as2);
		return 0;
	}
	else if (sm == sn && sm*sm != M) {
		printf("%d", -1);
		return 0;
	}
	
	if (sm*sm == M) {
		as2 = sm *sm;
		if (sn*sn == N) {
			for (int i = sm; i <= sn; i++) {
				as1 += i *i;
			}
		}
		else {
			for (int i = sm; i < sn; i++) {
				as1 += i *i;
			}
		}
	}
	else {
		as2 = (sm + 1) *(sm+1);
		if (sn *sn == N) {
			for (int i = sm+1; i <= sn; i++) {
				as1 += i *i;
			}
		}
		else {
			for (int i = sm; i < sn; i++) {
				as1 += i *i;
			}
		}
	}
	printf("%d\n%d", as1, as2);
	return 0;
	
}