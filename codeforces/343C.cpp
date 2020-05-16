#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll h[100000], p[100000], n, m;
inline ll cst(int l, int r, int i) {
  return p[r]-p[l]+min(abs(h[i]-p[l]), abs(h[i]-p[r]));
}
inline bool ok(ll md) {
  int c=0;
  for (int i=0;i<n&&c<m;i++) {
    int l=c;
    while (c<m&&cst(l,c,i)<=md)c++;
  }
  return c==m;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>m;
  for (int i=0;i<n;i++)cin>>h[i];
  for (int i=0;i<m;i++)cin>>p[i];
  ll l=0, r=LLONG_MAX;
  while (l<=r) {
    ll md=l+(r-l)/2ll;
    if (ok(md)) r=md-1;
    else l=md+1;
  }
  if (r>0&&ok(r-1)) cout<<r-1<<'\n';
  else if (ok(r)) cout<<r<<'\n';
  else cout<<l<<'\n';
}
