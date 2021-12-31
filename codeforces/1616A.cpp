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
  while (t--) {
    bool a[500]={false};
    ll b=100;
    ll n;
    cin>>n;
    for (ll i=0;i<n;i++) {
      ll x;
      cin>>x;
      if (a[x+b])a[-x+b]=true;
      else a[x+b]=true; 
    }
    ll c=0;
    for (ll i=0;i<=200;i++) c+=a[i];
    cout<<c<<'\n';
  }
}
