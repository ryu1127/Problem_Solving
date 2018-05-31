#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n,k;
    int p;
    long long x,y;
    double result = 0;
    double temp;

    vector<double> a;

    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&p);
        result = 0;
        for(int j=0;j<p;j++){
            scanf("%lld%lld",&x,&y);
            temp = (x*x) + (y*y);
            if(temp > result) result = temp;
        }
        a.push_back(result);
    }
    sort(a.begin(),a.end());
    printf("%.2lf",a[k-1]);
    return 0;
}

