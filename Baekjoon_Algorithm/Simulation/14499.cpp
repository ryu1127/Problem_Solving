//#include<cstdio>
#include<iostream>
#include<vector>
#define sync() { ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL); }

using namespace std;

//map m*n
int n, m;
//x좌표 , y좌표
int x, y;
//명령의 개수
int k;

typedef vector<int> v;
typedef vector<v> vv;

int nextR[5] = {0,0,0,-1,1};
int nextC[5] = {0,1,-1,0,0};


//map
vv space;
v operation;

v dice = { 0,0,0,0,0,0 };
enum DIRECTION {EAST = 1, WEST, NORTH, SOUTH};

//Rotate 함수 
void rotate(int direction) {
	int tmp = dice[0];
	switch (direction) {
	case EAST:
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[2];
		dice[2] = tmp;
		break;
	case WEST:
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[3];
		dice[3] = tmp;
		break;
	case NORTH:
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[1];
		dice[1] = tmp;
		break;
	case SOUTH:
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[4];
		dice[4] = tmp;
		break;

	}
}

void solve() {
	for (int i = 0; i < k; i++) {

		int nextX = x + nextR[operation[i]];
		int nextY = y + nextC[operation[i]];
		
		//exception handling
		if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) continue;
		
		//rotate
		rotate(operation[i]);
		x = nextX; y = nextY;
		if (space[nextX][nextY] == 0) space[nextX][nextY] = dice[5];
		else {
			dice[5] = space[nextX][nextY];
			space[nextX][nextY] = 0;
		}
		cout << dice[0] << "\n";
	}
}


int main() {

	cin >> n >> m >> x >> y >> k;
	space = vv(n, v(m));
	operation = v(k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> space[i][j];
		}
	}
	for (int i = 0; i < k; i++) cin >> operation[i];
	solve();
	return 0;
}






//#include <iostream>
//#include <vector>
//
//#define sync() { ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL); }
//
//using namespace std;
//
//enum DIRECTION { EAST = 1, WEST, NORTH, SOUTH };
//
//int nextR[5] = { 0, 0, 0, -1, 1 };
//int nextC[5] = { 0, 1, -1, 0, 0 };
//
//typedef vector<int> vi;
//typedef vector<vi> vvi;
//
//int n, m; // 세로, 가로
//vvi space; // 지도
//int x, y, k; //	초기(세로, 가로) 위치, 명령 개수
//
//vi operations; // 명령어 모음
//vi dice = { 0, 0, 0, 0, 0, 0 }; // 주사위
//
//void rotate(int direction) {
//	int tmp = dice[0];
//	switch (direction) {
//	case EAST:
//		dice[0] = dice[3];
//		dice[3] = dice[5];
//		dice[5] = dice[2];
//		dice[2] = tmp;
//		break;
//	case WEST:
//		dice[0] = dice[2];
//		dice[2] = dice[5];
//		dice[5] = dice[3];
//		dice[3] = tmp;
//		break;
//	case NORTH:
//		dice[0] = dice[4];
//		dice[4] = dice[5];
//		dice[5] = dice[1];
//		dice[1] = tmp;
//		break;
//	case SOUTH:
//		dice[0] = dice[1];
//		dice[1] = dice[5];
//		dice[5] = dice[4];
//		dice[4] = tmp;
//		break;
//	}
//}
//
//void solve() {
//	for (int i = 0; i < k; ++i) {
//		int nextX = x + nextR[operations[i]];
//		int nextY = y + nextC[operations[i]];
//		// 예외 조건
//		if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) {
//			continue;
//		}
//		// 회전
//		rotate(operations[i]);
//		x = nextX;
//		y = nextY;
//		// 바닥이 0인 경우
//		if (space[nextX][nextY] == 0) {
//			space[nextX][nextY] = dice[5];
//		}
//		// 바닥이 숫자인 경우
//		else {
//			dice[5] = space[nextX][nextY];
//			space[nextX][nextY] = 0;
//		}
//		// 윗면 출력
//		cout << dice[0] << endl;
//	}
//}
//
//int main() {
//	sync();
//	cin >> n >> m >> x >> y >> k;
//	space = vvi(n, vi(m));
//	operations = vi(k);
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			cin >> space[i][j];
//		}
//	}
//	for (int i = 0; i < k; ++i) {
//		cin >> operations[i];
//	}
//	solve();
//	return 0;
//}