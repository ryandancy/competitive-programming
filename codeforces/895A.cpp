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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin>>n;
  int a[360];
  for (int i=0;i<n;i++)cin>>a[i];
  int md=INF;
  for (int sz=0;sz<=n/2;sz++){
    for (int i=0;i<n;i++){
      int cs=0;
      for (int j=0;j<sz;j++){
        cs+=a[(i+j)%n];
      }
      md=min(md,abs(360-2*cs));
    }
  }
  cout<<md<<'\n';
}
