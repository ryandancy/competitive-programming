#include <bits/stdc++.h>
#define PI 3.1415926535897932384626433832795L
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll n;
vector<pair<ld,pair<ll,ll>>> xy;
ll r(const pair<ll,ll>&f) {
  return f.first*f.first+f.second*f.second;
}
pair<ll,ll>pl(pair<ll,ll>a,pair<ll,ll>b) {
  return {a.first+b.first,a.second+b.second};
}
pair<ll,ll>mn(pair<ll,ll>a,pair<ll,ll>b) {
  return {a.first-b.first,a.second-b.second};
}
ld el2p(ld x) {
  while (x<0) x+=2*PI;
  while (x>2*PI)x-=2*PI;
  return x;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  for (ll i=0;i<n;i++){
    ll x,y;
    cin>>x>>y;
    xy.push_back({atan2(y,x),{x,y}});
  }
  sort(xy.begin(),xy.end());
  ll bst=0;
  ll j=0;
  pair<ll,ll> ts{0,0};
  for (ll i=0;i<n;i++) {
    while (j<n&&el2p(xy[(i+j)%n].first-xy[i].first)<PI) {
      ts=pl(ts,xy[(i+j)%n].second);
      bst=max(bst,r(ts));
      j++;
    }
    ts=mn(ts,xy[i].second);
    bst=max(bst,r(ts));
    j--;
  }
  cout<<bst<<'\n';
}
