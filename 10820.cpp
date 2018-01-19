#include<stdio.h>
#include<string.h>

int main(){

	char str[102];

	int upper_case,lower_case,number,gap;

	while(fgets(str,102,stdin)!=NULL){
		upper_case = 0;
		lower_case = 0;
		number = 0;
		gap = 0;
		int len; 
		len = strlen(str)-1; // except \n

		for(int i=0;i<len;i++){
			if(str[i]>='a' && str[i]<='z'){
				lower_case++;
			}
			else if(str[i]>='A' && str[i]<='Z'){
				upper_case++;
			}
			else if(str[i]==' '){
				gap++;
			}
			else{
				number++;
			}
		}
		printf("%d %d %d %d\n",lower_case,upper_case,number,gap);

	}
	return 0;
}