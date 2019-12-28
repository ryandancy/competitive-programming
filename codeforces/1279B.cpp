#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000001
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
ll a[100000], o=0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    ll n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> a[o+i];
    ll m = 0, to = 0, si = -1;
    int i;
    for (i = o; i < o+n; i++) {
      to += a[i];
      if (a[i] > m) m = a[i], si = i;
      if (to > s) {
        to -= a[i];
        break;
      }
    }
    if (i == o+n) {cout << 0 << '\n'; goto nxt;}
    // to -= m;
    // for (; i < o+n; i++) {
    //   to += a[i];
    //   if (to > s) {
    //     to -= a[i];
    //     break;
    //   }
    // }
    cout << si - o + 1 << '\n';
    nxt:;
    o += n;
  }
}
