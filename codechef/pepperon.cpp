// PEPPERON - Chef and Pepperoni Pizza
// Written during August Cook-Off 2019
#include <bits/stdc++.h>
using namespace std;
int h1s[1000], h2s[1000];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    fill_n(h1s, 1000, 0);
    fill_n(h2s, 1000, 0);
    int sh1, sh2;
    sh1 = sh2 = 0;
    int N; char c;
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin.ignore(256, '\n');
      for (int j = 0; j < N/2; j++) {
        cin.get(c);
        if (c=='1') { h1s[i]++; sh1++; }
      }
      for (int j = N/2; j < N; j++) {
        cin.get(c);
        if (c=='1') h2s[i]++, sh2++;
      }
    }
    int bst = abs(sh2-sh1);
    for (int i = 0; i < N; i++) {
      int nsh1 = sh1 - h1s[i] + h2s[i];
      int nsh2 = sh2 - h2s[i] + h1s[i];
      int nb = abs(nsh2-nsh1);
      bst = min(bst, nb);
    }
    cout << bst << "\n";
  }
}
