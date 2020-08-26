#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int a[3000];
vector<pii> p[3000][3000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while (t--) {
    int n;
    cin>>n;
    for (int i=0;i<n;i++)cin>>a[i],a[i]--;
    for (int i=0;i<n;i++)for (int j=0;j<n;j++)p[i][j].clear();
    for (int i=0;i<n;i++) {
      for (int j=i+1;j<n;j++) {
        p[a[i]][a[j]].push_back({i,j});
      }
    }
    ll res=0;
    pii mp;
    for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++) {
        int m=p[i][j].size();
        if (m==0)continue;
        sort(p[i][j].begin(),p[i][j].end());
        for (int k=0;k<m;k++) {
          mp.first=mp.second=p[i][j][k].second+1;
          mp.second++;
          int r=lower_bound(p[i][j].begin(),p[i][j].end(),mp)-p[i][j].begin();
          res+=m-r;
        }
      }
    }
    cout<<res<<'\n';
  }
}
