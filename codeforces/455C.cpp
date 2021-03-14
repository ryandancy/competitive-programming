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
ll n,m,q;
vector<ll> adj[300000];
ll uf[300000],sz[300000],d[300000];
bool v[300000]={false},v2[300000]={false};
ll ldfs(ll x,bool*mv,ll&f) {
  mv[x]=true;
  ll b=0;
  f=x;
  for (ll a:adj[x]) {
    if (mv[a]) continue;
    ll sf;
    ll nb=ldfs(a,mv,sf)+1;
    if (nb>b) {
      b=nb;
      f=sf;
    }
  }
  return b;
}
ll find(ll x) { // O(a(n))
  return uf[x]==x?x:uf[x]=find(uf[x]);
}
void unite(ll x, ll y) { // O(a(n))
  x=find(x),y=find(y);
  if (x==y) return;
  if (sz[x]<sz[y]) swap(x,y);
  uf[y]=x,sz[x]+=sz[y];
  d[x]=max(max(d[x],d[y]),d[x]/2+d[x]%2+d[y]/2+d[y]%2+1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>m>>q;
  for (ll i=0;i<n;i++) uf[i]=i,sz[i]=1,d[i]=0;
  for (ll i=0;i<m;i++){
    ll a,b;
    cin>>a>>b;
    a--,b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
    unite(a,b);
  }
  for (ll i=0;i<n;i++) {
    if (v[i]) continue;
    ll f,_;
    ldfs(i,v,f);
    d[find(i)]=ldfs(f,v2,_);
  }
  while (q--) {
    ll t,x,y;
    cin>>t;
    if (t==1) {
      cin>>x;
      cout<<d[find(x-1)]<<'\n';
    } else {
      cin>>x>>y;
      unite(x-1,y-1);
    }
  }
}
