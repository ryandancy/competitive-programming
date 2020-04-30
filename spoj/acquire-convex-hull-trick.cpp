// ACQUIRE - land acquisition. Convex hull trick.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
pll ov[50000];
ll cst[50001];
vector<pll> lns; vector<ld> isec;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  for (int i=0;i<n;i++){
    cin>>ov[i].first>>ov[i].second;
  }
  sort(ov,ov+n,[&](pll&a,pll&b){return a>b;});
  vector<ll> a,b;
  for (int i=0;i<n;) {
    a.push_back(ov[i].first);
    b.push_back(ov[i].second);
    int j=i;
    while (j<n&&ov[i].second>=ov[j].second)j++;
    i=j;
  }
  n=a.size();
  cst[0]=0;
  lns.push_back({a[0],cst[0]});
  for (int i=1;i<=n;i++){
    ll x=b[i-1];
    int p=lower_bound(isec.begin(), isec.end(), (ld)x)-isec.begin();
    pll& ln=lns[p];
    cst[i]=ln.first*x+ln.second;
    while (1) {
      pll& ln2=lns.back();
      ld sc=((ld)(ln2.second-cst[i]))/(ld)(a[i]-ln2.first);
      if (!isec.empty()&&sc<=isec.back()) {
        lns.pop_back();
        isec.pop_back();
      } else {
        lns.push_back({a[i],cst[i]});
        isec.push_back(sc);
        break;
      }
    }
  }
  cout<<cst[n]<<'\n';
}
