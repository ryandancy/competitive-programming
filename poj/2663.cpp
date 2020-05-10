// Bitmask DP
#include <iostream>
#include <cstdio>
using namespace std;
int dp[31][8]={{0}};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  dp[0][0]=1;
  for (int i=1;i<=30;i++){
    for (int a=0;a<8;a++){
      for (int b=0;b<8;b++){
        if (a&b) continue;
        int r=0;
        for (int j=0;j<3;j++){
          if ((a&(1<<j))||(b&(1<<j))) {
            if (r%2) break;
            r=0;
          } else r++;
        }
        if (r%2) continue;
        dp[i][a]+=dp[i-1][b];
      }
    }
  }
  int n;
  while (scanf("%d", &n), n!=-1) {
    printf("%d\n", dp[n][0]);
  }
}
