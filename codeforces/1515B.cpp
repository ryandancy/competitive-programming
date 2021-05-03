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
    ll n;
    cin>>n;
    if (n%2==0) {
      ll s=(ll)sqrtl((ld)(n/2));
      if (s*s==n/2) {cout<<"YES\n"; continue;}
    }
    if (n%4==0) {
      ll s=(ll)sqrtl((ld)(n/4));
      if (s*s==n/4) {cout<<"YES\n";continue;}
    }
    cout<<"NO\n";
  }
}
