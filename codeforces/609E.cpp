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
ll n,m,mstw=0;
ll u[200000], v[200000], wg[200000];
vector<pll> adj[200000], mst[200000];
bool vi[200000]={false},v2[200000]={false};
ll p[200000][19]={{0}},mx[200000][19]={{0}},d[200000]={0};
ll afm(ll& x, ll amt) {
  ll res=0;
  for (int k=0;k<19;k++) {
    if (amt&(1<<k)) {
      res=max(res,mx[x][k]);
      x=p[x][k];
    }
  }
  return res;
}
ll pmx(ll a,ll b) {
  ll res=0;
  if (d[a]<d[b])swap(a,b);
  res=max(res,afm(a,d[a]-d[b]));
  if (a==b) return res;
  for (int k=18;k>=0;k--) {
    if (p[a][k]!=p[b][k]) {
      res=max(res,mx[a][k]);
      res=max(res,mx[b][k]);
      a=p[a][k];
      b=p[b][k];
    }
  }
  res=max(res,mx[a][0]);
  res=max(res,mx[b][0]);
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>m;
  for (int i=0;i<m;i++) {
    cin>>u[i]>>v[i]>>wg[i];
    u[i]--,v[i]--;
    if (u[i]>v[i])swap(u[i],v[i]);
    adj[u[i]].push_back({v[i],wg[i]});
    adj[v[i]].push_back({u[i],wg[i]});
  }
  priority_queue<tuple<ll,ll,ll> > pq;
  pq.push({0,-1,0});
  int vs=0;
  while (vs<n) {
    tuple<int,int,int> a=pq.top(); pq.pop();
    ll d,pv,c;
    tie(d,pv,c)=a;
    d=-d;
    if (vi[c]) continue;
    mstw+=d;
    vs++;
    vi[c]=true;
    if (pv!=-1) {
      mst[pv].push_back({c,d});
      mst[c].push_back({pv,d});
    }
    for (pll nb:adj[c]) {
      if (vi[nb.first]) continue;
      pq.push({-nb.second,c,nb.first});
    }
  }
  stack<ll> stk;
  stk.push(0);
  v2[0]=true;
  while (stk.size()) {
    ll c=stk.top(); stk.pop();
    for (pll nb:mst[c]) {
      if (v2[nb.first])continue;
      v2[nb.first]=true;
      p[nb.first][0]=c;
      mx[nb.first][0]=nb.second;
      d[nb.first]=d[c]+1;
      stk.push(nb.first);
    }
  }
  for (int k=1;k<19;k++) {
    for (ll i=0;i<n;i++) {
      p[i][k]=p[p[i][k-1]][k-1];
      mx[i][k]=max(mx[i][k-1],mx[p[i][k-1]][k-1]);
    }
  }
  for (int i=0;i<m;i++) {
    if (u[i]==p[v[i]][0]||v[i]==p[u[i]][0])cout<<mstw<<'\n';
    else cout<<mstw+wg[i]-pmx(u[i],v[i])<<'\n';
  }
}
