#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int n;
    int fix;
    int number;
    int first;
    int last;
    int cnt=0;

    scanf("%d",&fix);
    number = fix;
    while(1){
        if(number>9){
            first = number/10;
            last = number % 10;
            number = 10*last + (first + last) % 10;
            cnt++;
            if(number==fix) {
                printf("%d",cnt);
                return 0;
            }
        }
        else{
            number = 10*number + number;
            cnt++;
            if(number==fix) {
                printf("%d",cnt);
                return 0;
            }
        }
    }
    return 0;
}