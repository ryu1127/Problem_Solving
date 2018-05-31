#include<cstdio>
#include<vector>
#include<algorithm>


using namespace std;

int main(){

  int n;
  int sum = 0;
  vector<int> p;

  scanf("%d",&n);
  int temp;
  for(int i=0;i<n;i++){
    scanf("%d",&temp);
    p.push_back(temp);
  }
  sort(p.begin(),p.end());

  //set size of vector
  int size = p.size();

  //calculate sum for result
  for(int i=1;i<=n;i++){
    sum += p[size-i]*i;
    sum = sum % 1000000009;
  }

  //print
  printf("%d",sum);

}
