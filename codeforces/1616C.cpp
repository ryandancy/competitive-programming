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

    ll a[70];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll t;
  cin>>t;
  while (t--) {
    ll n;
    cin>>n;
    for (ll i=0;i<n;i++)cin>>a[i];
    if (n<=2) {cout<<"0\n";continue;}
    ll lg=0;
    for (ll i=0;i<n;i++) {
      for (ll j=i+1;j<n;j++) {
        ll c=2;
        ll v=a[j],s=j-i,d=a[j]-a[i];
        ll g=gcd(s,d);
        // debug(s,d,g);
        d/=g;
        s/=g;
        for (ll k=j+s;k<n;k+=s) {
          v+=d;
          if (v==a[k]) c++;
        }
        lg=max(lg,c);
      }
    }
    cout<<n-lg<<'\n';
  }
}
