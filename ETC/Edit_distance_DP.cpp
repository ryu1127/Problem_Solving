#include<iostream>
#include<cstdio>
#include<string>
#include<stdio.h>


using namespace std;
int editDist(string str1, string str2, int m, int n);

int main(){
    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDist(str1,str2,str1.length(),str2.length());
    return 0;
}

int editDist(string str1, string str2, int m, int n){

    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0) dp[i][j] = j; //Min operations = j
            else if(j==0) dp[i][j] = i; // Min operation = i
            else if (str1[i-1] == str2[i-1]) dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i][j-1] , //Insert
                                   dp[i-1][j],  //Remove
                                   dp[i-1][j-1]);          //Replace 

        }
    }
    return dp[m][n];
}