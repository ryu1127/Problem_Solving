#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

//n줄 m칸
int n, m;
typedef vector<int> vi;
typedef vector<vi> vvi;
//최대로 얻을 수 있는 동전 개수를 저장한 2차원 배열
vvi max_coin;
//동전이 저장 된 2차원 배열
vvi coin;

int result = 0;

void input()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> coin[i][j];
        }
    }
}
void init()
{
    coin = vvi(n + 1, vi(m + 1));
    max_coin = vvi(n + 1, vi(m + 1, 0));
    max_coin[1][1] = coin[1][1];
    if(n!=1 && m != 1){
        max_coin[2][1] = max_coin[1][1] + coin[2][1];
        max_coin[1][2] = max_coin[1][1] + coin[1][2];
    }
}
int findMax(int i, int j)
{
    //범위가 벗어나면 올 수 없는 곳이므로 0을 return
    if (i < 1 || j < 1)
        return 0;
    //저장된 최대 값이 있다면 그것을 불러오기
    if (max_coin[i][j] != 0)
        return max_coin[i][j];
    //현재 자리까지 최대 동전 = 현재 자리 동전 + 위와 왼쪽 중 더 많은 동전을 얻을 수 있는 것을 선택
    max_coin[i][j] = coin[i][j] + max(findMax(i - 1, j), findMax(i, j - 1));
    //최종적인 n,m을 찾았으면 return 
    return max_coin[i][j];
}
void solve()
{
    result = findMax(n, m);
}
void printResult()
{
    cout << result;
}

int main()
{
    cin >> n >> m;
    init();
    input();
    solve();
    printResult();

    return 0;
}