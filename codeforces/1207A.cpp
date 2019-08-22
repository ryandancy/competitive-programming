// 1207A - There Are Two Types Of Burgers
// Written during Codeforces Educational Round #71
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int b, p, f, h, c;
    cin >> b >> p >> f >> h >> c;
    int ans =0;
    if (h>c) {
      int r = min(p, b/2);
      ans += r*h;
      b -= r*2;
      ans += c*min(f, b/2);
    } else {
      int r = min(f, b/2);
      ans += r*c;
      b -= r*2;
      ans += h*min(p, b/2);
    }
    cout << ans << "\n";
  }
}
