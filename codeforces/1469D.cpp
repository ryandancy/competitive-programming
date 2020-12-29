#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...) (0)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin>>T;
  while (T--) {
    ll n;
    cin>>n;
    ll c=1;
    while (c<n) {
      ll a=c,b=n;
      int k=0;
      while (!(a==1&&b==2)&&k<=8) {
        if (a>b) swap(a,b);
        ll nb=b/a;
        if (b%a)nb++;
        b=nb;
        if (a>b) swap(a,b);
        k++;
      }
      if (k<=8) break;
      c++;
    }
    vector<pll> v;
    for (ll i=2;i<n;i++) {
      if (i==c)continue;
      v.push_back({i,n});
    }
    ll a=c,b=n;
    while (!(a==1&&b==2)) {
      if (a>b) swap(a,b),swap(c,n);
      v.push_back({n,c});
      ll nb=b/a;
      if (b%a)nb++;
      b=nb;
      if (a>b) swap(a,b),swap(c,n);
    }
    cout<<v.size()<<'\n';
    for (pll&x:v) {
      cout<<x.first<<' '<<x.second<<'\n';
    }
  }
}
