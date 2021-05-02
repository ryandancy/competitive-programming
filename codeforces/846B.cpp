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
ll n,k,m,t[45],st=0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>k>>m;
  for (ll i=0;i<k;i++) cin>>t[i],st+=t[i];
  sort(t,t+k);
  ll res=0;
  for (ll r=1;r<=n*(k+1);r++) {
    for (ll b=0;b<=n;b++) {
      ll v=b*st;
      ll s=r-b*(k+1);
      if (v>m||s<0) break;
      if (s==0) {
        res=r;
        goto nxt;
      }
      for (ll i=0;i<k;i++) {
        if (s<n-b) {
          v+=t[i]*s;
          s=0;
        } else {
          s-=n-b;
          v+=t[i]*(n-b);
        }
        if (v>m) break;
        if (s==0) {
          res=r;
          goto nxt;
        }
      }
    }
    nxt:;
  }
  cout<<res<<'\n';
}
