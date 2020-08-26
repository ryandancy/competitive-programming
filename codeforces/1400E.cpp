#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
int a[5001]={0}; int nr=0;
int rd(int l, int r) { //[l,r]
  nr++;
  int mn=INF;
  for (int i=l;i<=r;i++) {
    if (a[i]<mn)mn=a[i];
  }
  for (int i=l;i<=r;i++) {
    a[i]-=mn;
  }
  int ans=mn;
  for (int i=l;i<=r;) {
    while (i<=r&&!a[i])i++;
    int j=i;
    while (j<=r&&a[j])j++;
    if (i<j) ans+=rd(i,j-1);
    i=j;
  }
  return min(ans,r-l+1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  for (int i=0;i<n;i++)cin>>a[i];
  int ans=0;
  for (int i=0;i<n;) {
    while (i<n&&!a[i])i++;
    int j=i;
    while (j<n&&a[j])j++;
    if (i<j) ans+=rd(i,j-1);
    i=j;
  }
  cout<<ans<<'\n';
}
