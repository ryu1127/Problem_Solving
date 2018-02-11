#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

struct Score {
	string name;
	int kor;
	int eng;
	int math;
};

bool cmp(const Score &u, const Score &v) {
	if (u.kor > v.kor) return true;
	else if (u.kor == v.kor) {
		if (u.eng < v.eng) return true;
		else if (u.eng == v.eng) {
			if (u.math > v.math) return true;
			else if (u.math == v.math) {
				if (u.name < v.name) return true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<Score> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i].name >> s[i].kor >> s[i].eng >> s[i].math;
	}
	sort(s.begin(), s.end(), cmp);
	for (int i = 0; i < n; i++) {
		cout << s[i].name << "\n";
	}
	return 0;
	

}