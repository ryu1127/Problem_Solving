#include<cstdio>

using namespace std;
int check[10001] = {0};

int dn(int n);

int main(){
    int n=10000;
    // //test case number
    // scanf("%d",&n);
    int temp;
    
    for(int i=1;i<=n;i++){
        temp = dn(i);
        if(temp<=10000) check[temp] = 1;
        else break;
    } 
    for(int i=1;i<=n;i++){
        if(check[i]==0) printf("%d\n",i);
    }
    return 0;

    
}

int dn(int n){
    int temp;
    int sum = 0;
    sum += n;
    while(1){
        if(n/10>=1){
            temp = n % 10;
            n -= temp;
            n /= 10;
            sum += temp;
        }
        else{
            sum += n;
            break;
        }
    }
    return sum;
}