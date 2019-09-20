#include<stdio.h>
int T,t;
int N,n;
char str[10001];

typedef struct _node {
	int isEnd;
	int cnt;
	struct _node * next[10];
}NODE;

NODE root;
void Init_Root(void)
{
	int i;
	root.isEnd = 0;
	for (i = 0; i < 10; i++) root.next[i] = (NODE*)0;
}

int Trie_Insert(NODE* root, char* str) {
	int i;
	NODE* parent = root;
	for (i = 0; str[i]; i++)
	{
		//여기서 끝나는것이 있는 경우
		if (parent->next[(int)str[i]-'0'] == (NODE*)0)
		{
			parent->next[(int)str[i]- '0'] = calloc(1, sizeof(NODE));
			if (parent->next[(int)str[i]- '0'] == (NODE*)0) return 0;
		}
		if (parent->next[(int)str[i] - '0']->isEnd == 1) return -1;
		parent->next[(int)str[i] - '0']->cnt++;
		parent = parent->next[(int)str[i]- '0'];
		if (parent->isEnd) return -1;
		
	}
	parent->isEnd = 1;
	if (parent->cnt > 1) return -1;
	return 1;
}



int main(void) {
	int flag = 0;
	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		Init_Root();
		scanf("%d", &N);
		for (n = 0; n < N; n++) {
			scanf("%s", str);
			if (Trie_Insert(&root, str) == -1) {
				flag = 1;
				break;
			}
		}
		if (flag) printf("NO\n");
		else printf("YES\n");
		flag = 0;
	}
}