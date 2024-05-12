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
  string s;
  cin>>t;
  while (t--) {
    ll n;
    cin>>n;
    cin>>s;
    ll mn=INF;
    for (ll x=1;x*x<=n;x++) {
      if (n%x) continue;
      ll k=x;
      bool ok=true;
      bool strike=true;
      for (ll o=0;o<k;o++) {
        char g=s[o];
        for (ll i=o+k;i<n;i+=k) {
          if (s[i]!=g) {
            if (strike) strike=false;
            else if (i-2*k==o&&s[i]==s[i-k]) g=s[i];
            else {
              ok=false;
              goto nx;
            }
          }
        }
      }
      nx:;
      if (ok) {
        mn=min(mn,k);
      }
      k=n/x;
      ok=true;
      strike=true;
      for (ll o=0;o<k;o++) {
        char g=s[o];
        for (ll i=o+k;i<n;i+=k) {
          if (s[i]!=g) {
            if (strike) strike=false;
            else if (i-2*k==o&&s[i]==s[i-k]) g=s[i];
            else {
              ok=false;
              goto nx2;
            }
          }
        }
      }
      nx2:;
      if (ok) {
        mn=min(mn,k);
      }
    }
    cout<<mn<<'\n';
  }
}
