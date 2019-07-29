// TRT - Treats for the Cows

#include <iostream>
#include <utility>

using namespace std;

int vals[2000];
int dp[2000][2000]; // dp[size][l] -> max val for range l..l+size; ans is dp[N-1][0]

int maxrev(int N) {
  // initialize
  for (int i = 0; i < N; i++) {
    dp[0][i] = N*vals[i];
  }
  
  // fill in dp array
  for (int size = 1; size < N; size++) {
    for (int l = 0; l < N - size; l++) {
      dp[size][l] = max(
        dp[size-1][l+1] + (N-size)*vals[l], // choose left
        dp[size-1][l] + (N-size)*vals[l+size] // choose right
      );
    }
  }
  
  return dp[N-1][0];
}

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> vals[i];
  cout << maxrev(N) << endl;
}
