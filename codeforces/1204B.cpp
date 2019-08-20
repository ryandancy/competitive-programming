// 1204B - Mislove Has Lost an Array
// Note that the minimal solution is always [1, 1, 1, ..., 2, 4, 8, ..., 2^(l-1)] with l-1 elements greater than 1,
// and the maximal solution is always [1, 2, 4, 8, ..., 2^(r-1), 2^(r-1)] with r-1 elements less than 1.
// Written during Codeforces Round #581 (Div. 2).
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n, l, r;
  cin >> n >> l >> r;
  int mn = n-l+1;
  for (int x = 1, a = 2; x < l; x++, a *= 2) {
    mn += a;
  }
  int mx = 0, x = 1;
  for (int i = 0; i < n; i++) {
    mx += x;
    if (i < r-1) x *= 2;
  }
  cout << mn << ' ' << mx << '\n';
}
