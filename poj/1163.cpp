#include <iostream>
#include <cstdio>
using namespace std;
int tr[100][100], dp[100][100]={{0}};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  for (int i=0;i<n;i++){
    for (int j=0;j<=i;j++){
      scanf("%d", &tr[i][j]);
    }
  }
  dp[0][0]=tr[0][0];
  for (int i=1;i<n;i++){
    for (int j=0;j<=i;j++){
      dp[i][j]=max(dp[i-1][j], j>0?dp[i-1][j-1]:0)+tr[i][j];
    }
  }
  int mx=dp[n-1][0];
  for (int i=1;i<n;i++){
    mx=max(mx, dp[n-1][i]);
  }
  printf("%d\n", mx);
}
