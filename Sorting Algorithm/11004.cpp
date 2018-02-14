#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
  int n,k;
  scanf("%d%d",&n,&k);
  vector<int> v;
  for(int i=0;i<n;i++){
    int temp;
    scanf("%d",&temp);
    v.push_back(temp);
  }
  // for(int i=0;i<n;i++){
  //   printf("%d ",v[i]);
  // }
  sort(v.begin(),v.end());
  printf("%d\n",v[k-1]);
  return 0;
}
