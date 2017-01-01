#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	int pb = 0;
	scanf("%d", &pb);
	if (pb == 0) return 0;

	vector<string> s;
	string temp;

	cin.ignore(1);

	for (int i = 0; i < pb; i++) {
		getline(cin, temp);
		s.push_back(temp);
	}
	vector<int> sc;
	int score = 0;
	int count = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		for (unsigned int j = 0; j < s[i].size(); j++) {
			if (s[i][j] == 'O') {
				count += 1;
				score += count;
			}
			else {
				count = 0;
			}
		}
		sc.push_back(score);
		score = 0;
		count = 0;
	}
	for (int i = 0; i < pb; i++) {
		printf("%d\n", sc[i]);
	}
	return 0;
}