#include<cstdio>

using namespace std;

int main(){
    int s1,s2;
    scanf("%d%d",&s1,&s2);
    long long inp,ans;
    int flag=0;
    int check = 0;
    for(int i=0;i<s1;i++){
        scanf("%d%d",&inp,&ans);
        if(inp!=ans) flag = 1;
    }

    for(int i=0;i<s2;i++){
        scanf("%d%d",&inp,&ans);
        if(inp!=ans) check = 1;
    }

    if(flag==1) printf("Wrong Answer");
    else if(check==1) printf("Why Wrong!!!");
    else printf("Accepted");

    return 0;
}