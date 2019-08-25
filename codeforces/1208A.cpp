// 1208A - XORinacci
// Since (a^b)^a = b, the pattern repeats endlessly as a, b, a^b, a, b, a^b, ...
// Written during Manthan Codefest '19
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin >> T;
  while (T--) {
    int a, b, n;
    cin >> a >> b >> n;
    if (n%3==0) cout << a;
    else if (n%3==1) cout << b;
    else cout << (a^b);
    cout << "\n";
  }
}
