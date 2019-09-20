#include<stdio.h>

int gcd(int a, int b){
    if(a<b) gcd(b,a);
    if(b==0) return a;
    return gcd(b,a%b);
    
}


int main(){
    int n;
    scanf("%d",&n);
    int first;
    int arr[n+1];
    int i;
    for(i=0;i<n;i++){
        if(i==0) scanf("%d",&first);
        else {
            scanf("%d",&arr[i]);
            if(first%arr[i]==0) printf("%d/%d\n",first/arr[i],1);
            else {
                int tmp = gcd(first,arr[i]);
                printf("%d/%d\n",first/tmp,arr[i]/tmp);
            }
        }
    }
    return 0;
}