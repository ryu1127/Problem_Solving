#include<stdio.h>

int n;

    int i;
    int cnt=0;

void input(){
    scanf("%d",&n);
}
void solve(){
    for(i=317;i>=1;i++){

        if(i*i < n){
            n -= (i*i);
            cnt++;
        }
        if(n==0) return;
        if(n<4) 
        {
            cnt += 3;
            return;
        }

    }

}
void output(){
    printf("%d\n",cnt);
}


int main(){
    input();
    solve();
    output();
    return 0;
}