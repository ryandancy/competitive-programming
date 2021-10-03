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
typedef array<ll,10> aa;
ll n,c[10],a[10][200000],m;
aa b[100000];
ll su(aa x) {
  ll s=0;
  for (ll i=0;i<n;i++) {
    s+=a[i][x[i]];
  }
  return s;
}
bool so(aa x,aa y) {
  for (ll i=0;i<n;i++) {
    if (x[i]<y[i]) return true;
    if (x[i]>y[i]) return false;
  }
  return false;
}
struct cmp {
  bool operator()(array<ll,10> x,array<ll,10> y) const {
    ll sa=su(x),sb=su(y);
    if (sa>sb) return true;
    if (sa<sb) return false;
    return so(x,y);
  }
};
inline bool ok(array<ll,10>mb) {
  return !binary_search(b,b+m,mb,so);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n;
  for (ll i=0;i<n;i++) {
    cin>>c[i];
    for (ll j=0;j<c[i];j++) {
      cin>>a[i][j];
    }
  }
  cin>>m;
  for (ll i=0;i<m;i++) {
    for (ll j=0;j<n;j++) {
      cin>>b[i][j]; b[i][j]--;
    }
  }
  sort(b,b+m,so);
  set<aa,cmp> pq;
  aa fi;
  for (ll i=0;i<n;i++) {
    fi[i]=c[i]-1;
  }
  pq.insert(fi);
  ll mxs=m+10;
  while (pq.size()) {
    aa q=*pq.begin();pq.erase(pq.begin()); mxs--;
    if (ok(q)) {
      for (ll i=0;i<n;i++) {
        cout<<q[i]+1<<(i==n-1?'\n':' ');
      }
      break;
    }
    for (ll i=0;i<n;i++) {
      if (q[i]>0) {
        q[i]--;
        pq.insert(q);
        q[i]++;
        while (pq.size() > mxs) pq.erase(--pq.end());
      }
    }
  }
}
