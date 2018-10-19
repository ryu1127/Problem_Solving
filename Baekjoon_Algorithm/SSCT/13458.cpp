#include<iostream>
#include<vector>

#define sync() {ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);}

using namespace std;

//������ ����
int n;
//�����ڼ� n��
vector <long long> A;

//�Ѱ������� �� �� �ִ� �� B, �ΰ������� ���� �ִ� �� C
int B, C;

//�Ѱ����� �� , �ΰ����� ��
long long numB = 0, numC = 0;

void input() {
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		A.push_back(tmp);
	}
	cin >> B >> C;
}

void solve() {
	//�Ѱ������� �ϴ� �Ѹ� ����.
	for (int i = 0; i < n; i++) {
		A[i] = A[i] - B;
		numB++;
	}
	for (int i = 0; i < n; i++) {
		//�ΰ����� �ʿ�
		if (A[i] > 0) {
			numC += A[i] / C;
			if ((A[i] % C) != 0) numC++;
		}
	}
	cout << numC + numB << endl;
}


int main() {
	sync();
	input();
	solve();
	return 0;
}