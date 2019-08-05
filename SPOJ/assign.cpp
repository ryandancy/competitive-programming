// ASSIGN - Assignment
// Bitmask DP - O(n * 2^n), works for n <= 20

#include <iostream>

using namespace std;

typedef unsigned long long ll;

int arr[20];
ll dp[1<<21];

int main() {
  int C, N;
  cin >> C;
  for (int c = 0; c < C; c++) {
    cin >> N;
    
    // Load into arr bitmasks
    int cell;
    for (int i = 0; i < N; i++) {
      arr[i] = 0;
      for (int j = 0; j < N; j++) {
        cin >> cell;
        arr[i] |= (cell << j);
      }
    }
    
    fill_n(dp, 1<<N, 0);
    
    // DP to calculate number of assignments
    dp[0] = 1;
    for (int bm = 0; bm < (1<<N) - 1; bm++) {
      int x = __builtin_popcount(bm);
      for (int k = 0; k < N; k++) {
        if ((arr[x] & (1<<k)) && !(bm & (1<<k))) {
          // if we can take the kth bit of arr[x], we add it to the bitmask
          // representing bm + kth bit taken
          dp[bm | (1<<k)] += dp[bm];
        }
      }
    }
    
    cout << dp[(1<<N)-1] << endl;
  }
}
