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
ll sc(ll x) {
  if (x==0)return 1;
  ll res=1;
  while (x) {
    res*=x%10;
    x/=10;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n;
  cin>>n;
  ll res=sc(n),bs=1;
  while (n>0) {
    bool i9=n%10==9;
    n/=10;
    if (!i9) n--;
    bs*=9;
    res=max(res,sc(n)*bs);
  }
  cout<<res<<'\n';
}
