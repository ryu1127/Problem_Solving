// #include<cstdio>
// #include<string>


// int main(){
//     char str[1000001]={' '};
//     int cnt = 1;
//     scanf("%[^\n]s",str);
//     if(str[0]==' ') str[0] = 'a';
//     for(int i=0;i<1000000;i++){
//         if(str[i]==' ') {
//             if(str[i+1]!=' ') cnt++;
//         }
//         if(str[i]==EOF) break;
//     }
//     printf("%d",cnt);
//     return 0;
// }


#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    getline(cin,s);
    int cnt = 1;
    int size = s.size();

    if (size==1 && s[0]==' '){
        cout << 0;
        return 0;
    }

    if(s[0]==' ') cnt = 0;
    for(int i=0;i<size;i++){
        if(s[i]==' ') {
            if(i+1<size){
                cnt++;
            }
        else continue;
        }
    }
    cout << cnt;
    return 0;
    
}