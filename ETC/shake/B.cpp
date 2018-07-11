#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<vector<int> > a;

int n; // 격자 크기
int t; // 일반 -> 변신 모드 턴의 수
int r; // 목표지점의 행 < n
int c; // 목표지점의 열 < n
char s[500];

int findRoute(int x, int y,int status){
    int max_x = 0;
    int max_y = 0;
    if(x==1&y==1) return 0;

    //----------현재 위치가 워프 지점일때 -------------------
    //왼쪽 라인 체크 (워프지점)
    for(int i=x;i>=1;i--){
        if(a[i][y]==1) max_x = i;
    }
    //윗 라인 체크 (워프지점)
    for(int i=y;i>=1;i--){
        if(a[x][i]==1) max_y = i;
    }
    //윗 라인, 왼쪽 라인 비교해서 더 큰쪽으로 이동 
    if(max_x>max_y) findRoute(x,max_y,1);
    else findRoute(max_x,y,1);
    //-------------------------------------------------

    //----------현재 위치가 워프 지점이 아닐 때 --------------
    

    //-------------------------------------------------
    
}

int main(){
    scanf("%d%d%d%d",&n,&t,&r,&c);
    for(int i=1;i<=n;i++){
        cin >> s; //정상 입력
        int val;
        for(int j=1;j<=n;j++){
            //워프에 1로 작성
            if(s[j]=='#') val = 1; 
            else val = 0;
            a[i][j] = val;
        }
    }

    return 0;
}

