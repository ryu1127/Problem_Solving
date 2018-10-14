#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){

	int number;
	scanf("%d",&number);

	int count=0;

	int d[1000002] = {0};
	d[1] = 0;
	d[2] = 1;
	d[3] = 1;
	d[4] = 2;

	//i
	int i=5;
	while(i<=number){
		if(i%3==0){
			if(i%2==0){
				d[i] = min(min(d[i/3],d[i/2]),d[i-1])+1;
			}
			else d[i] = min(d[i/3],d[i-1])+1;
		}else{
			if(i%2==0){
				d[i] = min(d[i/2],d[i-1])+1;
			}
			else d[i] = d[i-1]+1;
		}
		i++;
	}
	printf("%d",d[number]);
	return 0;
}
