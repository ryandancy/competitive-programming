// 1213E - Two Small Strings
#include <bits/stdc++.h>
using namespace std;
char other(string& a) {
  if (a[0] == 'a') return a[1] == 'b' ? 'c' : 'b';
  if (a[0] == 'b') return a[1] == 'a' ? 'c' : 'a';
  return a[1] == 'a' ? 'b' : 'a';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  string a, b;
  cin >> n >> a >> b;
  cout << "YES\n";
  if (a[0] == a[1] || b[0] == b[1]) {
    if (a[0] == a[1] && b[0] == b[1]) {
      string res;
      for (int i = 0; i < n; i++) res += "abc";
      cout << res << "\n";
      return 0;
    }
    string o = (a[0] == a[1]) ? b : a;
    string rep;
    if (o == "ab" || o == "bc" || o == "ca") rep = "acb";
    else rep = "abc";
    string res;
    for (int i = 0; i < n; i++) res += rep;
    cout << res << "\n";
  } else {
    char x, y, z;
    if (a[0] == b[0]) {
      if (a[1] == b[1]) {
        z = a[0], x = a[1], y = other(a);
      } else {
        z = a[0], x = a[1], y = b[1];
      }
    } else if (a[1] == b[1]) {
      x = a[1], y = a[0], z = b[0];
    } else if (a[0] == b[1] && a[1] == b[0]) {
      x = a[0], y = other(a), z = a[1];
    } else if (a[1] == b[0]) {
      x = b[1], y = b[0], z = a[0];
    } else if (a[0] == b[1]) {
      x = a[1], y = a[0], z = b[0];
    } else {
      assert(false);
    }
    string res;
    for (int i = 0; i < n; i++) res += x;
    for (int i = 0; i < n; i++) res += y;
    for (int i = 0; i < n; i++) res += z;
    cout << res << "\n";
  }
}
