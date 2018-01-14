#include<stdio.h>
#include<stack>
#include<string>
#include<vector>

using namespace std;

int main() {



	int number;
	scanf("%d", &number);

	//전체 케이스 반복
	while (number--) {

		vector<int> vs;
		char temp[1];
		int check = 1;
		scanf("%c", &temp);
		//엔터 입력시까지 반복
		while (1) {
			check = 1;
			if (temp=="\n") break;
			else if (temp=="(") vs.push_back(-1);
			else if (temp, ")") {
				if (vs.empty == true) {
					check = 0;
					break;
				}
				else if (vs.back == -1) vs.pop_back;
				else {
					check = 0;
					break;
				}
			}
		}
		if (check == 1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}