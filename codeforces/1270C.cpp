// 1280C - Make Good
// First, the number of elements doesn't matter, only their sum and XOR.
// We calculate these. Then, if x is the XOR and s is the sum, it suffices
// to output x and s+x. O(n).
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    ll s=0, x=0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      s += a;
      x ^= a;
    }
    if (2*x==s) {cout << "0\n\n"; continue;}
    cout << "2\n" << x << " " << (s+x) << '\n';
  }
}
