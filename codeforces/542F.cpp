#include <bits/stdc++.h>
using namespace std;
int n,T;
vector<int> q[101];
queue<int> c[101];
int bst(int d) {
  if (d>=T) return 0;
  if (c[d].size()) {
    int res=c[d].front();
    c[d].pop();
    return res;
  }
  int r1=bst(d+1),r2=r1==0?0:bst(d+1);
  int res=r1+r2;
  int t=T-d;
  if (q[t].size()&&q[t].back()>res) {
    if (r1) c[d+1].push(r1);
    if (r2) c[d+1].push(r2);
    res=q[t].back();
    q[t].pop_back();
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>T;
  for (int i=0;i<n;i++){int t,tq;cin>>t>>tq;q[t].push_back(tq);}
  for (int i=1;i<=T;i++) {
    sort(q[i].begin(),q[i].end());
  }
  cout<<bst(0)<<'\n';
}
