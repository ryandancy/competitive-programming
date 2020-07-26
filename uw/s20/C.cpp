#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifndef DEBUG
#define debug(args...)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int l[201];
int dp[201];
int pv[201];
bool prt[201]={false};
int f;
bool ok(int n) {
  if (n<0)return true;
  int res=0;
  int sum=0;
  for (int i=0;i<n;i++){
    if (l[i]>f)return false;
    sum+=l[i];
    dp[i]=l[i];
    pv[i]=-1;
    for (int j=0;j<i;j++){
      int cs=dp[j]+l[i];
      if (cs<=f){
        if (cs>dp[i]) {
          dp[i]=cs;
          pv[i]=j;
        }
      }
    }
    res=max(res,dp[i]);
  }
  return sum-res<=f;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  cin>>f;
  f*=100;
  int nc;
  for (nc=0;cin>>l[nc],l[nc];nc++);
  int l=0,r=nc-1;
  while (l<=r){
    int m=(l+r)/2;
    // debug(m,ok(m));
    if (ok(m)) {
      l=m+1;
    } else {
      r=m-1;
    }
  }
  int v=ok(l)?l:ok(r)?max(r,0):max(r-1,0);
  if (v==0){
    cout<<"0\n";
    return 0;
  }
  ok(v);
  int mi=0;
  for (int i=0;i<v;i++)if (dp[i]>dp[mi])mi=i;
  while (mi!=-1) {
    prt[mi]=true;
    mi=pv[mi];
  }
  cout<<v<<'\n';
  for (int i=0;i<v;i++){
    cout<<(prt[i]?"port\n":"starboard\n");
  }
  // for (int i=0;i<v;i++)debug(dp[i]);
  // for (int i=0;i<v;i++)debug(pv[i]);
  
}
