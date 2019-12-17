// 910B - Door Frames
// Somewhat overkill - we try literally every single permutation of a and b into bars
// of length n. O(1) because it doesn't depend on a and b, performs maybe 6!^2 operations (very generously).
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
bool ok(int f[], int b, int s, int n) {
  if (s==1) {
    int sm = 0;
    for (int i = b; i < 6; i++) sm += f[i];
    return sm<=n;
  }
  int sm = f[b];
  for (int e = b+1; e <= 6-s; e++) {
    if (ok(f,e,s-1,n)) return true;
    sm += f[e];
    if (sm>n) return false;
  }
  return false; // ?
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n, a, b;
  cin >> n >> a >> b;
  if (4*a+2*b<=n) return cout<<"1\n",0;
  int f[6];
  if (a<b) f[0]=f[1]=f[2]=f[3]=a,f[4]=f[5]=b;
  else f[0]=f[1]=b,f[2]=f[3]=f[4]=f[5]=a;
  for (int s = 2; s < 6; s++) {
    do {
      if (ok(f,0,s,n)) {
        return cout << s << "\n", 0;
      }
    } while(next_permutation(f, f+6));
  }
  cout << "6\n";
}
