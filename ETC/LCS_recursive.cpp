#include<cstdio>
#include<iostream>

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
    //한쪽의 문자열이 종료되면 리턴
    if(m == 0 || n == 0) 
        return 0;
    //맨 뒤 글자가 같으면 1을 더하고 한글자씩 뺀걸로 다시 recursion
    if(X[m-1]==Y[n-1]) 
        return 1 + lcs(X,Y,m-1,n-1);
    //맨 뒤 글자가 다르면 한글자씩 뺀걸로 recursion
    else
        return max(lcs(X,Y,m,n-1), lcs(X,Y,m-1,n));
}
