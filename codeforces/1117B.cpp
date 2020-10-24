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
  ll n,m,k;
  cin>>n>>m>>k;
  for (int i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  ll res=(a[n-1]*k+a[n-2])*(m/(k+1));
  if (m%(k+1)!=0) {
    res+=a[n-1]*(m%(k+1));
  }
  cout<<res<<'\n';
}
