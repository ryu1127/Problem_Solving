#include<iostream>
#include<vector>

#define sync() {ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);}

using namespace std;

//시험장 개수
int n;
//응시자수 n개
vector <long long> A;

//총감독관이 볼 수 있는 수 B, 부감독관이 볼수 있는 수 C
int B, C;

//총감독관 수 , 부감독관 수
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
	//총감독관은 일단 한명씩 들어간다.
	for (int i = 0; i < n; i++) {
		A[i] = A[i] - B;
		numB++;
	}
	for (int i = 0; i < n; i++) {
		//부감독관 필요
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