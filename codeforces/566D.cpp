// 566D - Restructuring Company
// Time complexity: O((n + q) log n)
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int uf[300000], sz[300000];
struct rcomp : binary_function<pii,pii,bool> {
  bool operator() (const pii& x, const pii& y) const {
    return x.second < y.first;
  }
};
set<pii,rcomp> rset;
int find(int x) {
  while (uf[x]!=x)x=uf[x];
  return x;
}
void unite(int x, int y) {
  x=find(x);
  y=find(y);
  if (x==y)return;
  if (sz[x]<sz[y]) {
    swap(x,y);
  }
  uf[y]=x;
  sz[x]+=sz[y];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n, q;
  cin >> n >> q;
  for (int i=1;i<=n;i++)uf[i]=i,sz[i]=1;
  pii cp;
  for (int Q=0;Q<q;Q++) {
    int t,x,y;
    cin >> t >> x >> y;
    if (t==1) {
      if (x==y)continue;
      unite(x,y);
    } else if (t==2) {
      if (x==y)continue;
      int rl=x,rr=y;
      for (int i=x+1;i<=y;i++) {
        unite(x,i);
        cp.first=cp.second=i;
        auto r = rset.lower_bound(cp);
        if (r!=rset.end()&&r->first<=i&&i<=r->second) {
          rl=min(rl,r->first);
          rr=max(rr,r->second);
          i=r->second;
          rset.erase(r);
        }
      }
      rset.insert({rl,rr});
    } else {
      cout << (find(x)==find(y)?"YES":"NO") << "\n";
    }
  }
}
