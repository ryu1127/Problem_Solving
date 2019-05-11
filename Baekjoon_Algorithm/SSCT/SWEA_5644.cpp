#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//총 테스트 케이스 개수
int T;

//총 이동시간 M, BC의 개수 A
int M,A;
    queue<int> q;
    int dis = 0;
//사용자의 이동정보
typedef vector<int> vi;
vi user1;
vi user2;
vector<vector<int>> map;
struct AP{
    //AP의 x, y좌표
    int x; int y;
    //C : 충전범위 , P : 처리량
    int C; int P;
};
struct user_loc{
    int x; int y;
};
typedef vector<AP> AP_LIST;
AP_LIST ap;

int dy[5] = {0,-1,0,1,0};
int dx[5] = {0,0,1,0,-1};

//1,2가 총 충전할 수 있는 양
int user1_total = 0;
int user2_total = 0;

void input(){
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> M >> A;
        user1 = vi(M);
        user2 = vi(M);

        //User의 이동정보 입력
        for(int j=0;j<M;j++) cin >> user1[j];
        for(int j=0;j<M;j++) cin >> user2[j];
        //AP 정보 입력
        AP tmp;
        for(int j=0;j<A;j++){
            cin >> tmp.x >> tmp.y >> tmp.C >> tmp.P;
            ap.push_back(tmp);
        }
    }
}

void initialize(){
    user_loc user1_loc,user2_loc;
    user1_loc.x = 1; user1_loc.y = 1;
    user2_loc.x = 10; user2_loc.y = 10;
}
void startAP(AP ap,int dis){
    //현재만 칠하고 나가기
    if(dis==ap.C){
        map[ap.x][ap.y]
    }
    //다음 위치
    int next_x, next_y;
    //왼쪽 칸에서 범위
    for(int k=1;k<5;k++){
        next_x = ap.x + dx[k];
        next_y = ap.y + dy[k];
        
        startAP(next_x,next_y,dis+1);
    }
}

void setAP(int i){
    AP aptmp;
    aptmp = ap[i];
    startAP(aptmp,0);
}
void solve(){
    initialize();
    for(int i=0;i<A;i++) setAP(i);
}


int main(){
    
}