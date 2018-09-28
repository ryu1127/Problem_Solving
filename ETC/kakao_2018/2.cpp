#include<string>
#include<iostream>
#include<vector>

using namespace std;


vector<int> solution(int N, vector<int> stages){
    vector<int> answer(stages);
    cout << answer.size() << endl;
    
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

