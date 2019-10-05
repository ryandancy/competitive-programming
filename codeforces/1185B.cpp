// 1185B - Email from Polycarp
// Simple 2 pointers manipulation - O(n)
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  string a, b;
  while (n--) {
    cin >> a >> b;
    int pa, pb;
    pa = pb = 0;
    bool ok = true;
    if (a.size() > b.size()) { ok = false; goto en; }
    while (pa < a.size()) {
      if (pb >= b.size()) { ok = false; goto en; }
      if (a[pa] != b[pb]) {
        ok = false; goto en;
      }
      char ca = a[pa];
      while (ca == a[pa] && pa < a.size() && pb < b.size()) {
        if (ca != b[pb]) { ok = false; goto en; }
        pa++;
        pb++;
      }
      while (ca == b[pb] && pb < b.size()) pb++;
    }
    en:;
    if (pb < b.size()) ok = false;
    cout << (ok ? "YES\n" : "NO\n");
  }
}
