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
#define N 200
ll n,k,x,a[N];
ll dp[201][201]={{0}};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>k>>x;
  for (ll i=0;i<=200;i++) for (ll j=0;j<=200;j++) dp[i][j]=-1;
  if (n/k>x) return cout<<"-1\n",0;
  for (ll i=0;i<n;i++)cin>>a[i];
  for (ll y=1;y<=x;y++) {
    
    for (ll i=0;i<n;i++) {
      ll r=-1;
      if (y==1&&i<k) r=0;
      for (ll j=max(i-k,0ll);j<i;j++) {
        r=max(r,dp[y-1][j]);
      }
      if (r==-1) continue;
      r+=a[i];
      dp[y][i]=r;
    }
  }
  ll res=-1;
  for (ll i=n-k;i<n;i++) res=max(res,dp[x][i]);
  cout<<res<<'\n';
}
