#include<cstdio>
#include<deque>
#include<string.h>

using namespace std;

deque<int> d;

void makeDeque();

int main(){
	int n;
	scanf("%d",&n);

	while(n--){
		makeDeque();
	}
	return 0;
}

void makeDeque(){
	char command[30]={'\0'};
	scanf("%s",command);
	if(!strcmp(command,"push_back")){
		int temp;
		scanf("%d",&temp);
		d.push_back(temp);
	}
	else if(!strcmp(command,"push_front")){
		int temp;
		scanf("%d",&temp);
		d.push_front(temp);
	}
	else if(!strcmp(command,"pop_front")){
		if(d.empty()==0){
			printf("%d\n",d.front());
			d.pop_front();
		}
		else printf("-1\n");
	}
	else if(!strcmp(command,"pop_back")){
		if(d.empty()==0){
			printf("%d\n",d.back());
			d.pop_back();
		}
		else printf("-1\n");
	}
	else if(!strcmp(command,"size")){
		int n;
		n = d.size();
		printf("%d\n",n);
	}
	else if(!strcmp(command,"empty")){
		printf("%d\n",d.empty());
	}
	else if(!strcmp(command,"front")){
		if(d.empty()==0) printf("%d\n",d.front());
		else printf("-1\n");
	}
	else if(!strcmp(command,"back")){
		if(d.empty()==0) printf("%d\n",d.back());
		else printf("-1\n");
	}
}