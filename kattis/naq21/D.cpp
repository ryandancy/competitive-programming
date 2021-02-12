#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifndef DEBUG
#define debug(args...) (0)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll r[101];
set<ll> res;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  ll w,p;
  cin>>w>>p;
  for (int i=0;i<p;i++)cin>>r[i];
  r[p]=w;
  for (int i=0;i<=p;i++) {
    res.insert(r[i]);
    for (int j=0;j<=p;j++) {
      if (i==j)continue;
      res.insert(abs(r[i]-r[j]));
    }
  }
  int i=0;
  for (int x:res) {
    cout<<x;
    i++;
    if (i==res.size())cout<<'\n';
    else cout<<' ';
  }
}
