#include<iostream>
#include<vector>
#include<queue>

#define sync() {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}

using namespace std;

//지도의 크기 n*m
int n,m;
typedef vector<int> vi;
typedef vector<vi> vvi;

//새로 벽을 지을 곳의 리스트
queue<pair<int,int>> q;



vvi map;

void input(){
    cin >> n >> m;
    map = vvi(n,vi(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
}

void solve(){
    for(int i=0;i)
}




int main(){
    sync();
}

