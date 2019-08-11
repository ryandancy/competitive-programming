// 1200D - White Lines
// O((n-k+1)^2) processing, O(n^2) preprocessing, overall O(n^2)
// This was NOT created during the contest

#include <iostream>

using namespace std;

int arr[2000][2000];
int psums[2][2000][2000]; // prefix sums; 0=row, 1=col
int dp[2][2000][2000]; // top-left of k square
int run[2][2000][2000]; // individual runs/lengths of cells memoization; top/left

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, k;
  cin >> n >> k;
  
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < n; j++) {
      arr[i][j] = (s[j] == 'B');
    }
  }
  
  // preprocess prefix sums - two O(n^2) phases
  int base[] = {0, 0};
  for (int r = 0; r < n; r++) {
    psums[0][r][0] = arr[r][0];
    for (int c = 1; c < n; c++) {
      psums[0][r][c] = psums[0][r][c-1] + arr[r][c];
    }
    if (psums[0][r][n-1] == 0) base[0]++;
  }
  for (int c = 0; c < n; c++) {
    psums[1][0][c] = arr[0][c];
    for (int r = 1; r < n; r++) {
      psums[1][r][c] = psums[1][r-1][c] + arr[r][c];
    }
    if (psums[1][n-1][c] == 0) base[1]++;
  }
  
  // rows DP - first special (0, 0), then top row, then others
  dp[0][0][0] = base[0]; // special (0, 0)
  for (int r = 0; r < k; r++) {
    run[0][r][0] = (psums[0][r][k-1] >= psums[0][r][n-1] && psums[0][r][n-1] > 0);
    dp[0][0][0] += run[0][r][0];
  }
  for (int c = 1; c <= n-k; c++) { // top row
    dp[0][0][c] = base[0];
    for (int r = 0; r < k; r++) {
      run[0][r][c] = (psums[0][r][c+k-1] - psums[0][r][c-1] >= psums[0][r][n-1] && psums[0][r][n-1] > 0);
      dp[0][0][c] += run[0][r][c];
    }
  }
  for (int r = 1; r <= n-k; r++) { // rest
    for (int c = 0; c <= n-k; c++) {
      run[0][r+k-1][c] = (psums[0][r+k-1][c+k-1] - psums[0][r+k-1][c-1] >= psums[0][r+k-1][n-1]
        && psums[0][r+k-1][n-1] > 0);
      dp[0][r][c] = dp[0][r-1][c] - run[0][r-1][c] + run[0][r+k-1][c];
    }
  }
  
  // cols DP - similar
  dp[1][0][0] = base[1]; // special (0, 0)
  for (int c = 0; c < k; c++) {
    run[1][0][c] = (psums[1][k-1][c] >= psums[1][n-1][c] && psums[1][n-1][c] > 0);
    dp[1][0][0] += run[1][0][c];
  }
  for (int r = 1; r <= n-k; r++) { // left col
    dp[1][r][0] = base[1];
    for (int c = 0; c < k; c++) {
      run[1][r][c] = (psums[1][r+k-1][c] - psums[1][r-1][c] >= psums[1][n-1][c] && psums[1][n-1][c] > 0);
      dp[1][r][0] += run[1][r][c];
    }
  }
  for (int c = 1; c <= n-k; c++) { // rest
    for (int r = 0; r <= n-k; r++) {
      run[1][r][c+k-1] = (psums[1][r+k-1][c+k-1] - psums[1][r-1][c+k-1] >= psums[1][n-1][c+k-1]
        && psums[1][n-1][c+k-1] > 0);
      dp[1][r][c] = dp[1][r][c-1] - run[1][r][c-1] + run[1][r][c+k-1];
    }
  }
  
  // find best row dp + col dp
  int best = 0;
  for (int r = 0; r <= n-k; r++) {
    for (int c = 0; c <= n-k; c++) {
      best = max(best, dp[0][r][c] + dp[1][r][c]);
    }
  }
  
  cout << best << "\n";
}
