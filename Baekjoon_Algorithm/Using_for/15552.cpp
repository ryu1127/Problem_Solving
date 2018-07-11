#include<cstdio>
#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TestCase;
    cin >> TestCase;
    int n1,n2;
    for(int i=0;i<TestCase;i++){
        cin >> n1;
        cin >> n2;
        cout << n1 + n2 << "\n";
    }
    return 0;
}