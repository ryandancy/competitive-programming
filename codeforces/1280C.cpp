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
ll k;
vector<ll> adj[200000];
vector<pair<pll,ll>> ed;
ll u[200000];
bool v[200000]={false};
void fu(ll x) {
  v[x]=true;
  u[x]=1;
  for (ll p:adj[x]) {
    if (!v[p]) {
      fu(p);
      u[x]+=u[p];
    }
  }
}
ll fg() {
  ll G=0;
  for (auto e:ed) {
    const pll&p=e.first;
    ll x=p.first,y=p.second;
    if (u[x]>u[y]) swap(x,y);
    if (u[x]%2==1) G+=e.second;
  }
  return G;
}
ll fb() {
  ll B=0;
  for (auto e:ed) {
    const pll&p=e.first;
    ll x=p.first,y=p.second;
    if (u[x]>u[y]) swap(x,y);
    B+=min(u[x],u[0]-u[x])*e.second;
  }
  return B;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll t;
  cin>>t;
  while (t--) {
    cin>>k;
    ed.clear();
    for (ll i=0;i<2*k;i++) adj[i].clear();
    for (ll i=0;i<2*k-1;i++) {
      ll x,y,t;
      cin>>x>>y>>t;
      x--,y--;
      adj[x].push_back(y);
      adj[y].push_back(x);
      ed.push_back({{x,y},t});
    }
    for (ll i=0;i<2*k;i++) u[i]=0,v[i]=false;
    fu(0);
    cout<<fg()<<' '<<fb()<<'\n';
  }
}
