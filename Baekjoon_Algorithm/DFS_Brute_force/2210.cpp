#include<iostream>
#include<vector>
#include<set>

#define sync() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}

using namespace std;


typedef vector<char> v;
typedef vector<v> vv;
typedef vector<string> key;
vv map;
string su;
key pointTable;
set<string> PT;

struct location {
	int x;
	int y;
};

//자리수
int idx = 0;
//좌표값
int x = 0, y = 0;
enum {EAST=1,SOUTH, WEST, NORTH};
int dy[5] = { 0,1,0,-1,0 };
int dx[5] = { 0,0,1,0,-1 };

void input() {
	map = vv(5, v(5));
	char temp;
	//맵 전체 입력
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}
}


void dfs(int idx, location loc , string T) {


	//정수가 다 만들어져있음
	if (idx == 6) {
		PT.insert(T);
		return;
	}
	//dfs의 새로운 좌표를 만듬
	//int nx, ny;
	//T = T + map[loc.x][loc.y];
	//for (int i = 1; i <= 4; i++) {
	//	 if (loc.x + dx[i] > 4 || loc.y + dy[i] > 4 || loc.x + dx[i] < 0 || loc.y + dy[i] < 0) continue;
	//	 nx = loc.x + dx[i];
	//	 ny = loc.y + dy[i];
	//	 loc.x = nx;
	//	 loc.y = ny;
	//	 dfs(idx + 1, loc, T);
	//}
	T = T + map[loc.x][loc.y];
	int nx, ny;
	for (int i = 1; i <= 4; i++) {
		if (loc.x + dx[i] > 4 || loc.y + dy[i] > 4 || loc.x + dx[i] < 0 || loc.y + dy[i] < 0) continue;
		nx = loc.x + dx[i];
		ny = loc.y + dy[i];
		loc.x = nx;
		loc.y = ny;
		dfs(idx + 1, loc, T);
		nx = loc.x - dx[i];
		ny = loc.y - dy[i];
		loc.x = nx;
		loc.y = ny;
	}
}

void solve() {
	location loc;
	string t = "";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			loc.x = i; loc.y = j;
			dfs(0, loc, t);
		}
	}
}

void Print_Val() {
	cout << PT.size();
}


int main() {
	input();
	solve();
	Print_Val();
	return 0;
}
