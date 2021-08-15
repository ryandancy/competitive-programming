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
#define N 100000
ll uf1[N],sz1[N],uf2[N],sz2[N];

ll find(ll x,ll*uf) {
  return uf[x]==x?x:uf[x]=find(uf[x],uf);
}

void unite(ll x, ll y, ll*uf, ll*sz) {
  x=find(x,uf),y=find(y,uf);
  if (x==y) return;
  if (sz[x]<sz[y]) swap(x,y);
  uf[y]=x,sz[x]+=sz[y];
}

// vector<ll> adj1[N],adj2[N];
vector<pll> e1,e2;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n,m1,m2;
  cin>>n>>m1>>m2;
  for (int i=0;i<n;i++) uf1[i]=uf2[i]=i,sz1[i]=sz2[i]=1;
  for (int i=0;i<m1;i++) {
    ll u,v;
    cin>>u>>v;
    u--,v--;
    unite(u,v,uf1,sz1);
    e1.push_back({min(u,v),max(u,v)});
    // adj1[u].push_back(v);
    // adj1[v].push_back(u);
  }
  for (int i=0;i<m2;i++) {
    ll u,v;
    cin>>u>>v;
    u--,v--;
    unite(u,v,uf2,sz2);
    e2.push_back({min(u,v),max(u,v)});
    // adj2[u].push_back(v);
    // adj2[v].push_back(u);
  }
  ll h=0;
  sort(e1.begin(),e1.end());
  sort(e2.begin(),e2.end());
  vector<pll> a;
  for (int i=0;i<n;i++) {
    for (int j=i+1;j<n;j++) {
      if (find(i,uf1)==find(j,uf1)||find(i,uf2)==find(j,uf2)) continue;
      pll p{i,j};
      if (binary_search(e1.begin(),e1.end(),p)||binary_search(e2.begin(),e2.end(),p)) continue;
      h++;
      a.push_back({i,j});
      unite(i,j,uf1,sz1);
      unite(i,j,uf2,sz2);
    }
  }
  cout<<h<<'\n';
  for (const pll&p:a) {
    cout<<p.first+1<<' '<<p.second+1<<'\n';
  }
  // for (const pll&p:e1) {
  //   if (find(p.first,uf1)!=find(p.second,uf1)&&find(p.first,uf2)!=find(p.second,uf2)) {
      
  //   }
  // }
}
