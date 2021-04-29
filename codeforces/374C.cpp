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
ll n,m;
string mp[1000];
ll rs[1000][1000]={{0}};
ll v[1000][1000]={{0}};
void dfs(ll x, ll y) {
  if (v[y][x]) return;
  v[y][x]=1;
  rs[y][x]=1;
  char nxt;
  switch (mp[y][x]) {
    case 'D': nxt='I'; break;
    case 'I': nxt='M'; break;
    case 'M': nxt='A'; break;
    case 'A': nxt='D'; break;
  }
  for (ll dx=-1;dx<=1;dx++) {
    for (ll dy=-1;dy<=1;dy++) {
      if ((dx==0)==(dy==0)) continue;
      ll nx=x+dx,ny=y+dy;
      if (nx<0||nx>=m||ny<0||ny>=n) continue;
      if (mp[ny][nx]!=nxt) continue;
      if (v[ny][nx]==1) {
        cout<<"Poor Inna!\n";
        exit(0);
      }
      if (v[ny][nx]==0) dfs(nx,ny);
      rs[y][x]=max(rs[y][x],rs[ny][nx]+1);
    }
  }
  v[y][x]=2;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>m;
  for (ll i=0;i<n;i++)cin>>mp[i];
  for (ll y=0;y<n;y++) {
    for (ll x=0;x<m;x++) dfs(x,y);
  }
  ll mx=0;
  for (ll y=0;y<n;y++) {
    for (ll x=0;x<m;x++) {
      if (mp[y][x]=='D') {
        mx=max(mx,rs[y][x]/4);
      }
    }
  }
  if (mx==0) {
    cout<<"Poor Dima!\n";
  } else {
    cout<<mx<<'\n';
  }
}
