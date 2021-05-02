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
#define S 50
ll n,s,k;
ll a[51]={0}; string co;
bool v[51]={false};
vector<ll> adj[51];
vector<pll> pa[51];
ll mt[51][2001];
ll res=INF;
void rc(ll x) {
  if (v[x]) return;
  for (pll p:pa[x]) if (!v[p.first]) return;
  v[x]=true;
  for (pll p:pa[x]) {
    for (ll q=0;q<=k;q++) {
      if (mt[p.first][q]>=INF) continue;
      ll e=min(k,q+a[x]);
      ll nt=mt[p.first][q]+p.second;
      if (e==k) res=min(res,nt);
      mt[x][e]=min(mt[x][e],nt);
    }
  }
  for (ll c:adj[x]) rc(c);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>s>>k; s--;
  for (ll i=0;i<n;i++)cin>>a[i];
  cin>>co;
  for (ll i=0;i<n;i++) {
    for (ll j=0;j<n;j++) {
      if (a[i]<a[j]&&co[i]!=co[j]) {
        adj[i].push_back(j);
        pa[j].push_back({i,abs(i-j)});
      }
    }
  }
  for (ll i=0;i<n;i++) {
    adj[S].push_back(i);
    pa[i].push_back({S,abs(i-s)});
  }
  for (ll i=0;i<=S;i++) for (ll j=0;j<=k;j++) mt[i][j]=INF;
  mt[S][0]=0;
  rc(S);
  if (res==INF) cout<< -1<<'\n';
  else cout<<res<<'\n';
}
