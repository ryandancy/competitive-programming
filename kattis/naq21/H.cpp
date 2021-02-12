#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifndef DEBUG
#define debug(args...) (0)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int x,y;
string k,mp[100];
int dp[100][100][51];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  cin>>x>>y>>k;
  for (int i=0;i<y;i++)cin>>mp[y-i-1];
  for (int c=0;c<=k.size();c++)dp[y-1][x-1][c]=mp[y-1][x-1]-'0';
  for (int c=k.size();c>=0;c--) {
    for (int i=y-1;i>=0;i--) {
      for (int j=x-1;j>=0;j--) {
        if (i==y-1&&j==x-1)continue;
        dp[i][j][c]=INF;
        if (i<y-1)dp[i][j][c]=min(dp[i][j][c],dp[i+1][j][c]+mp[i][j]-'0');
        if (j<x-1)dp[i][j][c]=min(dp[i][j][c],dp[i][j+1][c]+mp[i][j]-'0');
        if (c==k.size()) {debug(i,j,c,dp[i][j][c]);continue;}
        int dg=k[c]-'0';
        if (dg==0)continue;
        dg++;
        if (i+dg<y)dp[i][j][c]=min(dp[i][j][c],dp[i+dg][j][c+1]+mp[i][j]-'0');
        if (j+dg<x)dp[i][j][c]=min(dp[i][j][c],dp[i][j+dg][c+1]+mp[i][j]-'0');
        debug(i,j,c,dp[i][j][c]);
      }
    }
  }
  cout<<dp[0][0][0]<<'\n';
}
