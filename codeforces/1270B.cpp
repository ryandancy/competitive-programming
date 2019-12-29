// 1270B - Interesting Subarray
// An interesting subarray will always have two adjacent
// elements that differ by more than 1, making those two
// elements themselves an interesting subarray. We check
// for those in O(n).
#include <bits/stdc++.h>
using namespace std;
int a[200000], o=0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[o+i];
    for (int i = 0; i < n-1; i++) {
      if (abs(a[o+i+1]-a[o+i])>1) {
        cout << "YES\n";
        cout << i+1 << ' ' << i+2 << '\n';
        goto cnt;
      }
    }
    cout << "NO\n";
    cnt:
    o += n;
  }
}
