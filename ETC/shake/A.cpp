#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct { int score, penalty;} point;

class less_point{
public:
  bool operator() (const point &p1, const point &p2){
    if(p1.score != p2.score) return p1.score > p2.score;
    return p1.penalty < p2.penalty;
  }
};

int main(){
    int n;
    int score;
    int penalty;
    scanf("%d",&n);

    vector<point> a;
    point s;
    for(int i=0;i<n;i++){
        scanf("%d%d",&score,&penalty);
        s.score = score;
        s.penalty = penalty;
        a.push_back(s);
    }
    sort(a.begin(),a.end(),less_point());
    int count = 0;
    for(int i=4;i<n;i++){
        if(a[4].score == a[i+1].score) count++;
        else break;
    }
    printf("%d",count);
    return 0;


}

