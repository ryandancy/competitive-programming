// 1050 - To the Max
// For each row, sum each contiguous block of cells for O(n^3). Then
// do O(n) DP on each of the O(n^2) columns of blocks for O(n^3).
#include <iostream>
#include <cstdio>
#define INF 1000000000
using namespace std;
int S[100][100][100], a[100][100], n, dp[100];
int g(int *s) {
  int res=s[0];
  dp[0]=s[0];
  for (int i=1;i<n;i++) {
    dp[i]=max(dp[i-1],0)+s[i];
    res=max(res,dp[i]);
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) cin>>a[i][j];
  for (int y=0;y<n;y++) for (int i=0;i<n;i++) {
    S[i][i][y]=a[i][y];
    for (int j=i+1;j<n;j++) S[i][j][y]=S[i][j-1][y]+a[j][y];
  }
  int mx=-INF;
  for (int i=0;i<n;i++) for (int j=i;j<n;j++) mx=max(mx, g(S[i][j]));
  cout<<mx<<'\n';
}

