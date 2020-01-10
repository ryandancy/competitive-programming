// 1194D - 1-2-K Game
// Let a string of L and W denote whether Alice loses or wins,
// respectively, at n = 0-indexed position in the string.
// For k not divisible by 3, the pattern is LWWLWWLWW...
// For k divisible by 3, the pattern is (3*(k/3-1)*"LWW" + "LWWW")
// repeated. Implement this, O(1).
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    if (k % 3) {
      cout << (n%3==0 ? "Bob\n" : "Alice\n");
      continue;
    }
    int nb=k/3;
    n %= 3*(nb-1)+4;
    if (n < 3*(nb-1)) {
      cout << (n%3==0 ? "Bob\n" : "Alice\n");
      continue;
    }
    cout << (n==3*(nb-1) ? "Bob\n" : "Alice\n");
  }
}
