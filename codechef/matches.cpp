// MATCHES - Playing with Matches
// Written during Codechef September Cook-Off 2019
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
    int a, b;
    cin >> a >> b;
    int c = a + b, n=0;
    while (c) {
      switch(c%10) {
        case 0: n += 6; break;
        case 1: n += 2; break;
        case 2: n += 5; break;
        case 3: n += 5; break;
        case 4: n += 4; break;
        case 5: n += 5  ; break;
        case 6: n += 6; break;
        case 7: n += 3; break;
        case 8: n += 7; break;
        case 9: n += 6; break;
      }
      c /= 10;
    }
    cout << n << "\n";
  }
}
