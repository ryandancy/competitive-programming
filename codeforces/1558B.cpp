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
ll dp[4000001]={0},diff[4000001]={0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n,m;
  cin>>n>>m;
  ll ps=0,dps=0;
  for (ll i=1;i<=n;i++) {
    if (i==1) dp[1]=1,ps=1;
    else {
      dps+=diff[i]; dps%=m; dps+=m; dps%=m;
      dp[i]=((ps+dps)%m+m)%m;
      ps+=dp[i];
      ps%=m;
      ps+=m;
      ps%=m;
    }
    for (ll j=2;j*i<=n;j++) {
      diff[j*i]+=dp[i];
      diff[j*i]%=m;
      diff[j*i]+=m;
      diff[j*i]%=m;
      if (j*i+j<=n) {
        diff[j*i+j]-=dp[i];
        diff[j*i+j]%=m;
        diff[j*i+j]+=m;
        diff[j*i+j]%=m;
      }
    }
    // debug(i,dp[i],diff[i]);
  }
  cout<<(dp[n]%m+m)%m<<'\n';
}
