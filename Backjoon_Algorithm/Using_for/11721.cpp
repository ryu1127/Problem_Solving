#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    cin >> s;
    int i=0;
    int size = s.size();
    // printf("size of String : %d",size);
    for(int k=0;k<size;k++){
        printf("%c",s[i]);
        i++;
        if(i%10==0) printf("\n");
    }
    return 0;
}
