#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector< pair<int,int> > coins;

    coins.push_back(make_pair(1,8)); coins.push_back(make_pair(2,4));
    coins.push_back(make_pair(3,2)); coins.push_back(make_pair(3,7));
    coins.push_back(make_pair(5,3)); coins.push_back(make_pair(5,5));
    coins.push_back(make_pair(7,4)); coins.push_back(make_pair(7,7));
    coins.push_back(make_pair(8,7)); 

    int m[9][9];
    int D[9][9];

    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        //initialize all D,m to 0
            D[i][j] = m[i][j] = 0;
    
    for(auto c: coins)
        m[c.first][c.second] = 1;

    for(int i=1;i<9;i++)
        for(int j=1; j<9;j++)
            D[i][j] = max(D[i-1][j],D[i][j-1])+m[i][j];

    cout << D[8][8] << endl;
}