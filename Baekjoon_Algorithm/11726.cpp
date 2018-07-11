#include<stdio.h>

int d[1001] = {0};

int cal(int n);

int main(){
	int n;
	scanf("%d",&n);


	d[1] = 1;
	d[2] = 2;
	d[3] = 3;
	
	printf("%d\n",cal(n)%10007);
	return 0;
}

int cal(int n){
	if(d[n]>0){
		return d[n]%10007;
	}
	d[n] = cal(n-1) + cal(n-2);
	return d[n]%10007;
}
