#include<iostream>
#include<vector>
#define sync(){ ios_base::sync_with_stdio(falase),cin.tie(NULL), cout.tie(NULL);}

using namespace std;

typedef vector<char> v;
typedef vector<v> vv;
//1,2,3,4��Ϲ����� ����
v v1(8), v2(8), v3(8), v4(8);
vv v_array(4);
//N�� 0, S�� 1

//ȸ�� Ƚ��
int rot_num;

//�ð� : 1, �ݽð� : -1
int v_num, direction;

//���� 
int point=0;



//ȸ�� �κ�
void rotate(int i, int direction) {
	//�ð����
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
	//�ݽð����
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

//���� �ذ� �κ�
void solve(int v_num) {
	leftCompV(v_num);
	rightCompV(v_num);
	rotate(v_num, direction);
}


//���¸� �Է¹޴� �Լ�
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