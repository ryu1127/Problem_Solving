#include<iostream>
#include<vector>
#include<string>
//#include<cstdio>
#include<algorithm>
#define sync() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}


using namespace std;


typedef vector<int> line;
typedef vector<line> score;
string T="";
score point;



// 전체 인원
int n;


//int minD(int a, int b) {
//	if (a < b) return a;
//	else return b;
//}

void input() {
	cin >> n;

	point = score(n, line(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> point[i][j];
		}
	}
}

int dfs(int idx, string T) {
	//최종 완성
	if (idx == n) {
		int start = 0, link = 0;
		for (int i = 0; i < T.length(); i++) {
			for (int j = 0; j < T.length(); j++) {
				if (T[i] == '1') {
					if (T[j] == '1') start += point[i][j];
				}
				else {
					if (T[j] == '0') link += point[i][j];
				}
			}
		}
		return start > link ? start - link : link - start;
	}
	//아니면 DFS로 깊게 들어간다.
	return min(dfs(idx + 1, T+"1"), dfs(idx + 1, T+"0"));
}





int main() {
	sync();
	input();
	printf("%d",dfs(0, ""));
	return 0;

}