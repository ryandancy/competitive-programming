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
vector<ll> adj[200];
vector<pll> e;
pll vb{-1,-1};
bool v[200]={false};
ll dfs(ll&x) {
  ll x2=x;
  v[x2]=true;
  ll mx=-1;
  for (ll y:adj[x2]) {
    if ((x2==vb.first&&y==vb.second)||(x2==vb.second&&y==vb.first)) continue;
    if (!v[y]) {
      ll z=y;
      ll d=dfs(z);
      if (d>mx) {
        mx=d;
        x=z;
      }
    }
  }
  debug(x2,x,mx+1);
  return mx+1;
}
ll diam(ll x) {
  fill_n(v,200,false);
  dfs(x);
  fill_n(v,200,false);
  return dfs(x);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n;
  cin>>n;
  for (ll i=0;i<n-1;i++) {
    ll x,y;
    cin>>x>>y;
    x--,y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
    e.push_back({x,y});
  }
  ll mx=0;
  for (pll t:e) {
    vb=t;
    debug(t.first,t.second);
    mx=max(mx,diam(t.first)*diam(t.second));
  }
  cout<<mx<<'\n';
}
