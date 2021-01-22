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
vector<ll> dr[200000];
vector<pll> e;
ll dinc[200000], tp[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int t;
  cin>>t;
  while (t--) {
    ll n,m;
    cin>>n>>m;
    e.clear();
    for (ll i=0;i<n;i++) dr[i].clear(),dinc[i]=0,tp[i]=0;
    for (ll i=0;i<m;i++) {
      ll t,x,y;
      cin>>t>>x>>y;
      x--,y--;
      if (t) dr[x].push_back(y),dinc[y]++;
      e.push_back({x,y});
    }
    ll tn=0;
    queue<ll> q;
    for (ll x=0;x<n;x++)if (dinc[x]==0)q.push(x);
    while (q.size()) {
      ll x=q.front(); q.pop();
      // debug(x,tn);
      tp[x]=tn++;
      for (ll y:dr[x]) if (--dinc[y]==0) q.push(y);
    }
    // debug("tn", tn);
    if (tn!=n) {cout<<"NO\n"; continue;}
    cout<<"YES\n";
    for(pll p:e) {
      if (tp[p.first]>tp[p.second])swap(p.first,p.second);
      cout<<p.first+1<<' '<<p.second+1<<'\n';
    }
  }
}
