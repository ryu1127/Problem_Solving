#include <stdio.h>
int n, m, res = 1, chk[26];
char S[22][22];
int px[4] = { 1,-1,0,0 };
int py[4] = { 0,0,1,-1 };
void go(int x, int y, int k) {
	if (k > res) res = k;
	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = x + px[i]; ny = y + py[i];
		if (0 <= nx && nx<n && 0 <= ny && ny<m) {
			if (chk[S[nx][ny] - 'A'] == 0) {
				chk[S[nx][ny] - 'A'] = 1;
				go(nx, ny, k + 1);
				chk[S[nx][ny] - 'A'] = 0;
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", S[i]);
	chk[S[0][0] - 'A'] = 1;
	go(0, 0, 1);
	printf("%d", res);
	return 0;
}