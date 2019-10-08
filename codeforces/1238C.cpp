// 1238C - Standard Free2play
// This took way too long (>1h!)
// Written during Codeforces Educational Round #74
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
int a[200000], o=0;
int k[200001] = {0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int q;
  cin >> q;
  while (q--) {
    int h, n;
    cin >> h >> n;
    for (int i = o; i < o+n; i++) {
      cin >> a[i];
    }
    int i = o+n-1, l = 0;
    if (l == 0 && a[i] == 1) {
      while (a[i] == l+1 && i >= o) {
        k[i] = 0;
        l = a[i];
        i--;
      }
    }
    k[i] = 0;
    i--;
    int ccb = 0;
    while (i >= o) {
      l = i==o+n-1 ? 0 : a[i+1];
      while (a[i] == l+1 && i >= o) { // segfault should be ok, but if not maybe here
        k[i] = ccb + !(k[i+1]-ccb);
        l = i==o+n-1 ? 0 : a[i+1];
        i--;
      }
      if (i < o) break;
      if (k[i+1] == ccb) {
        ccb++;
      }
      k[i] = ccb;
      i--;
    }
    cout << k[o] << "\n";
    o += n;
  }
}
