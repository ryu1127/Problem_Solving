#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int c; //test case

    double result;
    int temp_result;
    scanf("%d",&c);
    for(int i=0;i<c;i++){
        //main loop
        temp_result = 0;
        int n;
        int temp;
        int cnt = 0;
        vector<int> a;
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            scanf("%d",&temp);
            a.push_back(temp);
            temp_result += temp;
        }
        sort(a.begin(),a.end());
        result = temp_result/n;
        for(int j=0;j<n;j++){
            if(a[j]>int(result)) cnt++;
            printf("cnt : %d\n",cnt);
        }
        cout << "average : " << result << endl;
        cout << "cnt : " << cnt << endl;
        cout << "n : " << n << endl;
        result = double(cnt*100)/double(n);
        cout << "result : " << result << endl;
        printf("%.3lf",result);
        printf("%%\n");
    }
    return 0;
}