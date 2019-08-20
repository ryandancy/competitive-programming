// 2B - The least round way
// The main problem here is to minimize the number of factors of 10 in the product; that is,
// we must minimize the *minimum* of the factors of 5 and the factors of 2 in the product.
// Thus we run the minimum-weight DP algorithm to find a path from (0, 0) to (n-1, n-1) twice,
// first minimizing the number of factors of 2, then minimizing the number of factors of 5.
// The minimum of the values at (n-1, n-1) of these two DP arrays will yield the minimum number
// of factors of 10. However, there is one special case: values of 0. Passing over a 0-valued
// cell sets the result to 0, which fixes the number of trailing zeroes at 1. To deal with this,
// we avoid 0-valued cells completely in the two DP iterations, but if the answer calculated
// by this is greater than 1 and there exists a 0-valued cell somewhere in the array (found when
// we input the array), we instead output a path that simply moves to the 0-valued cell and then
// to (n-1, n-1). Otherwise, the paths are stored by for each cell in one iteration of the DP
// algorithm, we store a 1 for "the minimum path to here moves down in the last step" and 2
// for "the minimum path to here moves right in the last step". We then use this to reconstruct
// the minimum overall path.

#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int arr[1000][1000];
int mv2[1000][1000]; // 1=down, 2=right
int dp2[1000][1000];
int mv5[1000][1000];
int dp5[1000][1000];
int n;

inline int numfac(int v, int& fac) { // how many times is fac a factor of v?
  if (v == 0) return 0;
  int res = 0;
  while (v % fac == 0) {
    v /= fac;
    res++;
  }
  return res;
}

void dp(int v, int mv[1000][1000], int dp[1000][1000]) {
  mv[0][0] = 0;
  dp[0][0] = numfac(arr[0][0], v);
  for (int y = 1; y < n; y++) {
    mv[y][0] = 1;
    if (arr[y][0] == 0) dp[y][0] = INF;
    else dp[y][0] = dp[y-1][0] + numfac(arr[y][0], v);
  }
  for (int x = 1; x < n; x++) {
    mv[0][x] = 2;
    if (arr[0][x] == 0) dp[0][x] = INF;
    else dp[0][x] = dp[0][x-1] + numfac(arr[0][x], v);
  }
  for (int y = 1; y < n; y++) {
    for (int x = 1; x < n; x++) {
      if (arr[y][x] == 0) dp[y][x] = INF;
      else if (dp[y-1][x] < dp[y][x-1]) {
        mv[y][x] = 1;
        dp[y][x] = dp[y-1][x] + numfac(arr[y][x], v);
      } else {
        mv[y][x] = 2;
        dp[y][x] = dp[y][x-1] + numfac(arr[y][x], v);
      }
    }
  }
}

void follow(int mv[1000][1000]) { // reconstruct the path in mv
  stack<int> mvs;
  int y, x; y = x = n-1;
  while (mv[y][x]) {
    mvs.push(mv[y][x]);
    if (mv[y][x] == 1) y--;
    else x--;
  }
  while (mvs.size()) {
    cout << (mvs.top() == 1 ? 'D' : 'R');
    mvs.pop();
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  bool has0 = false;
  int x0 = -1;
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      cin >> arr[y][x];
      if (arr[y][x] == 0) {
        has0 = true;
        x0 = x;
      }
    }
  }
  
  dp(2, mv2, dp2);
  dp(5, mv5, dp5);
  
  int mn = min(dp2[n-1][n-1], dp5[n-1][n-1]);
  if (mn > 1 && has0) {
    cout << "1\n";
    for (int x = 0; x < x0; x++) cout << 'R';
    for (int y = 0; y < n-1; y++) cout << 'D';
    for (int x = x0; x < n-1; x++) cout << 'R';
    cout << '\n';
  } else {
    cout << mn << "\n";
    if (dp2[n-1][n-1] < dp5[n-1][n-1]) follow(mv2);
    else follow(mv5);
  }
}
