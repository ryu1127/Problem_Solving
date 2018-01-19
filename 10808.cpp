#include<stdio.h>
#include<string.h>

using namespace std;

int main(){
	char str[102];
	scanf("%s",str);
	int size;

	size = strlen(str); //개행문자 포함 안함

	for(int i='a';i<='z';i++){
		int count=0;
		for(int j=0;j<size;j++){
			if(i==str[j]){
				count++;
			}
		}
		printf("%d ",count);
		count = 0;
	}
	return 0;

}