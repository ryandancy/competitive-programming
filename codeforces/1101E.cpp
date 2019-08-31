// 1101E - Polycarp's New Job
// The optimal strategy is to minimize one dimension (we pick height) by rotating any bills
// in which y > x and any wallets in which h > w. O(n).
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n; char t;
  cin >> n;
  int mw = 0, mh = 0;
  while (n--) {
    cin >> t;
    if (t == '+') {
      int x, y;
      cin >> x >> y;
      if (x < y) swap(x, y);
      mw = max(mw, x);
      mh = max(mh, y);
    } else {
      int h, w;
      cin >> h >> w;
      if (w < h) swap(h, w);
      cout << (h >= mh && w >= mw ? "YES" : "NO") << "\n";
    }
  }
}
