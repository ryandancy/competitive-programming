// 1206A - Choose Two Numbers
// Written during the contest
#include <bits/stdc++.h>
using namespace std;
int a[100], b[100];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a, a+n); sort(b, b+m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x = a[i]+b[j];
      if (!binary_search(a, a+n, x) && !binary_search(b, b+m, x)) {
        cout << a[i] << ' ' << b[j] << endl;
        return 0;
      }
    }
  }
}
