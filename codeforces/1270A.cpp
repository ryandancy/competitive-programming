// 1270A - Card Game
// Simple - whoever has card n wins.
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    for (int i = 0; i < k1; i++) {
      int a;
      cin >> a;
      if (a == n) {
        cout << "YES\n";
      }
    }
    for (int i = 0; i < k2; i++) {
      int a;
      cin >> a;
      if (a == n) {
        cout << "NO\n";
      }
    }
  }
}
