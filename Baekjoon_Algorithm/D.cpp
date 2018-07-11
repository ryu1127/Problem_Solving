#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n,m;
vector<int> a;


int main(){

    // int num[500001] = {0};
    vector<int> num(500001,0);
    scanf("%d%d",&n,&m);
    int temp;   
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        a.push_back(temp);
    }
    int cnt = 0;
    int result = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(result >= n-i+1){
                printf("%d",result);
                return 0;
            }

            if(num[a[j]]==0){
                num[a[j]] = 1;
                cnt++;
                // printf("enter\n");
            } 
            else{
                if(result < cnt) {
                    result = cnt;
                    // printf("result : %d\n",result);
                    
                }
                // for(int i=0;i<500001;i++){
                //     num[i] = 0;
                // }
                vector<int> temp(500001,0);
                num = temp;
                cnt = 0;
                break;
            }
        }
    }

    printf("%d",result);
    return 0;
    
}