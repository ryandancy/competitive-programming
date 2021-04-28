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
ll n,a[300000],mn[300000][30],gc[300000][30];
bool okr(ll l,ll r) {
  if (r>=n||l>=n) return false;
  ll o=1,k=0;
  while (2*o<r-l+1)o*=2,k++;
  ll x=r-o+1;
  ll m=min(mn[l][k],mn[x][k]);
  ll g=__gcd((unsigned long long)gc[l][k],(unsigned long long)gc[x][k]);
  // debug(l,r,o,k,x,m,g,m==g);
  return m==g;
}
bool ok(ll rg) {
  for (ll i=0;i+rg<n;i++) {
    if (okr(i,i+rg)) return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n;
  for (ll i=0;i<n;i++)cin>>a[i],mn[i][0]=gc[i][0]=a[i];
  for (ll k=1;k<20;k++) {
    for (ll i=0;i+(1<<k)<=n;i++) {
      mn[i][k]=min(mn[i][k-1],mn[i+(1<<(k-1))][k-1]);
      gc[i][k]=__gcd((unsigned long long)gc[i][k-1], (unsigned long long)gc[i+(1<<(k-1))][k-1]);
    }
  }
  ll x=0,y=n-1,res;
  while (x<=y) {
    ll m=(x+y)/2;
    if (ok(m)) {
      x=m+1;
    } else {
      y=m-1;
    }
    res=ok(x+1)?x+1:ok(x)?x:y;
  }
  vector<ll> p;
  for (ll i=0;i+res<n;i++) {
    if (okr(i,i+res)) p.push_back(i);
  }
  cout<<p.size()<<' '<<res<<'\n';
  for (ll i=0;i<p.size();i++) {
    cout<<p[i]+1;
    if (i==p.size()-1) cout<<'\n';
    else cout<<" ";
  }
}
