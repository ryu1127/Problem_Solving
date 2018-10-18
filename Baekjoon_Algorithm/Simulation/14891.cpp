#include<iostream>
#include<vector>
#define sync(){ ios_base::sync_with_stdio(falase),cin.tie(NULL), cout.tie(NULL);}

using namespace std;

typedef vector<char> v;
typedef vector<v> vv;
//1,2,3,4톱니바퀴의 상태
v v1(8), v2(8), v3(8), v4(8);
vv v_array(4);
//N극 0, S극 1

//회전 횟수
int rot_num;

//시계 : 1, 반시계 : -1
int v_num, direction;

//점수 
int point=0;



//회전 부분
void rotate(int i, int direction) {
	//시계방향
	v v_tmp(8);
	v_tmp = v_array[i];
	int tmp = v_tmp[0];
	if (direction > 0) {
		v_tmp[0] = v_tmp[7];
		v_tmp[7] = v_tmp[6];
		v_tmp[6] = v_tmp[5];
		v_tmp[5] = v_tmp[4];
		v_tmp[4] = v_tmp[3];
		v_tmp[3] = v_tmp[2];
		v_tmp[2] = v_tmp[1];
		v_tmp[1] = tmp;
		v_array[i] = v_tmp;
	}
	//반시계방향
	else {
		v_tmp[0] = v_tmp[1];
		v_tmp[1] = v_tmp[2];
		v_tmp[2] = v_tmp[3];
		v_tmp[3] = v_tmp[4];
		v_tmp[4] = v_tmp[5];
		v_tmp[5] = v_tmp[6];
		v_tmp[6] = v_tmp[7];
		v_tmp[7] = tmp;
		v_array[i] = v_tmp;
	}
}

void leftCompV(int i) {
	if (i == 0) return;
	//cout << v_array[i][6] << ", " << v_array[i - 1][2] << "\n";
	if (v_array[i][6] != v_array[i - 1][2]) {
		direction = -direction;
		leftCompV(i - 1);
		rotate(i-1, direction);
		direction = -direction;
	}
}
void rightCompV(int i) {
	if (i == 3) return;
	if (v_array[i][2] != v_array[i+1][6]) {
		direction = -direction;
		rightCompV(i + 1);
		rotate(i+1, direction);
		direction = -direction;
	}
}

//문제 해결 부분
void solve(int v_num) {
	leftCompV(v_num);
	rightCompV(v_num);
	rotate(v_num, direction);
}


//상태를 입력받는 함수
void makeV(int k) {
	v v_tmp(8);
	for (int i = 0; i < 8; i++) {
		cin >> v_tmp[i];
	}
	v_array[k]=v_tmp;
}

void Point() {
	if (v_array[0][0]=='1') point += 1;
	if (v_array[1][0]=='1') point += 2;
	if (v_array[2][0]=='1') point += 4;
	if (v_array[3][0]=='1') point += 8;
}

int main() {
	makeV(0);
	makeV(1);
	makeV(2);
	makeV(3);
	cin >> rot_num;
	for (int i = 0; i < rot_num; i++) {
		cin >> v_num >> direction;

		solve(v_num-1);
	}
	Point();
	cout << point << "\n";
	return 0;
}


/*
10101111
01111101
11001110
00000010
*/