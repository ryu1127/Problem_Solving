#include<stdio.h>
#include<string>
#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int main() {
	vector<int> v;
	string n;
	cin >> n;
	int start;
	int total = 0;
	int checkPoint = 0;
	start = n.length() % 3;
	for (int i = n.length() - 1; i >= start; i--) {
		total += (n[i]-48) * pow(2, checkPoint);
		if (checkPoint == 2) {
			checkPoint = 0;
			v.push_back(total);
			total = 0;
		}
		else checkPoint++;
	}
	for (int i = start - 1; i >= 0; i--) {
		total += (n[i] - 48) * pow(2, checkPoint);
		if (checkPoint == start-1) {
			checkPoint = 0;
			v.push_back(total);
			total = 0;
		}
		else checkPoint++;
	}
	int a = v.size();
	for (int i = 0; i < a; i++) {
		int temp = v.back();
		printf("%d", temp);
		v.pop_back();
	}
	return 0;
}
