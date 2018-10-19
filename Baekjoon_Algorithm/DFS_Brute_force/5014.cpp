#include<iostream>
#include<vector>
#include<queue>
#define mp make_pair



using namespace std;

//총 몇층인지
int Highest;
//목표 층
int Target;

//현재 층
int Now;

//위로 가는 버튼
int Up;

//아래로 가는 버튼
int Down;

typedef vector<bool> visit;
visit visited;
queue<pair<int, int>> q;

//경계값 체크
bool check_boundary(int position) {
	return (position > 0 && position <= Highest);
}

void input() {
	cin >> Highest >> Now >> Target >> Up >> Down;
	visited = visit(Highest + 1, false);
}
// 10 1 10 2 1
// 6


void solve() {
	q.push(mp(Now, 0));
	visited[Now] = true;
	while (!q.empty()) {
		int here = q.front().first;
		int btn_cnt = q.front().second;
		q.pop();

		//답을 찾은 경우 버튼 누른 횟수 출력하고 종료
		if (here == Target) {
			cout << btn_cnt;
			exit(0);
		}

		//다음 방문할 위치 선택
		int next = here + Up;
		//이동할 수 있는지 확인하고 체크한후 큐에 삽임
		if (check_boundary(next) && visited[next] == false) {
			q.push(mp(next, btn_cnt + 1));
			visited[next] = true;
		}
		//아래 버튼
		next = here - Down;
		if (check_boundary(next) && visited[next] == false) {
			q.push(mp(next, btn_cnt + 1));
			visited[next] = true;
		}
	}
}



int main() {
	input();
	solve();
	cout << "use the stairs\n";
	return 0;
}