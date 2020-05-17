#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifndef DEBUG
#define debug(args...)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
map<pll, ll> m; set<pll> u; ll zz=0;
inline ll fexp(ll b, ll e) {
  if (e==0) return 1;
  if (e==1) return b;
  ll r=fexp(b, e/2ll);
  r=(r*r)%MOD;
  if (e%2) r*=b, r%=MOD;
  return r;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin>>n;
  for (int i=0;i<n;i++) {
    ll a, b;
    cin>>a>>b;
    if (a==0&&b==0) {
      zz++;
      continue;
    }
    ll d=gcd(abs(a), abs(b));
    a/=d, b/=d;
    if (a<0||(a==0&&b<0)) {
      a=-a, b=-b;
    }
    m[{a,b}]++;
  }
  ll res=1;
  for (auto it=m.begin();it!=m.end();++it) {
    if (u.count(it->first)) continue;
    u.insert(it->first);
    ll x1=it->first.first, y1=it->first.second, cnt=it->second;
    ll x2=-y1, y2=x1;
    if (x2<0||(x2==0&&y2<0)) {
      x2=-x2, y2=-y2;
    }
    pll t={x2,y2};
    if (m.count(t)) {
      ll ad=fexp(2,cnt)+fexp(2,m[t])-1; ad%=MOD;
      res*=ad, res%=MOD;
      u.insert(t);
    } else {
      res*=fexp(2,cnt), res%=MOD;
    }
  }
  cout<<((res+zz-1)%MOD+MOD)%MOD<<'\n';
  return 0;
}
