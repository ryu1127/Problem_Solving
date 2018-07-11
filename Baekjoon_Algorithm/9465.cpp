#include<stdio.h>
#include<algorithm>

using namespace std;


int d[100001][3] = {0};
int p[2][100001] = {0};

int n;

int check = 0;

int inputPoint();
int cal(int i);


int main(){

	int testCase;
	scanf("%d",&testCase);

	while(testCase--){
		inputPoint();
		d[0][0] = 0;
		d[0][1] = p[0][0];
		d[0][2] = p[1][0];
		for(int i=1;i<=n;i++){
			cal(i);
			// printf("cal success!!\n");
		}
		int result ;
		result = max(d[n-1][0],max(d[n-1][1],d[n-1][2]));
		printf("%d\n",result);
	}

	return 0;
}

int inputPoint(){
	
	scanf("%d",&n);
	for(int i=0;i<2;i++){
		for(int j=0;j<n;j++){
			int temp;
			scanf("%d",&temp);
			p[i][j] = temp;
			// printf("p[%d][%d] : %d\n",i,j,p[i][j]);
		}
	}
	return 0;
}


int cal(int i){

	d[i][0] = max(d[i-1][1],d[i-1][2]);
	d[i][1] = max(d[i-1][0],d[i-1][2])+p[0][i];
	d[i][2] = max(d[i-1][0],d[i-1][1])+p[1][i];
	// printf("d[%d] : %d %d %d \n",i,d[i][0],d[i][1],d[i][2]);
	return 0;
}