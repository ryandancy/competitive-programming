// 891A - Pride
// The optimal algorithm is to get a 1 as quickly as possible, then spread it.
// If we don't start with a 1, we just calculate all the O(n^2) possible GCDs
// we get until we find a 1, then calculate the number of GCDs needed. O(n^2).
#include <bits/stdc++.h>
using namespace std;
int a[2000][2000]={{0}};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  int oc=0;
  for (int i = 0; i < n; i++) {
    cin >> a[0][i];
    if (a[0][i]==1)oc++;
  }
  if (oc>0) {
    cout << n-oc << "\n";
    return 0;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n-i; j++) {
      a[i][j] = gcd(a[i-1][j],a[i-1][j+1]);
      if (a[i][j] == 1) {
        cout << i+n-1 << '\n';
        return 0;
      }
    }
  }
  cout << "-1\n";
}
