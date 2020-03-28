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
  int t;
  cin>>t;
  while (t--){
    ll n, k;
    cin>>n>>k;
    ll Q = floorl((-1+sqrtl((ld)(8*k-7)))/2.0L);
    ll f=Q+1, s=k-Q*(Q+1)/2-1;
    for (ll i=n-1;i>=0;i--){
      if (i==f||i==s)cout<<'b';
      else cout<<'a';
    }
    cout<<'\n';
  }
}
