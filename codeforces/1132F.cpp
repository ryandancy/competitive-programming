#include <bits/stdc++.h>
using namespace std;
int dp[500][500]={{0}};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n; string os;
  cin>>n>>os; n=os.size();
  string s;
  for (int i=0;i<n;){
    char c=os[i];
    s+=c;
    while (os[i]==c) i++;
  }
  n=s.size();
  for (int d=1;d<=n;d++) {
    for (int i=0;i<=n-d;i++) {
      int j=i+d-1;
      if (i==j) {dp[i][j]=1; continue;}
      dp[i][j]=min(dp[i][j-1], dp[i+1][j])+1;
      if (s[i]==s[j]) dp[i][j]=min(dp[i][j], dp[i+1][j-1]+1);
      for (int k=i;k<j;k++){
        dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]-(s[k]==s[i]&&s[k]==s[j]));
      }
    }
  }
  cout<<dp[0][n-1]<<'\n';
}
