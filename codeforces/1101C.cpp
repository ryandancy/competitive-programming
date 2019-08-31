// 1101C - Division and Union
// We sort the intervals by left edge. We then iterate through the intervals and if at any point (with idx > 1)
// the current left edge is strictly greater than the largest right edge thus seen, the intervals before and
// after this point do not overlap and we can safely switch from outputting 1 to outputting 2. We also save time
// by performing all test cases in the same array and updating an offset value. O(n log n) due to sorting.
#include <bits/stdc++.h>
using namespace std;
struct ival {
  int l, r, idx;
};
bool cmp(ival& a, ival& b) {
  return a.l == b.l ? a.r < b.r : a.l < b.l;
}
ival s[200000];
int ans[200000];
int o = 0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T, n, l, r;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = o; i < o+n; i++) {
      cin >> l >> r;
      s[i] = {l, r, i};
    }
    sort(s+o, s+o+n, cmp);
    int mxr = s[o].r, a = 1;
    ans[s[o].idx] = 1;
    for (int i = o+1; i < o+n; i++) {
      if (s[i].l > mxr) {
        a = 2;
      } else {
        mxr = max(mxr, s[i].r);
      }
      ans[s[i].idx] = a;
    }
    if (a == 1) cout << "-1";
    else for (int i = o; i < o+n; i++) {
      cout << ans[i];
      if (i < o+n-1) cout << ' ';
    }
    cout << '\n';
    o += n;
  }
}
