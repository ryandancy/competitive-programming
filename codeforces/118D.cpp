// 118D - Caesar's Legions
// The problem of how many arrangements there are with n1 footmen and n2 horsemen
// is equivalent to the classic DP problem of how many paths there are from (0, 0)
// to (n0, n1) moving only down or right, with moving right representing a footman
// and moving down representing a horseman. We store separately the number of paths
// ending at each node with each consecutive number of down/right moves.
// Time complexity: O(n0n1(k0+k1))
#include <bits/stdc++.h>
#define MOD 100000000
using namespace std;
int dp[101][101][2][11] = {{{{0}}}}; // dp[# footmen][# horsemen][0=right, 1=down][# consecutive] = # paths
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n0, n1, k0, k1;
  cin >> n0 >> n1 >> k0 >> k1;
  for (int i0 = 1; i0 <= k0; i0++) {
    dp[i0][0][0][i0] = 1;
  }
  for (int i1 = 1; i1 <= k1; i1++) {
    dp[0][i1][1][i1] = 1;
  }
  for (int i0 = 1; i0 <= n0; i0++) {
    for (int i1 = 1; i1 <= n1; i1++) {
      for (int j = 1; j <= k0; j++) {
        dp[i0][i1][1][1] += dp[i0][i1-1][0][j];
        dp[i0][i1][1][1] %= MOD;
        if (j < k0) {
          dp[i0][i1][0][j+1] += dp[i0-1][i1][0][j];
          dp[i0][i1][0][j+1] %= MOD;
        }
      }
      for (int j = 1; j <= k1; j++) {
        dp[i0][i1][0][1] += dp[i0-1][i1][1][j];
        dp[i0][i1][0][1] %= MOD;
        if (j < k1) {
          dp[i0][i1][1][j+1] += dp[i0][i1-1][0][j];
          dp[i0][i1][1][j+1] %= MOD;
        }
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= k0; i++) {
    res += dp[n0][n1][0][i];
    res %= MOD;
  }
  for (int i = 1; i <= k1; i++) {
    res += dp[n0][n1][1][i];
    res %= MOD;
  }
  cout << res << "\n";
}