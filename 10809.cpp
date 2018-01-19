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
		int index=-1;
		for(int j=0;j<size;j++){
			if(i==str[j]){
				index = count;
				break;
			}
			count++;
		}
		printf("%d ",index);
		count = 0;
		index = -1;
	}
	return 0;

}