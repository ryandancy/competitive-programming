// Z-algorithm
#include <bits/stdc++.h>
using namespace std;
int dp[5001], z[5000][5000]={{0}}, mxz[5000]={0};
void zalg(string& s, int z[], int ofs) { // len(z) >= len(s); ofs is offset
  int n=s.size();
  z[ofs]=0;
  int x=0, y=0;
  for (int i=1;i<n;i++) {
    z[ofs+i]=max(0,min(z[ofs+i-x],y-i+1));
    while (i+z[ofs+i]<n && s[z[ofs+i]]==s[i+z[ofs+i]]) {
      x=i; y=i+z[ofs+i]; z[ofs+i]++;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  cin>>n>>a>>b;
  string s;
  cin>>s;
  n=s.size();
  string ns=s;
  for (int i=0;i<n;i++){
    zalg(ns, z[i], i);
    ns=ns.substr(1);
  }
  for (int i=0;i<n;i++){
    for (int j=i+1;j<n;j++){
      mxz[j]=max(mxz[j],min(z[i][j],j-i));
    }
  }
  dp[0]=a;
  for (int i=1;i<n;i++){
    dp[i]=dp[i-1]+a;
    for (int j=1;j<=i;j++){
      if (mxz[j]>=i-j+1){
        dp[i]=min(dp[i],dp[j-1]+b);
      }
    }
  }
  cout<<dp[n-1]<<'\n';
}
