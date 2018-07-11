#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;
string n;

int main() {
	int checkFirst = 0;
	int number;
	cin >> n;
	int index;
	int size = n.size();
	index = 0;
	while (index<size) {
		number = n[index] - 48;
		if (number - 4 >= 0) {
			number -= 4;
			printf("%d", 1);
			checkFirst = 1;
		}
		else {
			if (checkFirst == 1) {
				printf("%d", 0);
			}
		}
		if (number - 2 >= 0) {
			number -= 2;
			printf("%d", 1);
			checkFirst = 1;
		}
		else {
			if (checkFirst == 1) {
				printf("%d", 0);
			}
		}
		printf("%d", number);
		checkFirst = 1;
		index++;
	}
	return 0;
	
}