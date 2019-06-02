#include<stdio.h>
#include<stdlib.h>

#define max(a,b) (a)>(b) ? a : b;
int *d;
int n;
int *arr;
int max;


void input(){
    scanf("%d",&n);
    arr = (int *)calloc(n+1,sizeof(int));
    d = (int *)calloc(n+1,sizeof(int));
    int i;
    for(i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    max = arr[1];
}
int solve(int n){

    if(n==1){
        return d[n] = arr[n];
    }
    else if(d[n]!=0){
        return d[n];
    }
    else{
        d[n] = max(solve(n-1)+arr[n],arr[n]);
    }
    if(max<d[n]) max = d[n];
    return d[n];
}

void output(){
    printf("%d\n",max);
}


int main(){
    input();
    solve(n);
    output();
    return 0;
}