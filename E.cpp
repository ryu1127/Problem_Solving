#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
    int n;
    int temp;
    vector<int> a;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        a.push_back(temp);
    }
    sort(a.begin(),a.end());
    int sum = 0;
    int tem;

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            tem = int(pow(2.0,double(j-i-1)));
            sum += (a[j]-a[i])*tem;
            sum = sum % 1000000007;
        }
    }
    printf("%d",sum);
    return 0;
}