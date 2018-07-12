#include<cstdio>


int d(int n){
    int n1,n2,n3,n4;
    if(n<10){
        return n;
    }
    else if(n<100){
        return n;
    }
    else{
        int num = n;
        int cnt=0;
        for(int i=100;i<=num;i++){
            //109
            n = i;
            n1 = n/100;  //1
            n = n % 100;
            n2 = n/10;   //0
            n = n % 10;
            n3 = n;     //9
            if((n1-n2)==(n2-n3)) {
                // printf("%d\n",i);
                cnt++;
            }
        }
        return cnt+99;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",d(n));
    return 0;
}