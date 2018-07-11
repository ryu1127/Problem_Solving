#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int lcs(char *X, char *Y, int m, int n);

int main(){
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    // char X[] = "AGGTA";
    // char Y[] = "BGTBA";

    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of LCS is %d\n",lcs(X,Y,m,n));   
    return 0;
}

int lcs(char *X, char *Y, int m, int n){
    int L[m+1][n+1];
    int i,j;
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            if(i==0||j==0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1]){
                L[i][j] = L[i-1][j-1] + 1;
            }
            else
                L[i][j] = max(L[i-1][j],L[i][j-1]);
        }
    }
    for(int i=m;i>0;i++){
        for(int j=n;j>0;j++){
            if(L[i][j]!=L[i-1][j]){
                
            }
        }
    }

    return L[m][n];
}
