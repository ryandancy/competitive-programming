#include <bits/stdc++.h>
using namespace std;
int a[5][1000];
bool aft[1000][1000];
int dp[1000]={0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin>>n>>k;
  for (int i=0;i<k;i++){
    for (int j=0;j<n;j++)cin>>a[i][j],a[i][j]--;
  }
  for (int q=0;q<k;q++){
    for (int i=0;i<n;i++){
      for (int j=0;j<i;j++){
        aft[a[q][i]][a[q][j]]=true;
      }
    }
  }
  int mx=0;
  for (int i=0;i<n;i++){
    int v=a[0][i];
    dp[v]=1;
    int q=0;
    for (int j=0;j<i;j++){
      int x=a[0][j];
      if (!aft[x][v]){
        q=max(q,dp[x]);
      }
    }
    dp[v]+=q;
    mx=max(mx,dp[v]);
  }
  cout<<mx<<'\n';
}
