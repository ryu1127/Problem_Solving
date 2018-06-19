#include<stdio.h>
#include<algorithm>

using namespace std;

int d[10002] = {0};
int p[10002] = {-1};

// int cal(int i);

int main(){
	int n;
	scanf("%d",&n);

	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	d[1] = p[1];
	d[2] = p[1]+p[2];
	d[3] = max(d[2],max(d[1]+p[3],p[2]+p[3]));
	for(int i=4;i<=n;i++){
		d[i] = max(d[i-1],max(d[i-2]+p[i],d[i-3]+p[i-1]+p[i]));
	}

	printf("%d\n",d[n]);
	return 0;
}

// int cal(int i){
// 	if(i==1){
// 		return p[1];
// 	}
// 	else if(i==2){
// 		return p[1]+p[2];
// 	}
// 	else if(i==3){
// 		return max(p[1]+p[2],max(p[1]+p[3],p[2]+p[3]));
// 	}
// 	// d[i] = max(cal(i-2)+cal(i-1),max(cal(i-1)+p[i],cal(i-2)+p[i]));
// 	d[i] = max(cal(i-1),max(cal(i-2)+p[i],cal(i-3)+p[i-1]+p[i]));
	
// 	return d[i];
// }



