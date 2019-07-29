// MIXTURES - Mixtures
// Basic O(n^2) DP (much fast enough for n=100)
// For each range in the list defined by left pos and length, we calculate two values:
// the minimum smoke (dp[left][len]) and the colour when that smoke is generated (vals[left][len]).
// To do this we divide the range by a cut value as if we mix to the left, then right, then combine.

#include <iostream>
#define INF 1000000000

using namespace std;

int dp[100][101]; // dp[left][len] -> min smoke
int vals[100][101]; // vals[left][len] -> colour for min smoke

int main() {
  int N;
  while (cin >> N) {
    for (int i = 0; i < N; i++) {
      cin >> vals[i][1];
      dp[i][1] = 0;
    }
    for (int len = 2; len <= N; len++) {
      for (int left = 0; left <= N - len; left++) {
        dp[left][len] = vals[left][len] = INF;
        for (int cut = 1; cut < len; cut++) {
          int smoke = dp[left][cut] + dp[left+cut][len-cut] + vals[left][cut]*vals[left+cut][len-cut];
          if (smoke < dp[left][len]) {
            dp[left][len] = smoke;
            vals[left][len] = (vals[left][cut] + vals[left+cut][len-cut]) % 100;
          }
        }
      }
    }
    cout << dp[0][N] << endl;
  }
}
