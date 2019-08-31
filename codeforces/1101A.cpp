// 1101A - Minimum Integer
// Simple math - if we can we choose the number itself, otherwise we choose the first greater than r. O(1).
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int q;
  cin >> q;
  while (q--) {
    int l, r, d;
    cin >> l >> r >> d;
    if (l > d) {
      cout << d << "\n"; continue;
    }
    cout << (r/d+1)*d << '\n';
  }
}
