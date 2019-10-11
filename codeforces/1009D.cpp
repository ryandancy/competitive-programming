// 1009D - Relatively Prime Graph
// Simple - we just brute-force allocate them by checking for GCD each time.
// We ensure connectedness by connecting everything to 1 first (since gcd(1, x) = 1).
// If we can't do that, it's impossible.
// O(m) maybe? Fast enough.
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<pii> es;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  if (m < n - 1) {
    return cout << "Impossible\n", 0;
  }
  for (int i = 2; i <= n; i++) {
    es.push_back({1, i});
  }
  for (int a = 2; a < n && es.size() < m; a++) {
    for (int b = a+1; b <= n && es.size() < m; b++) {
      if (gcd(a, b) == 1) {
        es.push_back({a, b});
      }
    }
  }
  if (es.size() < m) {
    return cout << "Impossible\n", 0;
  }
  cout << "Possible\n";
  for (pii& e : es) {
    cout << e.first << " " << e.second << "\n";
  }
}
