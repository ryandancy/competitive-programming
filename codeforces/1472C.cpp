#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200000],dp[200000],n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin>>T;
  while (T--) {
    cin>>n;
    for (int i=0;i<n;i++)cin>>a[i];
    ll mx=0;
    for (int i=n-1;i>=0;i--) {
      dp[i]=a[i];
      if (i+a[i]<n) dp[i]+=dp[i+a[i]];
      mx=max(mx,dp[i]);
    }
    cout<<mx<<'\n';
  }
}
