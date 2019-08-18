// RICHSTR - Rich Substrings
// Written during August Cook-Off 2019
#include <bits/stdc++.h>
using namespace std;
int ts[100000];
int bit[100001];
int bit_sum(int x) {
  int res = 0;
  while (x > 0) {
    res += bit[x];
    x -= x&-x;
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int N, Q;
    cin >> N >> Q;
    if (N < 3) {
      string ta;
      cin >> ta;
      int x, y;
      while (Q--) { cin >> x >> y; cout << "NO\n"; }
      continue;
    }
    fill_n(ts, 100000, 0);
    fill_n(bit, 100001, 0);
    char a, b, c;
    cin.ignore(256, '\n');
    cin.get(a); cin.get(b);
    for (int i = 2; i < N; i++) {
      cin.get(c);
      ts[i-2] = (a == b || b == c || a == c);
      a = b;
      b = c;
    }
    for (int i = 1; i <= N-2; i += 2) {
      bit[i] = ts[i-1];
    }
    for (int k = 2; k <= N; k *= 2) {
      for (int i = k; i <= N-2; i += 2*k) {
        bit[i] = bit_sum(i-1) + ts[i-1];
      }
    }
    int l, r;
    while (Q--) {
      cin >> l >> r;
      if (r-l < 2) {
        cout << "NO\n";
        continue;
      }
      if (bit_sum(r-2) - bit_sum(l-1) > 0) {
        cout << "YES\n";
      } else cout << "NO\n";
    }
  }
}
