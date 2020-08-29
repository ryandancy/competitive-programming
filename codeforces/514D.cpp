#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n,m,k;
int a[100000][5];
set<pii> s[5]; int mx[5]={0};
bool ok() {
  int sm=0;
  for (int i=0;i<m;i++)sm+=mx[i];
  return sm<=k;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m>>k;
  for (int i=0;i<n;i++)for (int j=0;j<m;j++)cin>>a[i][j];
  int l=0,md=0,res[5]={0};
  for (int r=0;r<n;r++) {
    for (int i=0;i<m;i++) {
      s[i].insert({a[r][i],r});
      mx[i]=max(mx[i],a[r][i]);
    }
    while (l<n&&!ok()) {
      if (l>=0) {
        for (int i=0;i<m;i++) {
          s[i].erase({a[l][i],l});
          if (l<r&&a[l][i]==mx[i])mx[i]=(--s[i].end())->first;
          if (l>=r)mx[i]=0;
        }
      }
      l++;
    }
    if (r-l+1>md) {
      md=r-l+1;
      for (int i=0;i<m;i++)res[i]=mx[i];
    }
  }
  for (int i=0;i<m;i++) {
    cout<<res[i]<<(i==m-1?'\n':' ');
  }
}
