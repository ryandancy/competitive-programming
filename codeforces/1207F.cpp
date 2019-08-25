// 1207F - Remainder Problem
// Square-root heuristics: if x < sqrt(500000), it's faster to store and generate all the answers in O(sqrt N) time;
// if x > sqrt(500000), its faster to naively calculate the answer in O(sqrt N) time. Overall complexity: O(q sqrt N).
#include <bits/stdc++.h>
#define HEUR 708
using namespace std;
typedef long long ll;
int ans[HEUR][HEUR] = {{0}};
int arr[500001] = {0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  int t, x, y;
  while (q--) {
    cin >> t >> x >> y;
    if (t == 1) {
       arr[x] += y;
       for (int m = 1; m < HEUR; m++) {
         ans[m][x%m] += y;
       }
    } else {
      if (x >= HEUR) {
        int res = 0;
        for (int a = y; a <= 500000; a += x) {
          res += arr[a];
        }
        cout << res << "\n";
      } else {
        cout << ans[x][y] << "\n";
      }
    }
  }
}
