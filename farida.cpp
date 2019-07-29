// FARIDA - Princess Farida
// Simple dynamic programming

#include <iostream>

using namespace std;

long long dp[10001];
long long arr[10000];

int main() {
  int T, N;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }
    
    dp[0] = 0;
    dp[1] = arr[0];
    for (int i = 1; i < N; i++) {
      dp[i+1] = max(dp[i], dp[i-1] + arr[i]);
    }
    
    cout << "Case " << t << ": " << dp[N] << endl;
  }
}
