#include <bits/stdc++.h>
using namespace std;
int n, k, a, m;
set<int> ss;
int nv(int sz) {
  return (sz+1)/(a+1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>k>>a>>m;
  ss.insert(0);
  ss.insert(n+1);
  int nf=nv(n);
  if (nf<k) return cout<<"0\n",0;
  for (int i=1;i<=m;i++){
    int x;
    cin>>x;
    auto it=ss.upper_bound(x);
    int r=*it,l=*--it;
    ss.insert(x);
    nf-=nv(r-l-1);
    nf+=nv(x-l-1);
    nf+=nv(r-x-1);
    if (nf<k) return cout<<i<<'\n',0;
  }
  cout<<"-1\n";
}
