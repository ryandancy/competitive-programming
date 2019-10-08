// 1238B - Kill `Em All
// Just always target the rightmost monster, simulate it
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
int a[100000], o=0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int q;
  cin >> q;
  while (q--) {
    int n, r;
    cin >> n >> r;
    for (int i = o; i < n+o; i++) {
      cin >> a[i];
    }
    sort(a+o, a+n+o);
    int s = 0;
    int res = 0;
    int i = n+o-1;
    while (i >= o) {
      if (a[i] <= s) break;
      res++;
      s += r;
      int orig = a[i];
      while (a[i] == orig && i >= o) i--;
    }
    cout << res << "\n";
    o += n;
  }
}
