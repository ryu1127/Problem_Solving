#include<iostream>
#include<vector>

#define sync() {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}

using namespace std;
//N*M
int n,m;
//현재 좌표 r,c
int r,c;
//방향 direction d=
int d;
//방향 좌표 
enum {NORTH = 0,EAST, SOUTH, WEST};
//방향에 따른 움직임
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
//결과 저장
int cnt = 0;
//더이상 가는게 불가능
bool flag = false;
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi map;
struct Robot {
    int r;
    int c;
    int d;
};
void input(){
    // 3 <= N,M <= 50
    cin >> n >> m;
    cin >> r >> c >> d;
    map = vvi(n,vi(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
}
bool check_boundary(int next_r,int next_c){
    return (next_r < n && next_r>=0 && next_c < m && next_c >=0);
}
void dfs(int now_r,int now_c,int now_d){
    //바라보는 방향 왼쪽부터 탐색하게 하기 위해
    now_d = now_d - 1;
    //현재 위치 청소하기 ㅡ 청소했으면 2로 표시
    if(map[now_r][now_c]==0) {
        map[now_r][now_c]=2;
        cnt++;
    }
/*
5 5
1 1 0
1 1 1 1 1
1 0 1 0 1
1 0 0 0 1
1 0 1 0 1
1 1 1 1 1
*/

    for(int i=0;i<4;i++){
        //진행할 수 있을 때
        int next_r = now_r + dr[now_d];
        int next_c = now_c + dc[now_d];
        int next_d = now_d;
        if(check_boundary(next_r,next_c) && map[now_r][now_c]==0) dfs(next_r,next_c,next_d);
        now_d--;
    }
}

int main(){
    input();
    dfs(r,c,d);
    cout << cnt;
}