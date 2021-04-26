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
ll a[200000],n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll t;
  cin>>t;
  while (t--) {
    cin>>n;
    for (ll i=0;i<n;i++)cin>>a[i];
    ll ca=a[0];
    for (ll i=0;i<n;i++)ca&=a[i];
    ll c=0;
    for (ll i=0;i<n;i++)if(a[i]==ca)c++;
    ll f=1;
    for (ll i=1;i<=n-2;i++) {
      f*=i;
      f%=MOD;
    }
    f%=MOD;
    f+=MOD;
    f%=MOD;
    ll x=c*(c-1);
    x%=MOD;
    ll r=x*f;
    r%=MOD;
    r+=MOD;
    r%=MOD;
    cout<<r<<'\n';
  }
}
