// 11173 - Grey Codes
// The k'th reflected grey code is k xor k>>1.
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, _;
  cin >> N;
  while (N--) {
    int k;
    cin >> _ >> k;
    cout << (k^(k>>1)) << '\n';
  }
}
