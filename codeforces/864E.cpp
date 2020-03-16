// 864E - Fire
// Dynamic programming, variant of knapsack problem. O(nm) where m is
// the maximum value of d. Important observation: the optimal insertion
// order is in order of increasing d, so we sort by d. We keep track of
// the elements included by keeping a link to the previous DP we used;
// if the time (second dimension) decreases, we used it.
#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
int t[100], d[100], p[100], idx[100], k[100];
int dp[100][2001];
int pdp[100][2001];
bool dcmp(int a,int b){
  return d[a]<d[b];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin>>n;
  for (int i=0,ix=1;i<n;i++,ix++){
    cin>>t[i]>>d[i]>>p[i];
    idx[i]=ix;
    d[i]--;
    if (t[i]>d[i]) {
      i--;n--;
    }
  }
  if (n==0)return cout<<"0\n0\n",0;
  for (int i=0;i<n;i++)k[i]=i;
  sort(k,k+n,dcmp);
  for (int i=0;i<2001;i++) {
    dp[0][i]=t[k[0]]<=i?p[k[0]]:0;
    pdp[0][i]=t[k[0]]<=i?-1:i;
  }
  for (int i=1;i<n;i++){
    for (int j=0;j<2001;j++) {
      dp[i][j]=max(dp[i-1][j], j-t[k[i]]>=0?dp[i-1][min(j,d[k[i]])-t[k[i]]]+p[k[i]]:-INF);
      pdp[i][j]=dp[i-1][j]>(j-t[k[i]]>=0?dp[i-1][min(j,d[k[i]])-t[k[i]]]+p[k[i]]:-INF)?j:min(j,d[k[i]])-t[k[i]];
    }
  }
  cout<<dp[n-1][2000]<<'\n';
  stack<int> s;
  int cd=2000;
  for (int i=n-1;i>=0;i--){
    if (pdp[i][cd]!=cd){
      cd=pdp[i][cd];
      s.push(i);
    }
  }
  cout<<s.size()<<'\n';
  vector<int> x;
  while (!s.empty()) {
    int c=s.top();s.pop();
    cout<<idx[k[c]]<<' ';
  }
  cout<<'\n';
}
