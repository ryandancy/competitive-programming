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
ll a[300000],n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n;
  for (int i=0;i<n;i++)cin>>a[i];
  ll c[2]={0};
  ll k=0;
  for (int i=0;i<n;i++,k=!k) {
    c[k]+=a[i]/2;
    c[!k]+=a[i]/2+a[i]%2;
  }
  cout<<min(c[0],c[1])<<'\n';
}
