#include<stdio.h>

int K;
int tree[1025];
int SQR(int a,int k){
    int tmp ;
    tmp = 1;
    while(k--){
        tmp *= a;
    }
    return tmp;
}

void solve(){
    int c,j;
    int i=1;
    int ans,idx;
    c=1;
    while(1){
        if(i>K) return;
        idx = SQR(2, K - i);
        for(j=0;j<SQR(2,c-1);j++) {
            printf("%d ", tree[idx]);
            idx = idx + SQR(2,K-i+1);
        }
        idx = 0;i++;
        if(i>K) return;
        printf("\n");
        c++;
    }
}
int main()
{
    int i;
    scanf("%d",&K);
    for(i=1;i<=(SQR(2,K)-1);i++){
        scanf("%d",&tree[i]);
    }
    solve();

    return 0;
}