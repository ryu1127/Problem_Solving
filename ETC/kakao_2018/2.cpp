#include<string>
#include<iostream>
#include<vector>

using namespace std;


vector<int> solution(int N, vector<int> stages){
    vector<int> answer;
    int a[501] = {0};
    int size = stages.size();
    for(int i=0;i<size;i++){
        a[stages[i]] += 1 ;
    }
    


    sort(answer.begin(),answer.end());
    
    
    
    
    return answer;
}

int main(){
    int n = 5;
    vector<int> stages;
    stages.push_back(3);
    stages.push_back(4);
    stages.push_back(2);
    stages.push_back(1);
    stages.push_back(5);

    solution(n,stages);
    return 0;
}

