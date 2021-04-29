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
ll a[5000],b[5000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n;
  cin>>n;
  for (ll i=0;i<n;i++)cin>>a[i];
  for (ll i=0;i<n;i++)cin>>b[i];
  ll ba=0;
  for (ll i=0;i<n;i++) ba+=a[i]*b[i];
  ll mx=ba;
  for (ll c=0;c<n;c++) {
    ll d=0;
    for (ll w=1;c-w>=0&&c+w<n;w++) {
      ll cu=a[c-w]*b[c-w]+a[c+w]*b[c+w];
      ll nu=a[c-w]*b[c+w]+a[c+w]*b[c-w];
      d+=nu-cu;
      mx=max(mx,ba+d);
    }
  }
  for (ll c=0;c<n-1;c++) {
    ll d=0;
    for (ll w=0;c-w>=0&&c+w+1<n;w++) {
      ll cu=a[c-w]*b[c-w]+a[c+w+1]*b[c+w+1];
      ll nu=a[c-w]*b[c+w+1]+a[c+w+1]*b[c-w];
      d+=nu-cu;
      mx=max(mx,ba+d);
    }
  }
  cout<<mx<<'\n';
}
