// 1287A - Angry Students
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int k;
    cin >> k;
    string s;
    cin >> s;
    int bs = 0;
    int af=0; bool st=false;
    for (int i = 0; i < k; i++) {
      if (s[i] == 'A') {
        if (af>bs) bs = af;
        st = true;
        af = 0;
      } else if (st) {
        af++;
      }
    }
    if (af>bs) bs=af;
    cout << bs << '\n';
  }
}
