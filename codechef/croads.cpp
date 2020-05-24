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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin>>T;
  while (T--) {
    ll n;
    cin>>n;
    if ((n&-n)==n) {cout<<"-1\n";continue;}
    ll res=0;
    for (ll i=0;(1ll<<i)<n;i++){
      res+=(1ll<<i)*((n-(1ll<<i))/(1ll<<(i+1))+1);
    }
    cout<<res-1<<'\n';
  }
}
