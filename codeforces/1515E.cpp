#include <bits/stdc++.h>
#define MOD M
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
#define N 400
ll dp[N+1][N+1]={{0}};//,dp[N+1]={0};
ll ch[2*N+3][2*N+3]={{0}};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n,M;
  cin>>n>>M;
  dp[1][0]=1;
  for (ll i=2;i<=N;i++) {
    dp[i][0]=2*dp[i-1][0];
    dp[i][0]%=M;
    dp[i][0]+=M;
    dp[i][0]%=M;
  }
  ch[0][0]=1;
  for (ll i=1;i<2*N+3;i++) {
    for (ll j=0;j<=i;j++) {
      ch[i][j]=ch[i-1][j];
      if (j>0) ch[i][j]+=ch[i-1][j-1];
      ch[i][j]%=M;
      ch[i][j]+=M;
      ch[i][j]%=M;
    }
  }
  for (ll h=1;h<=N;h++) {
    for (ll k=1;k<=N;k++) {
      for (ll i=0;i<=k;i++) {
        ll a=i,b=k-i-1;
        ll s1=i,s2=b-h+1;
        if (s2<0) continue;
        ll c=ch[s1+s2][s1];
        ll v=dp[a][0]*dp[b][h-1];
        v%=M;
        v+=M;
        v%=M;
        v*=c;
        v%=M;
        v+=M;
        v%=M;
        dp[k][h]+=v;
        dp[k][h]%=M;
        dp[k][h]+=M;
        dp[k][h]%=M;
      }
    }
  }
  ll sm=0;
  for (ll i=0;i<=N;i++) {
    sm+=dp[n][i];
    sm%=M;
    sm+=M;
    sm%=M;
  }
  // for (ll i=0;i<=n;i++) for (ll h=0;h<i;h++) debug(i,h,dp[i][h]);
  cout<<sm<<'\n';
}
