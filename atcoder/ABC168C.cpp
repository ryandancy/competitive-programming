#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifndef DEBUG
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
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  ld a, b, h, m;
  cin>>a>>b>>h>>m;
  ld p1=2.0l*PI*(h*60.0l+m)/720.0l, p2=2.0l*PI*m/60.0l;
  cout<<setprecision(30)<<sqrtl(a*a+b*b-2.0l*a*b*cosl(p1-p2))<<'\n';
  return 0;
}
