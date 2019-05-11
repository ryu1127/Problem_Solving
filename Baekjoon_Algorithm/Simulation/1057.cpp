#include<iostream>

using namespace std;

//n이 2의 몇제곱인지 계산해주는 함수
int RetCount(int n){
    if(n==1) return 0;
    if(n/2>0){
        return 1 + RetCount(n/2);
    }
}

int main(){
    int n;
    int jimin, hansu;
    cin >> n >> jimin >> hansu;
    printf("%d\n",RetCount(n));
    /*
    //n이 짝수 일 때 
    if(n%2==0) {
        if(jimin + hansu > n){}
    }

    //n이 홀수 일 때 
    else{

    }
    */
   return 0;
}