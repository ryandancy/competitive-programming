// 1206C - Almost Equal
// Written during the contest
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    if (i % 2) cout << 2*i-1;
    else cout << 2*i;
    cout << ' ';
  }
  for (int i = 1; i <= n; i++) {
    if (i % 2) cout << 2*i;
    else cout << 2*i-1;
    if (i != n) cout << ' ';
  }
  cout << '\n';
}
