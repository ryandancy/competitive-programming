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
ll a[50000],t[50000],x[50000],r[50000],n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n;
  for (int i=0;i<n;i++)cin>>a[i],x[i]=i;
  for (int i=0;i<n;i++)t[i]=n-a[i]-a[(i+1)%n];
  sort(x,x+n,[&](int q, int w){return t[q]>t[w];});
  for (int i=0;i<n;i++)r[x[i]]=i;
  for (int i=0;i<n;i++)cout<<r[i]<<(i==n-1?'\n':' ');
}
