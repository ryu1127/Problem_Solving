#include<cstdio>
#include<vector>

using namespace std;

int main(){
  int n,k;
  scanf("%d%d",&n,&k);
  int temp;
  vector<int> a;
  for(int i=0;i<n;i++){
    scanf("%d",&temp);
    a.push_back(temp);
  }
  int size = a.size()-1;
  int cnt = 0;

  while(1){
    if(size<0){
      break;
    }
    if(k==0){
      break;
    }
      if (k >= a[size]){
        k = k - a[size];
        cnt++;
      }else{
        size--;
      }
  }

  printf("%d",cnt);
  return 0;
}
