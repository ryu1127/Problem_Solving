#include<stdio.h>
#define YES 1
#define NO 0

int T,i;

char str[81];

typedef struct _trie{
    int cnt;
    struct TRIE * next[26];
    int isEnd;
}TRIE;

TRIE * root;

void Init_Trie(TRIE* root){
    
}
void Clean_Trie(TRIE* root){
    if(root->isEnd == NO) {
        for(i=0;i<26;i++){
            if(root->next[i] != (TRIE*)0){
                Clean_Trie(root->next[i]);
            }
        }
    }
}

int toNumber(char ch){
    return ch-'a';
}

int main(){

}