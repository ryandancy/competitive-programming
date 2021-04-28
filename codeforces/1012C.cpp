#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 100000000000
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
ll a[5000],dp[5000][5000]={{0}},rm[5000][5000]={{0}};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n;
  cin>>n;
  for (ll i=0;i<n;i++)cin>>a[i];
  for (ll k=1;k<=n/2+n%2;k++) {
    for (ll i=0;i<n;i++) {
      ll cl=i==0?0:max(a[i-1]-a[i]+1,0ll);
      ll cr=i==n-1?0:max(a[i+1]-a[i]+1,0ll);
      ll lcr,ccl;
      if (i<=1) {
        dp[i][k]=k==1?cl+cr:INF;
        goto nxt;
      }
      lcr=max(a[i-1]-a[i-2]+1,0ll);
      if (k==1) lcr=0;
      ccl=max(cl-lcr,0ll);
      debug(i,k,cl,ccl,cr,rm[i-3][k-1]);
      dp[i][k]=min(dp[i-2][k-1]+ccl+cr,cl+cr+(i==2?INF:rm[i-3][k-1]));
    nxt:
      if (i==0) rm[i][k]=dp[i][k];
      else rm[i][k]=min(rm[i-1][k],dp[i][k]);
    }
  }
  for (ll k=1;k<=n/2+n%2;k++) {
    ll m=INF;
    for (ll i=0;i<n;i++) {
      m=min(m,dp[i][k]);
    }
    cout<<m<<(k==n/2+n%2?'\n':' ');
  }
  // for (ll k=1;k<=n/2+n%2;k++) {
  //   for (ll i=0;i<n;i++) {
  //     ll x = i==0?INF:dp[i-1][k];
  //     ll y = i<=1?k==1?0:INF:dp[i-2][k-1];
  //     ll cl = i==0?0:max(a[i-1]-a[i]+1,0ll);
  //     ll cr = i==n-1?0:max(a[i+1]-a[i]+1,0ll);
  //     dp[i][k]=min(x,y+cl+cr);
  //   }
  //   cout<<dp[n-1][k]<<(k==n/2+n%2?'\n':' ');
  // }
  for (ll i=0;i<n;i++) {
    for (ll j=1;j<=n/2+n%2;j++) debug(i,j,dp[i][j]);
  }
}
