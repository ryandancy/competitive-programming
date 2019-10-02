// PARTY - Party Schedule
// Modified 0-1 knapsack DP - O(Bn) where B is budget, n is number of parties
// We *could* make it slightly more efficient by binary searching the best result
// at the end (since dp[p][n] is nondecreasing for increasing p), but that's unnecessary

#include <iostream>

using namespace std;

int fees[100];
int fun[100];
int dp[501][101]; // dp[total fee][first p parties] = max fun

int main() {
  int limit, n;
  while (1) {
    cin >> limit >> n;
    if (limit == 0 && n == 0) break;
    
    for (int i = 0; i < n; i++) {
      cin >> fees[i] >> fun[i];
    }
    
    for (int i = 0; i <= 500; i++) dp[i][0] = 0;
    fill_n(dp[0], 101, 0);
    
    int best = 0;
    for (int p = 0; p < n; p++) {
      for (int fee = 1; fee <= limit; fee++) {
        dp[fee][p+1] = dp[fee][p];
        if (fee >= fees[p]) {
          dp[fee][p+1] = max(dp[fee][p+1], dp[fee-fees[p]][p] + fun[p]);
        }
        if (p+1 == n && dp[fee][n] > dp[best][n]) {
          best = fee;
        }
      }
    }
    
    cout << best << " " << dp[best][n] << endl;
  }
}
