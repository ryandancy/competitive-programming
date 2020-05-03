#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifndef DEBUG
#define debug(args...)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  ll v, x, m;
  cin>>v>>x>>m;
  vector<pii> w;
  for (ll q=1;q<m;q++){
    ll p=v*q%m;
    if (p/q==x)w.push_back({p,q});
  }
  if (w.empty())return cout<<"-1\n",0;
  sort(w.begin(),w.end());
  cout<<w[0].first<<' '<<w[0].second<<'\n';
}
