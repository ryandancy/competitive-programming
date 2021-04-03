// technically constant time, but n sqrt n on the number of islands
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
ll n,d,p[30001]={0},dp[30001][1000]={{0}};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>d;
  for (ll i=0;i<n;i++) {
    ll x;
    cin>>x;
    p[x]++;
  }
  for (ll x=30000;x>=0;x--) {
    for (ll i=0;i<1000;i++) {
      ll lj=d+i-500;
      if (lj<=0||lj>30000) continue;
      dp[x][i]=p[x];
      ll bf=0;
      if (i>0&&x+lj-1<=30000) bf=max(bf,dp[x+lj-1][i-1]);
      if (x+lj<=30000) bf=max(bf,dp[x+lj][i]);
      if (i<999&&x+lj+1<=30000) bf=max(bf,dp[x+lj+1][i+1]);
      dp[x][i]+=bf;
    }
  }
  cout<<dp[d][500]<<'\n';
}
