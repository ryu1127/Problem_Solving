#include<stdio.h>

int N,i;
int j;
char str[10001][21];

typedef struct _node{
    struct _node * next[26];
    int cnt;
    int isEnd;
}NODE;
NODE* root;

int toNumber(char al){
    return (int)(al-'a');
}
int Trie_Insert(char al){
    NODE* parent = root;
    //노드가 없는 경우 새로 만들어준다
    if(parent->next[toNumber(al)]==(NODE*)0){
        NODE*
    }
}

int main(){

    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%s",str[i]);
        for(j=0;str[i][j];j++){
            Trie_Insert(str[i][j]);
        }
    }
    return 0;
}