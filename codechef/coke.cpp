// COKE - Chef Drinks Coke
// Written during August Cook-Off 2019
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int N, M, K, L, R;
    cin >> N >> M >> K >> L >> R;
    int bp = 1000000000;
    while (N--) {
      int t, p;
      cin >> t >> p;
      if (t-K > M) t -= M;
      else if (K-t > M) t += M;
      else t = K;
      if (L <= t && R >= t) bp = min(bp, p);
    }
    if (bp == 1000000000) cout << "-1\n";
    else cout << bp << "\n";
  }
}
