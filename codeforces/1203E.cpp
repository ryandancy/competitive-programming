// 1203E - Boxers
// Rewrite of a (failing) version written during the contest
#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define ll long long
using namespace std;
int c[150002] = {0};
bool mvd[150002] = {false};
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, e, res = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> e;
    c[e]++;
    if (c[e] == 1) res++;
  }
  for (int x = 3; x >= 2; x--) {
    for (int i = (x == 3) ? 1 : 2; i <= 150000; i++) {
      if (x == 3 ? (i > 1 ? c[i] < 3 : c[i] < 2) : (c[i] != 2)) continue;
      mvd[i] = true;
      int j;
      bool didup = false;
      for (j = i-1; c[j]==1 && !mvd[j] && j > 0; j--);
      if (j > 0 && !mvd[j] && c[j] == 0) {
        for (int k = j; k < i; k++) mvd[k] = true;
        res++;
        didup=true;
      }
      if (!didup || x == 3) {
        for (j = i+1; c[j]==1&&!mvd[j]&&j<=150001;j++);
        if (j<=150001 && !mvd[j] && c[j]==0) {
          for (int k = i+1; k <= j; k++) mvd[k] = true;
          res++;
        }
      }
    }
  }
  cout << res << endl;
}
