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
string digs[]={"1110111", "0010010", "1011101", "1011011", "0111010",
  "1101011", "1101111", "1010010", "1111111", "1111011"};
string o[2000];
int df[2001][10];
pii dp[2001][2001];
int dpo[2001][2001], dpk[2001][2001];
int dpt[2001][2001];
int ci=0;
bool pc(int&a, int&b){
  if (dp[ci][a].first==-1)return false;
  if (dp[ci][b].first==-1)return true;
  if (ci==0){
    return dp[ci][a].second>dp[ci][b].second;
  }
  if (dp[ci][a].first!=dp[ci][b].first)return dp[ci][a].first<dp[ci][b].first;
  return dp[ci][a].second>dp[ci][b].second;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n,k;
  cin>>n>>k;
  for (int i=0;i<=2000;i++)for (int j=0;j<=2000;j++)dpo[i][j]=-1;
  for (int i=0;i<n;i++)cin>>o[i];
  for (int i=0;i<n;i++){
    for (int j=0;j<=9;j++){
      df[i][j]=0;
      for (int c=0;c<7;c++){
        if (o[i][c]=='0'&&digs[j][c]=='1')df[i][j]++;
        else if (o[i][c]=='1'&&digs[j][c]=='0'){
          df[i][j]=-1;
          break;
        }
      }
    }
  }
  // for (int i=0;i<n;i++)for (int j=0;j<=9;j++)debug(i,j,df[i][j]);
  for (int j=0;j<=k;j++){
    int mxd=-1;
    for (int d=0;d<=9;d++){
      if (df[0][d]==-1)continue;
      if (df[0][d]==j){
        mxd=d;
      }
    }
    if (mxd==-1)dp[0][j].first=-1,dp[0][j].second=-1;
    else dp[0][j].first=0,dp[0][j].second=mxd;
    dpk[0][j]=j;
    dpt[0][j]=-1;
  }
  sort(dpk[0],dpk[0]+k+1,pc);
  for (int j=0;j<=k;j++){
    if (dpk[0][j]!=-1)dpo[0][dpk[0][j]]=j;
  }
  // for (int i=0;i<=k;i++)debug(i,dp[0][i].first,dp[0][i].second);
  // for (int i=0;i<=k;i++)debug(i,dpo[0][i]);
  for (ci=1;ci<n;ci++){
    for (int j=0;j<=k;j++){
      int mxo=-1,mxd=-1,mxt=-1;
      for (int d=0;d<=9;d++){
        if(df[ci][d]==-1)continue;
        if (df[ci][d]<=j&&dp[ci-1][j-df[ci][d]].first!=-1){
          int ov=dpo[ci-1][j-df[ci][d]];
          if (mxo==-1||ov<mxo||(mxo==ov&&d>mxd)){
            mxo=ov,mxd=d;
            // debug(ci,j,ov,d,j-df[ci][d]);
            mxt=j-df[ci][d];
          }
        }
      }
      if (mxd==-1)dp[ci][j].first=-1,dp[ci][j].second=-1,dpt[ci][j]=-1;
      else dp[ci][j].first=mxo,dp[ci][j].second=mxd,dpt[ci][j]=mxt;
      dpk[ci][j]=j;
    }
    sort(dpk[ci],dpk[ci]+k+1,pc);
    for (int j=0;j<=k;j++){
      if (dpk[ci][j]!=-1)dpo[ci][dpk[ci][j]]=j;
    }
    // for (int i=0;i<=k;i++)debug(i,dp[ci][i].first,dp[ci][i].second);
    // for (int i=0;i<=k;i++)debug(i,dpo[ci][i]);
  }
  if (dp[n-1][k].first==-1){
    cout<<"-1\n";
    return 0;
  } else {
    stack<int> ds;
    for (int c=k,i=n-1;i>=0;c=dpt[i--][c]){
      ds.push(dp[i][c].second);
    }
    while (ds.size()){
      cout<<ds.top();ds.pop();
    }
    cout<<'\n';
  }
}
