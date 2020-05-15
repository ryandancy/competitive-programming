#include <iostream>
#include <cstdio>
using namespace std;
int *dp[5000];
char s[5000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  scanf("%d %s", &n, s);
  for (int i=0;i<n;i++){
    dp[i]=new int[n-i];
  }
  for (int i=0;i<n;i++) {
    for (int d=0;d<n-i;d++) {
      dp[i][d]=0;
    }
  }
  for (int d=1;d<n;d++){
    for (int i=0;i+d<n;i++){
      if (s[i]==s[i+d]) dp[i][d]=d==1?0:dp[i+1][d-2];
      else dp[i][d]=min(dp[i+1][d-1], dp[i][d-1])+1;
    }
  }
  printf("%d\n", dp[0][n-1]);
  // for (int i=0;i<n;i++){ // if we clean up it TLEs
  //   delete dp[i];
  // }
}
