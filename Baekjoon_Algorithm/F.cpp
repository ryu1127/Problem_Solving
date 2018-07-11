#include<cstdio>
#include<vector>

using namespace std;

int main(){
    int n;
    vector<int> f;
    int t;
    scanf("%d",&n);
    int temp;
    int buf;
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        f.push_back(temp);
    }
    scanf("%d",&t);
    sort(f.begin(),f.end());
    if(t==0){
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += f[i];
        }
        printf("%d 1",sum);
        return 0;
    }
    else{
        int result = 0;
        for(int i=0;i<n;i++){
            buf = f[i];
            
        }
    }

}

int gcd(int a,int b){
    if(b<a) gcd(b,a);
    if(b==0) return a;
    return gcd(a,b%a);
}