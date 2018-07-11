#include<cstdio>
#include<iostream>

using namespace std;

int main(){
    int n;
    int result=0;
    scanf("%d",&n);
    int five,thr;
    for(five = 0;five<=n;five++){
        for(thr = 0; thr <= n; thr++){
            if(n == five*5+thr*3) result = five + thr;
        }
    }
    
    printf("%d",result == 0 ? -1 : result);

    return 0;

}