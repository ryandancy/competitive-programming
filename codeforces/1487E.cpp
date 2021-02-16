#include <bits/stdc++.h>
#define INF 1000000000000
using namespace std;
typedef long long ll;
ll n[4],a[4][150000],dp[4][150000],sp[4][150000];
vector<int> pr[4][200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i=0;i<4;i++)cin>>n[i];
  for (int i=0;i<4;i++) {
    for (int j=0;j<n[i];j++) {
      cin>>a[i][j];
      sp[i][j]=j;
    }
  }
  for (int i=1;i<4;i++) {
    int m;
    cin>>m;
    while (m--) {
      int x,y;
      cin>>x>>y;
      x--,y--;
      pr[i][y].push_back(x);
    }
  }
  for (int i=1;i<4;i++) for (int j=0;j<n[i];j++) sort(pr[i][j].begin(),pr[i][j].end());
  for (int i=0;i<n[0];i++)dp[0][i]=a[0][i];
  for (int i=1;i<4;i++) {
    sort(sp[i-1],sp[i-1]+n[i-1],[&](ll x, ll y){
      return dp[i-1][x]<dp[i-1][y];
    });
    for (int j=0;j<n[i];j++) {
      ll k=0;
      for (;k<n[i-1]&&binary_search(pr[i][j].begin(),pr[i][j].end(),sp[i-1][k]);k++);
      if (k==n[i-1]) dp[i][j]=INF;
      else dp[i][j]=dp[i-1][sp[i-1][k]]+a[i][j];
    }
  }
  ll bst=INF;
  for (int i=0;i<n[3];i++) if (dp[3][i]<bst)bst=dp[3][i];
  if (bst>=INF) cout<<"-1\n";
  else cout<<bst<<'\n';
}
