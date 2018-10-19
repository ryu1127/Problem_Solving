#include<iostream>
#include<vector>
#include<queue>
#define mp make_pair



using namespace std;

//�� ��������
int Highest;
//��ǥ ��
int Target;

//���� ��
int Now;

//���� ���� ��ư
int Up;

//�Ʒ��� ���� ��ư
int Down;

typedef vector<bool> visit;
visit visited;
queue<pair<int, int>> q;

//��谪 üũ
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

		//���� ã�� ��� ��ư ���� Ƚ�� ����ϰ� ����
		if (here == Target) {
			cout << btn_cnt;
			exit(0);
		}

		//���� �湮�� ��ġ ����
		int next = here + Up;
		//�̵��� �� �ִ��� Ȯ���ϰ� üũ���� ť�� ����
		if (check_boundary(next) && visited[next] == false) {
			q.push(mp(next, btn_cnt + 1));
			visited[next] = true;
		}
		//�Ʒ� ��ư
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