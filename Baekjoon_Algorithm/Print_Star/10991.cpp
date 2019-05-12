#include<cstdio>
#include<iostream>

using namespace std;

int main(){
    int n;
    int i;
    cin >> n;
    for(int line = 1; line <= n; line++){
        for(i=1;i<=n-line;i++){
            printf(" ");
        }
        printf("*");
        for(i=0;i<line-1;i++){
            printf(" *");
        }
        for(i=1;i<=n-line;i++){
            printf(" ");
        }
    }
    return 0;

}




