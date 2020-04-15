// 1337B - Kana and Dragon Quest game
// Overkill DP preprocessing lol, could have just calculated it.
#include <bits/stdc++.h>
using namespace std;
bool dp[100010][31][31];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i=0;i<31;i++)for (int j=0;j<31;j++)dp[0][i][j]=true;
  for (int h=1;h<=100000;h++){
    for (int v=0;v<31;v++){
      for (int l=0;l<31;l++){
        if (v==0&&l==0)dp[h][v][l]=false;
        else {
          if (h/2+10<h&&v>0&&dp[h/2+10][v-1][l])dp[h][v][l]=true;
          else if (l>0&&(h<=10||dp[h-10][v][l-1]))dp[h][v][l]=true;
          else dp[h][v][l]=false;
        }
      }
    }
  }
  int t;
  cin>>t;
  while (t--){
    int x, n, m;
    cin>>x>>n>>m;
    cout<<(dp[x][n][m]?"YES\n":"NO\n");
  }
}
