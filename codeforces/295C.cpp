// SUPER annoying complete search
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,k,na=0,nb=0;
ll dp[51][51][2]={{{0}}},dpw[51][51][2]={{{0}}},ch[51][51];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ch[0][0]=1;
  for (n=1;n<=50;n++) {
    for (k=0;k<=n;k++) {
      ch[n][k]=ch[n-1][k]+(k==0?0:ch[n-1][k-1]);
    }
  }
  cin>>n>>k;
  k/=50;
  for (int i=0;i<n;i++){
    ll x;
    cin>>x;
    if (x==50)na++;
    else nb++;
  }
  dpw[na][nb][0]=1;
  queue<tuple<ll,ll,ll,ll,ll,ll,ll> > bfs;
  bfs.push({0,1,-1,-1,1,na,nb});
  while (bfs.size()) {
    ll f,d,pa,pb,cw,a,b;
    tie(f,d,pa,pb,cw,a,b)=bfs.front(); bfs.pop();
    if (pa!=-1)dpw[a][b][f]+=dpw[pa][pb][!f]*cw%MOD;
    dpw[a][b][f]%=MOD;
    if (dp[a][b][f]) continue;
    dp[a][b][f]=d;
    if (f==0) {
      // to
      for (ll fa=0;fa<=k&&fa<=a;fa++) {
        for (ll fb=0;fa+2*fb<=k&&fb<=b;fb++) {
          if (fa==0&&fb==0)continue;
          ll qa=a-fa,qb=b-fb;
          if (dp[qa][qb][!f]) continue;
          bfs.push({!f,d+1,a,b,ch[a][fa]*ch[b][fb]%MOD,qa,qb});
        }
      }
    } else {
      // from
      for (ll ta=0;ta<=k&&ta<=na-a;ta++) {
        for (ll tb=0;ta+2*tb<=k&&tb<=nb-b;tb++) {
          if (ta==0&&tb==0)continue;
          ll qa=a+ta,qb=b+tb;
          if (dp[qa][qb][!f]) continue;
          bfs.push({!f,d+1,a,b,ch[na-a][ta]*ch[nb-b][tb]%MOD,qa,qb});
        }
      }
    }
  }
  if (dp[0][0][1]==0)cout<<"-1\n0\n";
  else {
    cout<<dp[0][0][1]-1<<'\n'<<(dpw[0][0][1]%MOD+MOD)%MOD<<"\n";
  }
}
