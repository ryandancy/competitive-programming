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
ll px[100000], py[100000],sx=0,sy=0,n,dx,dy;
bool ok(ll m) {
  m--;
  if (m<0)return false;
  ll k=m/n;
  ll ndx=dx-k*sx-px[m%n],ndy=dy-k*sy-py[m%n];
  debug(dx,dy,m,k,ndx,ndy);
  return abs(ndx)+abs(ndy)<=m+1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  dx=x2-x1,dy=y2-y1;
  string s;
  cin>>n>>s;
  for (int i=0;i<n;i++) {
    char c=s[i];
    if (c=='U')sy++;
    else if (c=='D')sy--;
    else if (c=='L')sx--;
    else if (c=='R')sx++;
    px[i]=sx;
    py[i]=sy;
  }
  ll l=0,r=200000000000000ll;
  while (l<=r) {
    ll m=(l+r)/2;
    if (ok(m)) {
      r=m-1;
    } else {
      l=m+1;
    }
  }
  debug(r,l);
  cout<<(ok(r-1)?r-1:ok(r)?r:ok(l)?l:ok(l+1)?l+1:-1)<<'\n';
}
