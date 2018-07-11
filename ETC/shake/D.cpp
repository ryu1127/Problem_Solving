#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int idx;
int n;
int temp;
int maxVal = 0;
int sizes;
int cnt = 0;

vector<int> a;
vector<int> b;
vector<int> c;
vector<int> tem;
vector<int> btem;


//현재 배열이 맞는지 아닌지 
int isCorrect(){
    cout << "enter isCorrect " << endl;
    cnt++;
    idx = 0;
    int check = 0;
    int zz=0;
    while(1){
            // cout << "enter first While " << endl;
        check = 0;
        // if(a[idx]==0) idx++;
        // else{
        //     for(int i=idx;i<a[idx]+idx;i++){
        //         if(a[i]==0) check++;
        //     }
        //     idx = a[idx]+idx+check;
        //     if(idx == n) {
        //         printf("%d : Correct!\n",cnt);
        //         return 1;
        //     }
        //     if(idx > n) {
        //         printf("%d : Not Correct!\n",cnt);
        //         return 0;
        //     }
        // }
        if(idx>n-1) return 0; 
        if(a[idx]==0) idx++;
        else{
                // cout << "enter Else " << endl;
            int flag = a[idx];
            cout << "flag : " << flag << "\n";
            while(1){
                    // cout << "enter second while " << endl;
                if(check == flag-1){
                    cout << "check : " << check << endl;
                    cout << " idx : " << idx << endl;
                    if((n-1)==idx) {
                        cout << "end Correct at index " << idx << "\n";
                        return 1;
                    }
                    idx++;
                    if(n-1<idx) {
                        cout << "end Not Correct at index " << idx << "\n";
                        return 0;
                    }
                    if(a[idx]==1) idx++;
                    flag = a[idx];
                }
                idx++;
                if(a[idx]!=0) {
                    cout << "check at index " << idx << "\n";
                    check++;
                }
                
                if(idx>n-1) {
                    cout << "idx out of range\n";
                    return 0; 
                }
                
            }
            // cout << "exit Second While " << endl;
        }
    }
        cout << "exit First while " << endl;
}
int findVal(){
    //현재 올바르면 최소값 리턴
    
    if(isCorrect()) return maxVal;
    else {
        int csize = c.size();
        for(int i=0;i<csize;i++){
            printf("C[%d] : %d\n",i,c[i]);
            maxVal = c[i];
            for(int j=0;j<n;j++){
                if(b[j]==c[i]){
                    printf("j : %d\n",j);
                    // for(int k=0;k<n;k++){
                    //     if(k!=j) tem.push_back(a[k]);
                    //     if(k!=j) btem.push_back(b[k]);
                    // }
                    // a = tem;
                    // b = btem;
                    // n -= 1;
                    a[j] = 0;
                    if(isCorrect()) return maxVal;
                }
            }
        }
    }
    return maxVal;
}

int main(){

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        a.push_back(temp);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        b.push_back(temp);
        c.push_back(temp);
    }
    sizes = a.size();
    sort(c.begin(),c.end());
    int result = findVal();
    printf("%d",result);
    return 0;
}