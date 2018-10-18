#include<iostream>
#include<vector>

using namespace std;

//������ ũ�� (2���� 100)
int n;

//����� ���� (0���� 100)
int k;

//���� ���� ��ȯ ȸ��
int l;

//���� �Ӹ� ��ġ
int x = 0, y = 0, lenght = 1;
int nx=1, ny=1;
int second=0;

enum {EAST=1, SOUTH, WEST, NORTH};
//���� ���� �������
int direction = EAST;

int dy[5] = { 0,1,0,-1,0 };
int dx[5] = { 0,0,1,0,-1 };

struct mov_snake {
	int second;
	char direction;
};

//�ð��� ��ȭ ���� ����
vector<mov_snake> moving;
vector<pair<int, int>> snake;
int count;

typedef vector<int> v;
typedef vector<v> vv;
vv space;
int vi=0;
void mov() {
	while (1) {
		if (vi<l) {
			if (second == moving[vi].second) {
				if (moving[vi].direction == 'L') {
					if (direction == EAST) direction = NORTH;
					else direction--;
				}
				else {
					if (direction == NORTH) direction = EAST;
					else direction++;
				}
				vi++;
			}
		}

		nx = x + dx[direction];
		ny = y + dy[direction];
		if (nx > n || ny > n || nx <= 0 || ny <= 0) {
			second++;
			break;
		}
		if (space[nx][ny] == 1) {
			second++;
			break;
		}
		else if (space[nx][ny] == 0) {
			space[snake[0].first][snake[0].second] = 0;
			snake.erase(snake.begin());
		}
		x = nx;
		y = ny;
		space[x][y] = 1;
		snake.push_back(make_pair(x, y)); 
		second++;
	}
	cout << second;

}


void solve() {
	cin >> n >> k;
	space = vv(n+1, v(n+1));


	//initialize map
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			space[i][j] = 0;
		}
	}
	//��� �ִ� ���� 2�� ǥ��
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		space[x][y] = 2;
	}

	//������ ����
	cin >> l;
	mov_snake tmp;
	for (int i = 0; i < l; i++) {
		cin >> tmp.second >> tmp.direction;
		moving.push_back(tmp);
	}

	space[1][1] = 1;
	snake.push_back(make_pair(1, 1));
}

int main() {
	solve();
	x = 1; y = 1;
	mov();
}