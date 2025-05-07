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
ll a[100001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll T=0;
  cin>>T;
  while (T--) {
    ll n,k;
    cin>>n>>k;
    for (ll i=0;i<n;i++) cin>>a[i];
    ll mn=a[0],mx=a[0],nmx=1;
    ll p=a[0]%2;
    for (ll i=1;i<n;i++) {
      if (a[i]<mn) mn=a[i];
      if (a[i]>mx) mx=a[i],nmx=0;
      if (a[i]==mx) nmx++;
      p += a[i];
      p %= 2;
    }
    ll s=mx-mn;
    if (s>k+1 || (s==k+1 && nmx > 1)) {
      cout<<"Jerry\n";
    } else if (p==0) {
      cout<<"Jerry\n";
    } else {
      cout<<"Tom\n";
    }
  }
}
