#include <bits/stdc++.h>
using namespace std;
int k[200000], tk=0, cd[200000], n, m, il[200000];
vector<int> sd[200000];
bool ok(int a) {
  if (a<tk)return false;
  int nsk=0;
  for (int t=0;t<n;t++) {
    il[t]=t;
    if (sd[t].empty()) cd[t]=-1,nsk++;
    else {
      auto it=upper_bound(sd[t].begin(),sd[t].end(),a);
      if (it==sd[t].begin())cd[t]=-1,nsk++;
      else cd[t]=*--it;
    }
  }
  sort(il,il+n,[&](int x,int y){return cd[x]<cd[y];});
  int kb=0;
  for (int i=nsk;i<n;i++) {
    int j=il[i];
    int my=cd[j]-kb;
    int tb=min(my,k[j]);
    kb+=tb;
  }
  int l=tk-kb;
  return 2*l<=a-kb;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m;
  for (int i=0;i<n;i++)cin>>k[i],tk+=k[i];
  for (int i=0;i<m;i++){
    int d,t;
    cin>>d>>t;
    sd[t-1].push_back(d);
  }
  for (int i=0;i<n;i++)sort(sd[i].begin(),sd[i].end());
  int l=tk,r=2*tk;
  while (l<=r){
    int m=(l+r)/2;
    if (ok(m)){
      r=m-1;
    } else {
      l=m+1;
    }
  }
  int v=ok(r-1)?r-1:ok(r)?r:l;
  cout<<v<<'\n';
}
