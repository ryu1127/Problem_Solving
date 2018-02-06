#include<cstdio>
#include<queue>
#include<string.h>

int main() {

	int n;
	scanf("%d", &n);
	int queue[10000] = {0};

	int val;
	int front = 0;
	int end = 0;

	while (n--) {
		char str[100] = {};
		scanf("%s", str);
		
		if (!strcmp(str,"push")) {
			scanf("%d", &val);
			queue[end] = val;
			end++;

			//when queue is full
			//if (end == 1000) {
			//	int temp[1000] = {0};
			//	int temp_size=0;
			//	for (int i = 0; i < end - front; i++) {
			//		temp[i] = queue[front++];
			//		temp_size++;
			//	}
			//	queue[1000] = { 0 };
			//	front = 0;
			//	end = 0;
			//	for (int i = 0; i < temp_size; i++) {
			//		queue[i] = temp[i];
			//		end++;
			//	}
			//}
		}
		else if (!strcmp(str, "pop")) {
			//queue is empty
			if (front == end) {
				printf("-1\n");
			}
			
			else {
				printf("%d\n", queue[front]);
				queue[front] = 0;
				front++;
			}
		}
		else if (!strcmp(str, "size")) {
			printf("%d\n", end - front);
		}
		else if (!strcmp(str, "empty")) {
			if (end == front) printf("1\n");
			else printf("0\n");
		}
		else if (!strcmp(str, "front")) {
			if (end == front) printf("-1\n");
			else printf("%d\n", queue[front]);
		}
		else if (!strcmp(str, "back")) {
			if (end == front) printf("-1\n");
			else printf("%d\n", queue[end - 1]);
		}
	}
	return 0;
}