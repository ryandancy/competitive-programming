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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll t;
  cin>>t;
  array<ll, 200000> a;
  while (t--) {
    ll n,k;
    cin>>n>>k;
    for (ll i=0;i<n;i++) {
      cin>>a[i];
    }
    ll l=k/2+k%2;
    ll r=k/2;
    ll ans=0;
    for (ll i=0;l>0&&i<n;i++) {
      ll ta=min(a[i],l);
      a[i]-=ta;
      l -= ta;
      if (a[i]==0&&ta>0) ans++;
    }
    for (ll i=n-1;r>0&&i>=0;i--) {
      ll ta=min(a[i],r);
      a[i]-=ta;
      r -= ta;
      if (a[i]==0&&ta>0) ans++;
    }
    cout<<ans<<'\n';
  }
}
