// 1196B - Odd Segments
// We don't care about the actual values of each element; we only care about whether they are even or odd.
// Then, this problem reduces to finding whether it is possible to group the elements into k groups such
// that there are an odd number of odd numbers in each group. If t is the number of odd elements, this
// can only be done if t >= k and t-k+1 is odd, since an optimal strategy for grouping the elements is
// to choose the first odd element in sequence each time until the last grouping (at which point, to comply
// with the problem statement, we choose the last element).
#include <bits/stdc++.h>
using namespace std;
bool arr[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int idx = 0;
  int Q;
  cin >> Q;
  while (Q--) {
    int t = 0;
    int n, k, e;
    cin >> n >> k;
    for (int i = idx; i < idx+n; i++) {
      cin >> e;
      arr[i] = (e % 2 == 1);
      if (e % 2) t++;
    }
    if (t-k+1 <= 0 || (t-k+1) % 2 == 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (int i = idx, c = 0; i < idx+n && c < k-1; i++) {
        if (arr[i]) {
          cout << i-idx+1 << ' ';
          c++;
        }
      }
      cout << n << '\n';
    }
    idx += n;
  }
}
