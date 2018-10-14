#include<cstdio>




int main(){

    int train[5] = {0};
    int max = 0;
    int ip_p,op_p;
    for(int i=0;i<4;i++){
        scanf("%d",&ip_p);
        scanf("%d",&op_p);
        train[i+1] = train[i] - ip_p + op_p ;
        if(train[max]<train[i+1]) max = i+1;
    }

    printf("%d",train[max]);
    return 0;
}