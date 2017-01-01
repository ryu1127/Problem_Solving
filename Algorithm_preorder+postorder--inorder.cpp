#include<stdio.h>
#include <vector>

using namespace std;

static vector<int> LVR;		//��ü ���ϰ��� �ϴ� ���� ������ ���������� ����

vector<int> VLR_input(vector<int> VLR, int node_num);
void Print_Order(vector<int> something);
void Make_LVR(vector<int> VLR, vector<int> LRV, int node_num);
vector<int> LRV_input(vector<int> LRV, int node_num);

int main() {
	//���� ����
	int node_num = 0;		//����� ���� 1~1000��
	vector<int> VLR_temp;
	vector<int> LRV_temp;
	

	//����� ���� �Է�
	//printf("����� ������ �Է��ϼ��� : ");
	scanf("%d", &node_num);

	if (node_num < 1 && node_num>1000) {
		printf("������ ������ϴ�.\n");
		return 0;
	}
	printf("\n\n");
	
	//���� ��ȸ�� ��� �Է�
	vector<int> VLR(VLR_input(VLR_temp, node_num));

	//���� ��ȸ�� ��� �Է�
	vector<int> LRV(LRV_input(LRV_temp, node_num));

	//���� ��ȸ ��� ���
	Make_LVR(VLR, LRV, node_num);

	//printf("���� ��ȸ �Է°� : ");
	//Print_Order(VLR);
	//printf("���� ��ȸ �Է°� : ");
	//Print_Order(LRV);
	//printf("���� ��ȸ ��ȯ �� ��� �� : ");

	Print_Order(LVR);
	return 0;
}


//���� ��ȸ ��� �Է� �Լ�
vector<int> VLR_input(vector<int> VLR, int node_num) {
	//printf("���� ��ȸ ����� �Է��ϼ��� : ");
	for (int i = 0; i < node_num; i++) {
		int temp = 0;
		scanf("%d", &temp);
		VLR.push_back(temp);
		//printf("%d VLR�� �Է� �Ϸ� \n", temp);
	}
	printf("\n\n");
	return VLR;
}

//��ȸ �Լ��� ���� ��� ���ִ� �Լ� 
void Print_Order(vector<int> something) {
	for (int i = 0; i < something.size(); i++) {
		printf("  %d",something[i]);
	}
	printf("\n");
}

//���� ��ȸ ��� �Է� �Լ�
vector<int> LRV_input(vector<int> LRV, int node_num) {
	//printf("���� ��ȸ ����� �Է��ϼ��� : ");
	for (int i = 0; i < node_num; i++) {
		int temp = 0;
		scanf("%d", &temp);
		LRV.push_back(temp);
		//printf("%d LRV�� �Է� �Ϸ�", temp);
	}
	printf("\n\n");
	return LRV;
}

//���� ������ ���� ���� ��ȸ ����� ��� �Լ�
void Make_LVR(vector<int> VLR, vector<int> LRV, int node_num) {
	if (VLR.size() == 0) return;
	int root = VLR[0]; //��Ʈ ����
	int LRV_left_index = 0;	//���� �ڽ��� �ε�����
	int LRV_left_num = 0;	//���� �ڽ��� ����

	//���� �ڽ��� �ε��� ���� ���� ������ �ڽĵ� ǥ�� �� �� �����Ƿ� ���� �������� ����.

	vector<int> LRV_temp_left;			//���� LRV���� �������� ���� �ڽİ� ������ �ڽ�
	vector<int> LRV_temp_right;
	vector<int> VLR_temp_left;			//���� VLR���� �������� ���� �ڽİ� ������ �ڽ�
	vector<int> VLR_temp_right;

	if (node_num == 1) {				//node_num�� 1�̶�� ���� �������� �ڽ��� �ϳ����̹Ƿ� �����ϰ� �����Ѵ�.
		LVR.push_back(VLR[0]);
		return;
	}

	for (int i = 0; i < node_num; i++) {
		if (VLR[1] == LRV[i]) {
			LRV_left_index = i;				//���� �ڽ��� ��ġ�� �ε�����
			LRV_left_num = i + 1;			//���� �ڽ��� ����

			//������ �ε������� ���� ���� �ڽİ� ������ �ڽ��� ������ �����Ͽ� 
			for (int j = 0; j < i + 1; j++) LRV_temp_left.push_back(LRV[j]);
			for (int j = i + 1; j < node_num-1; j++) LRV_temp_right.push_back(LRV[j]);
			for (int j = 1; j < i + 2; j++) VLR_temp_left.push_back(VLR[j]);
			for (int j = i + 2; j < node_num; j++) VLR_temp_right.push_back(VLR[j]);

			//�� �ڽĵ鿡 ���Ͽ� �ٽ� ��������� ȣ���Ͽ� �ɰ��� ������. ���� ��ȯ ��� �̿�
			//���� LVR�̹Ƿ� ����Լ��� ȣ�� ���� LVR������ �ϸ� �ȴ�.
			Make_LVR(VLR_temp_left, LRV_temp_left, i+1);
			LVR.push_back(root);
			Make_LVR(VLR_temp_right, LRV_temp_right, node_num - 2 - i);
		}
		
	}
}