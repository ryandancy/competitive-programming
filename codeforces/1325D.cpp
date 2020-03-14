#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...)
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
  ll u, v;
  cin >> u >> v;
  if (u>v) return cout<<"-1\n",0;
  if (u==v&&u==0) return cout<<"0\n",0;
  if (u==v) return cout<<1<<'\n'<<u<<'\n',0;
  ll df=v-u;
  ll ou=u,ov=v;
  if (df%2==1) return cout<<"-1\n",0;
  vector<ll> c;
  while (df!=0) {
    ll x=0;
    for (ll i=61;i>=0;i--) {
      if ((u&(1ll<<i))==0&&df>=2ll*(1ll<<i)) {
        u |= 1ll<<i;
        x |= 1ll<<i;
        df -= 2ll*(1ll<<i);
        if (df==0)break;
      }
    }
    c.push_back(u);
    if (df==0||c.size()>=3) {
      if (c.size()>=3) {
        cout<<"3\n";
        cout<<ou<<' '<<(ov-ou)/2<<' '<<(ov-ou)/2<<'\n';
      } else {
        cout<<c.size()+1<<'\n';
        for (int i=0;i<c.size();i++) {
          cout<<c[i]<<' ';
        }
        cout<<x<<'\n';
      }
      return 0;
    }
    u=x;
    x=0;
  }
  cout<<"-1\n";
}
