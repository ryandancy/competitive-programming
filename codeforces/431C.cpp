// 431C - k-Tree
// Though the tree is infinite, the largest number of levels we ever need to search
// is n, since n = 1 + 1 + 1 + ... (n times). We use DP over the levels and the sum
// remaining, taking advantage of the self-similarity of the tree.
// Time complexity: O(kn^2).
// Note: this problem is equivalent to "how many partitions of n are there with
// all addends less than or equal to k and one addend greater than or equal to d". I
// did not realize this until it was too late.
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int dp[101][101][2] = {{{0}}}; // dp[lvl][n][d fulfilled?] = number of paths
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, d;
  cin >> n >> k >> d;
  for (int i = 0; i <= n; i++) {
    dp[i][0][1] = 1;
  }
  for (int i = n-1; i >= 0; i--) {
    for (int x = 1; x <= n; x++) {
      for (int j = 1; j <= min(k, x); j++) {
        dp[i][x][1] += dp[i+1][x-j][1];
        dp[i][x][1] %= MOD;
        if (j >= d) dp[i][x][0] += dp[i+1][x-j][1];
        else dp[i][x][0] += dp[i+1][x-j][0];
        dp[i][x][0] %= MOD;
      }
    }
  }
  cout << dp[0][n][0] << "\n";
}
