#include<cstdio>


int main(){
    int stick;
    int count=0;
    scanf("%d",&stick);
    while(1){
        if(stick>=64){
            stick-=64;
            count++;
        }
        else if(stick>=32) {
            stick -= 32;
            count++;
        }
        else if(stick>=16){
            stick -= 16;
            count++;
        }
        else if(stick>= 8){
            stick -= 8;
            count++;
        }
        else if(stick>= 4){
            stick -= 4;
            count++;
        }
        else if(stick >= 2){
            stick -= 2;
            count++;
        }
        else if(stick==1){
            stick -= 1;
            count++;
        }
        else{
            break;
        }
    }
    printf("%d\n",count);
    return 0;
}