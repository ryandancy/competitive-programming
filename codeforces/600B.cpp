// 600B - Queries about less or equal elements
// Solved in ~3 minutes, no WAs (woot!)
// Sort a, then binary search for each element in b - O(m log n)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200000], b[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a, a+n);
  for (int i = 0; i < m; i++) {
    cout << upper_bound(a, a+n, b[i])-a << " ";
  }
  cout << endl;
}
