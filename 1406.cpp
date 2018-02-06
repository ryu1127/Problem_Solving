#include<cstdio>
#include<vector>

using namespace std;

int main() {
	char str[600000] = {};
	int index=0;
	char choice;
	vector<char> left;
	vector<char> right;

	//input string
	while (1) {
		scanf("%c", &str[index]);
		if (str[index] == '\n') {
			str[index] = '\0';
			break;
		}
		else {
			left.push_back(str[index]);
			index++;
		}
	}

	int n;
	scanf("%d", &n);
	
	//main Program
	while (n--) {
		scanf("%c", &choice);
		scanf("%c", &choice);
		switch (choice) {
			case 'L':
				if (left.empty() == 0) {
					right.push_back(left.back());
					left.pop_back();
				}
				break;

			case 'D':
				if (right.empty() == 0) {
					left.push_back(right.back());
					right.pop_back();
				}
				break;

			case 'B':
				if (left.empty() == 0) {
					left.pop_back();
				}
				break;

			case 'P':
				char temp;
				scanf("%c", &temp);
				scanf("%c", &temp);
				left.push_back(temp);
				break;

			default:
				break;
		}

		
	}
	int left_size, right_size;
	left_size = left.size();
	right_size = right.size();
	for (int i = 0; i <left_size; i++) {
		printf("%c", left[i]);
	}
	for (int i = right_size-1; i >=0; i--) {
		printf("%c", right[i]);
	}
	return 0;
}
