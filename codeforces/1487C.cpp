#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while (t--) {
    int n;
    cin>>n;
    int rel[100][100]={{0}};
    int id[100]={0},od[100]={0},td=n%2?(n-1)/2:(n-2)/2;
    for (int i=0;i<n;i++) {
      for (int j=i+1;j<=i+td;j++) {
        int r=j%n;
        rel[i][r]=1;
        rel[r][i]=-1;
        id[i]++;
        od[r]++;
      }
    }
    for (int i=0;i<n;i++) {
      for (int j=i+1;j<n;j++) {
        cout<<rel[i][j];
        if (i==n-2&&j==n-1)cout<<'\n';
        else cout<<' ';
      }
    }
  }
}
