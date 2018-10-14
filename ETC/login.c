#include<stdio.h>
#include<time.h>

// #include<windows.h>




int user_id[100001] = {0};
int user_pwd[100001] = {0};
int index = 1;

int admin_id = 56789;
int admin_pwd = 87654;




//ID 비밀 번호 비교 함수
int verify(int uid,int pwd){
    static int trial = 0;
    // 유저 아이디와 비밀번호가 일치 할 때 
    if(user_id == uid && user_pwd == pwd) return 0;
    else if(admin_id == uid && admin_pwd == pwd){

    }
    else {
        trial++;
        return trial;
    }
}

void wait1s(){
    //이 밑의 start에 해당 코드의 실행 시간이 저장
    clock_t start = clock();
    
            //start 시작 시간으로 부터 현재 clock()시간 까지의 차이를 
            //PER_SEC으로 나누면 몇초가 지났는지 계산
            //1초가 지나면 while문을 빠져나오면서 종료
    while((clock()-start)/CLOCKS_PER_SEC <= 0.5){;}
    //왠지 모르겠지만 윗줄에서 0.5를 1로 하면 2초마다 증가
    //컴퓨터에서 실행시켜보고 시간 맞는지 확인
    
}

int main(){
    int uid;
    int pwd;

    user_id[0]=123;
    user_pwd[0]=456;
    
    //overtime은 대기 시간을 2배씩 증가시키기 위한 변수
    int overtime;
    overtime = 1;
    int check;

    //걸리는 시간을 계산하여 저장할 변수
    int delayTime = 10;


    while(1){
        printf("사용자 ID : "); scanf("%d",&uid);
        printf("비밀번호 : "); scanf("%d",&pwd);

        //아이디 비밀번호 확인 함수 호출 및 check에 오류 횟수 리턴
        //오류가 없을 시 0을 리턴
        check = verify(uid,pwd);
        
        //입력에러가 없을 시 
        if(check==0) {
            printf("성공적으로 로그인 되었습니다.\n");
            break;
        }

        //입력 에러 발생시 
        else{
            //5회 오류 반복시마다 2배씩 시간 증가
            printf("사용자 ID 또는 비밀번호 오류 (%d회)\n",check);

            //overtime이 변화할 때를 조건으로 표시
            //변화할 시는 5회가 초과했을 때이므로 그때마다 딜레이 시간을 2배로 증가
            if(overtime != ((check-1)/5)+1) delayTime *= 2;
            // overtime에 처음 5회까진 1, 10회까진 2, 15회까진 3이 들어감 
            overtime = ((check-1)/5)+1;
            
            
            //보여줄 때 쓸 함수 
            printf("delayTime : %d\n",delayTime);

            // printf("overtime : %d\n",overtime);


            for(int i=0;i<delayTime;i++) {
                printf("second...\n");
                wait1s();
            }
        }
    }
    return 0;
}


int addUser(){
    
}

