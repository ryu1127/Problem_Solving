#include<stdio.h>
#include <vector>

using namespace std;

static vector<int> LVR;		//전체 구하고자 하는 중위 순위를 전역변수로 지정

vector<int> VLR_input(vector<int> VLR, int node_num);
void Print_Order(vector<int> something);
void Make_LVR(vector<int> VLR, vector<int> LRV, int node_num);
vector<int> LRV_input(vector<int> LRV, int node_num);

int main() {
	//변수 지정
	int node_num = 0;		//노드의 개수 1~1000개
	vector<int> VLR_temp;
	vector<int> LRV_temp;
	

	//노드의 개수 입력
	//printf("노드의 개수를 입력하세요 : ");
	scanf("%d", &node_num);

	if (node_num < 1 && node_num>1000) {
		printf("범위를 벗어났습니다.\n");
		return 0;
	}
	printf("\n\n");
	
	//전위 순회한 결과 입력
	vector<int> VLR(VLR_input(VLR_temp, node_num));

	//후위 순회한 결과 입력
	vector<int> LRV(LRV_input(LRV_temp, node_num));

	//중위 순회 결과 출력
	Make_LVR(VLR, LRV, node_num);

	//printf("전위 순회 입력값 : ");
	//Print_Order(VLR);
	//printf("후위 순회 입력값 : ");
	//Print_Order(LRV);
	//printf("중위 순회 변환 후 출력 값 : ");

	Print_Order(LVR);
	return 0;
}


//전위 순회 결과 입력 함수
vector<int> VLR_input(vector<int> VLR, int node_num) {
	//printf("전위 순회 결과를 입력하세요 : ");
	for (int i = 0; i < node_num; i++) {
		int temp = 0;
		scanf("%d", &temp);
		VLR.push_back(temp);
		//printf("%d VLR에 입력 완료 \n", temp);
	}
	printf("\n\n");
	return VLR;
}

//순회 함수에 대해 출력 해주는 함수 
void Print_Order(vector<int> something) {
	for (int i = 0; i < something.size(); i++) {
		printf("  %d",something[i]);
	}
	printf("\n");
}

//후위 순회 결과 입력 함수
vector<int> LRV_input(vector<int> LRV, int node_num) {
	//printf("후위 순회 결과를 입력하세요 : ");
	for (int i = 0; i < node_num; i++) {
		int temp = 0;
		scanf("%d", &temp);
		LRV.push_back(temp);
		//printf("%d LRV에 입력 완료", temp);
	}
	printf("\n\n");
	return LRV;
}

//얻은 정보를 통해 중위 순회 결과를 얻는 함수
void Make_LVR(vector<int> VLR, vector<int> LRV, int node_num) {
	if (VLR.size() == 0) return;
	int root = VLR[0]; //루트 설정
	int LRV_left_index = 0;	//왼쪽 자식의 인덱스값
	int LRV_left_num = 0;	//왼쪽 자식의 노드수

	//왼쪽 자식의 인덱스 값을 통해 오른쪽 자식도 표현 할 수 있으므로 따로 정의하지 않음.

	vector<int> LRV_temp_left;			//기존 LRV에서 나누어진 왼쪽 자식과 오른쪽 자식
	vector<int> LRV_temp_right;
	vector<int> VLR_temp_left;			//기존 VLR에서 나누어진 왼쪽 자식과 오른쪽 자식
	vector<int> VLR_temp_right;

	if (node_num == 1) {				//node_num가 1이라는 것은 나누어진 자식이 하나뿐이므로 저장하고 리턴한다.
		LVR.push_back(VLR[0]);
		return;
	}

	for (int i = 0; i < node_num; i++) {
		if (VLR[1] == LRV[i]) {
			LRV_left_index = i;				//왼쪽 자식이 위치한 인덱스값
			LRV_left_num = i + 1;			//왼쪽 자식의 개수

			//지정된 인덱스값에 따라 왼쪽 자식과 오른쪽 자식을 나누어 저장하여 
			for (int j = 0; j < i + 1; j++) LRV_temp_left.push_back(LRV[j]);
			for (int j = i + 1; j < node_num-1; j++) LRV_temp_right.push_back(LRV[j]);
			for (int j = 1; j < i + 2; j++) VLR_temp_left.push_back(VLR[j]);
			for (int j = i + 2; j < node_num; j++) VLR_temp_right.push_back(VLR[j]);

			//그 자식들에 대하여 다시 재귀적으로 호출하여 쪼개어 나간다. 분할 상환 기법 이용
			//또한 LVR이므로 재귀함수의 호출 또한 LVR순서로 하면 된다.
			Make_LVR(VLR_temp_left, LRV_temp_left, i+1);
			LVR.push_back(root);
			Make_LVR(VLR_temp_right, LRV_temp_right, node_num - 2 - i);
		}
		
	}
}