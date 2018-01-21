#include<stdio.h>
#include<string>

using namespace std;

int main(){

	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);

	string s1,s2;
	s1 = to_string(a) + to_string(b);
	s2 = to_string(c) + to_string(d);
	long long l1,l2;
	l1 = stoll(s1);
	l2 = stoll(s2);
	long long result;
	result = l1 + l2;
	//signed long long을 출력하고 싶을땐 %lld를 이용해야 한다.
	printf("%lld",result);

	return 0;


}