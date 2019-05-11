#include<iostream>
#include<vector>
#include<queue>

#define sync() {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}

using namespace std;


//N*M
int n,m;

//현재 좌표 r,c
int r,c;
//방향 direction d=
int d;
enum {NORTH = 0,EAST, SOUTH, WEST};
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

//결과 저장
int cnt = 0;

typedef vector<int> vi;
typedef vector<vi> vvi;
vvi space;
struct Robot {
    int r;
    int c;
    int d;
};
int clean[51][51]={false};
queue<Robot> q;

void input(){
    // 3 <= N,M <= 50
    cin >> n >> m;
    cin >> r >> c >> d;
    space = vvi(n,vi(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> space[i][j];
        }
    }
}
//새로 가야할 방향을 리턴
int changeDirection(int d){
    if(d==NORTH) d = WEST;
    else d -= 1;
    return d;
}

bool check_boundary(int next_r, int next_c){
    if(next_r >= 0 && next_r < n && next_c >= 0 && next_c < m) return true;
    return false;
}
void solve(){

    //현재 방문한 곳을 청소하고 큐에 넣는다.
    Robot robot;
    robot.r = r;
    robot.c = c;
    robot.d = d;
    q.push(robot);
    clean[r][c] = true;
    cnt++;
    bool flag = false;


    while(!q.empty()){
        Robot next;
        //현재 방문하고 있는 노드의 정보 저장
        int now_r = q.front().r;
        int now_c = q.front().c;
        int now_d = q.front().d;
        q.pop();
        next.d = now_d;

        //현재 방향을 기준으로 왼쪽 방향부터 차례대로 탐색
        //왼쪽 방향 탐색
        for(int i=0;i<4;i++){
            next.d = changeDirection(next.d);
            next.r = now_r + dr[next.d];
            next.c = now_c + dc[next.d];
            if(check_boundary(next.r,next.c) && clean[next.r][next.c] == false){
                if(space[next.r][next.c]==0){
                    clean[next.r][next.c]=true;
                    q.push(next);
                    cnt++;
                    flag = true;
                    break;
                }
            }
        }

        //모두 청소가 되어있거나 벽인 경우
        if(!flag){
            //뒤로 돌아서
            next.d = changeDirection(next.d);
            next.d = changeDirection(next.d);
            //앞으로 전진 한칸
            next.r = now_r + dr[next.d];
            next.c = now_c + dc[next.d];
            //다시 방향 그대로
            next.d = changeDirection(next.d);
            next.d = changeDirection(next.d);
            if(check_boundary(next.r,next.c)){
                if(space[next.r][next.c]==0){
                    q.push(next);
                }
            }
        }
    }
}


int main(){
    sync();
    input();
    solve();
    cout << cnt;
    return 0;
}