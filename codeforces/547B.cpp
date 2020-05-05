// Use std::set::upper_bound on sets (O(log n)), not std::upper_bound (O(n log n))!
#include <bits/stdc++.h>
using namespace std;
int a[200000], m[200000], h[200000], h2[200000], rh[200000], mp[200000], pmp[200000], res[200001], idx[200000];
vector<int> ps[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  for (int i=0;i<n;i++)cin>>a[i], pmp[i]=a[i], idx[i]=i;
  sort(pmp, pmp+n);
  int nd=0;
  for (int i=0;i<n;) {
    mp[nd]=pmp[i];
    while (i<n&&mp[nd]==pmp[i])i++;
    nd++;
  }
  for (int i=0;i<n;i++) {
    m[i]=lower_bound(mp,mp+nd,a[i])-mp;
    ps[m[i]].push_back(i);
  }
  set<int> pv;
  for (int i=0;i<nd;i++) {
    for (int p:ps[i]) {
      if (pv.empty()) {
        h[p]=n-p;
      } else {
        auto u=pv.upper_bound(p);
        if (u==pv.end()) h[p]=n-p;
        else h[p]=*u-p;
      }
    }
    for (int p:ps[i])pv.insert(p);
  }
  set<int> pv2;
  for (int i=0;i<nd;i++) {
    for (int p:ps[i]) {
      if (pv2.empty()) {
        h2[p]=p;
      } else {
        auto u=pv2.upper_bound(p);
        if (u==pv2.begin()) h2[p]=p;
        else h2[p]=p-*--u-1;
      }
    }
    for (int p:ps[i])pv2.insert(p);
  }
  for (int i=0;i<n;i++){
    rh[i]=h[i]+h2[i];
  }
  sort(idx, idx+n, [&](int a, int b){return rh[a]>rh[b];});
  for (int i=n,j=0;i>0;i--){
    res[i]=(i<n?res[i+1]:0);
    while (j<n&&rh[idx[j]]>=i)res[i]=max(res[i], a[idx[j++]]);
  }
  for (int i=1;i<=n;i++){
    cout<<res[i]<<(i==n?'\n':' ');
  }
}
