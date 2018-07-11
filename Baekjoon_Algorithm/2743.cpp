#include<stdio.h>

int main(){
	char str[102];
	scanf("%s",str);
	int len=0;
	for(int i=0;str[i];i++){
		len++;
	}
	printf("%d\n",len);
	return 0;
}