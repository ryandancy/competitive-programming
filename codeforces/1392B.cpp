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
ll a[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin>>T;
  while (T--) {
    ll n, k;
    cin>>n>>k;
    for (int i=0;i<n;i++)cin>>a[i];
    ll m=a[0], x=a[0];
    for (int i=0;i<n;i++) {
      if (a[i]>x)x=a[i];
      if (a[i]<m)m=a[i];
    }
    k--;
    for (int i=0;i<n;i++) {
      a[i]=x-a[i];
    }
    ll d=x-m;
    if (k%2) {
      for (int i=0;i<n;i++) {
        a[i]=d-a[i];
      }
    }
    for (int i=0;i<n;i++) {
      cout<<a[i]<<(i==n-1?'\n':' ');
    }
  }
}
