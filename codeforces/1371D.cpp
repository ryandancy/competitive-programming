#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
int a[300][300];
void d(int n,int k,int&i, int p, bool sc){
  if (i>=k)return;
  int x=sc?p:0,y=sc?0:p;
  for (int j=p;j<n&&i<k;j++,i++){
    a[x++][y++]++;
  }
}
void q(int n,int k){
  int i=0;
  d(n,k,i,0,false);
  for (int j=1;i<k;j++){
    d(n,k,i,j,true);
    d(n,k,i,n-j,false);
    d(n,k,i,j,false);
    d(n,k,i,n-j,true);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin>>T;
  while (T--) {
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)for (int j=0;j<n;j++)a[i][j]=0;
    q(n,k);
    int mxr=-1,mnr=INF,mxc=-1,mnc=INF;
    for (int i=0;i<n;i++){
      int r=0,c=0;
      for (int j=0;j<n;j++){
        c+=a[i][j];
        r+=a[j][i];
      }
      mxr=max(mxr,r);
      mnr=min(mnr,r);
      mxc=max(mxc,c);
      mnc=min(mnc,c);
    }
    cout<<(mxr-mnr)*(mxr-mnr)+(mxc-mnc)*(mxc-mnc)<<'\n';
    for (int i=0;i<n;i++){
      for (int j=0;j<n;j++){
        cout<<a[i][j];
      }
      cout<<'\n';
    }
  }
}
