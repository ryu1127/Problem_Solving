#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

long long a[1000001] = { 0 };

int main() {
	int n;
	scanf("%d", &n);
	vector<long long> v;
	long long index;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &index);
		v.push_back(index);
	}
	if (n == 1) {
		printf("%lld", index);
		return 0;
	}
	sort(v.begin(), v.end());

	int max = 1;
	int count = 1;
	
	long long result = v[0];
	for (int i = 0; i<n-1; i++) {
		if (v[i] == v[i + 1]) count++;
		else {
			if(max<count){
				result = v[i];
				max = count;
			}
			count = 1;
		}
		if (max < count) {
			max = count;
			result = v[i];
		}
	}
	printf("%lld\n", result);
	return 0;
}
