#include<stdio.h>

int main(){
	int d[1001] = {0};
	int m[1001] = {-1};
	int n;
	scanf("%d",&n);

	for(int i=1;i<=n;i++){
		scanf("%d",&m[i]);
	}

	d[1] = 1;
	if(n==1) {
		printf("%d",d[1]);
		return 0;
	}

	for(int i=2;i<=n;i++){
		int max=d[1];
		int check = 0;
		for(int j=1;j<i;j++){
			if(m[i]>m[j]){
				if(max<d[j]+1){
					check = 1;
					max = d[j]+1;
				}
			}
		}
		if(check == 1){
			d[i] = max;
		}
		else{
			d[i] = 1;
		}
	}
	int result = 0;
	for(int i=1;i<=n;i++){
		if(result<d[i]) result = d[i];
	}
	printf("%d",result);
	return 0;
}