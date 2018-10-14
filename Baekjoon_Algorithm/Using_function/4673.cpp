#include<cstdio>


int num[10001] = {1};

void d(int n){
    int n1,n2,n3,n4;
    int result = 0;
    result += n;
    n1 = n/1000;//1000의자리
    n = n % 1000;
    n2 = n/100; //100의자리
    n = n % 100;
    n3 = n/10;  //10의자리
    n = n % 10;
    n4 = n;     //1의자리
    result = result + n1 + n2 + n3 + n4;
    // printf("result : %d\n",result);
    // printf("num[%d] : 0\n",result);
    num[result] = 0;
    
}

int main(){
    for(int i=1;i<=10000;i++){
        d(i);
    }
    for(int i=1;i<=10000;i++){
        if(num[i]==1) printf("%d\n",i);
        printf("num[%d] : %d\n",i,num[i]);
    }
    return 0;
}