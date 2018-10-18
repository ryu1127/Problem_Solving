#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


//n : N*N 도시 , m : 최대 치킨집 수 
int n, m;

typedef vector<int> v;
typedef vector<v> map;
typedef vector<int> distance;
struct loc {
	int x;
	int y;
};
typedef vector<loc> chicken;
typedef vector<loc> home;

chicken ch;
home hm;
loc tmp;

int chickenCount=0;
int house = 0;
int idx = 0;
int dis = 9999999999;
int d = 0;
int total=0;
int ans = 9999999999;

map space;

string Chicken = "";

void input() {
	cin >> n >> m;

	space = map(n, v(n));
	//치킨 , 집 좌표 저장

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> space[i][j];
			if (space[i][j] == 2) {
				chickenCount++;
				tmp.x = i; tmp.y = j;
				ch.push_back(tmp);
			}
			if (space[i][j] == 1) {
				tmp.x = i; tmp.y = j;
				hm.push_back(tmp);
				house++;
			}
		}
	}
}


int dfs(int idx, string Chicken) {
	//ans = 9999999999;
	total = 0;
	int count = 0;

	if (idx == chickenCount) {
		for (int i = 0; i < Chicken.length(); i++) {
			if (Chicken[i] == '1')count++;
			if (count > m) {
				count = 0;
				return 999999;
			}
		}
		if (count == 0) return 9876543;
		count = 0;

		for (int i = 0; i < house; i++) {
			dis = 999999999;
			for (int j = 0; j < Chicken.length(); j++) {
				if (Chicken[j] == '1') {
					d = abs(ch[j].x - hm[i].x) + abs(ch[j].y - hm[i].y);
					dis = min(dis, d);
				}
			} total += dis;
		}if(total>0) ans = min(ans, total);
		return ans;
		
	}
	return min( dfs(idx + 1, Chicken + '0'),dfs(idx + 1, Chicken + '1') );
}






int main() {
	input();
	cout << dfs(0, "");
	return 0;
}