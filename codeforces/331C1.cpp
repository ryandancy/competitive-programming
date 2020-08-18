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
ll dp[1000001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n;
  cin>>n;
  dp[0]=0;
  for (ll i=1;i<=n;i++) {
    ll j=i;
    dp[i]=INF;
    while (j) {
      dp[i]=min(dp[i],dp[i-j%10]+1);
      j/=10;
    }
  }
  cout<<dp[n]<<'\n';
}
