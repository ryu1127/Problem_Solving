#include<cstdio>
#include<iostream>
#define mod 10007

using namespace std;

int n;

int d[1001][10]; //n개의 길이까지의 오르막 수
    int res =0;

// int dfs(int n,int depth){

// }


void bottom_up(){
    for(int i=0;i<=9;i++){
        d[1][i] = 1;
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=j;k++){
                d[i][j] += d[i-1][k];
                d[i][j] %= mod;
            }
        }
    }
    for(int i=0;i<=9;i++) res += d[n][i];
}

int main(){
    cin >> n;
    // dfs(0,0);
    bottom_up();
    printf("%d",res%mod);
    return 0;
}