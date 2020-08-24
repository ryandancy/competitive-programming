// priority queues be SLOW
// use vector arrays when there's a limited number of priorities + they'll never decrease
// O(nm), it's literally just distance in from last border
#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;
int n,m; ll res=0;
char mp[2001][2001];
ll rs[2000][2000]={{0}},prs[2000][2000]={{0}};
vector<int> xv[3000], yv[3000]; int mx=2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  scanf("%d %d\n", &n, &m);
  for (int i=0;i<n;i++)scanf("%s\n",mp[i]);
  for (ll y=0;y<n;y++){
    for (ll x=0;x<m;x++) {
      if (y==0||y==n-1||x==0||x==m-1) {rs[y][x]=1,res++;continue;}
      char c=mp[y][x];
      if (mp[y-1][x]!=c||mp[y+1][x]!=c||mp[y][x-1]!=c||mp[y][x+1]!=c) rs[y][x]=1,res++;
      else prs[y][x]=INF;
    }
  }
  for (ll y=1;y<n-1;y++) {
    for (ll x=1;x<m-1;x++) {
      if (!rs[y][x]&&(rs[y-1][x]==1||rs[y+1][x]==1||rs[y][x-1]==1||rs[y][x+1]==1)) {
        xv[2].push_back(x);
        yv[2].push_back(y);
      }
    }
  }
  for (int r=2;r<=mx;r++) {
    int sz=xv[r].size();
    for (int i=0;i<sz;i++) {
      int x=xv[r][i], y=yv[r][i];
      if (rs[y][x]) continue;
      rs[y][x]=r; res+=r;
      if (!rs[y][x-1]&&r+1<prs[y][x-1])xv[r+1].push_back(x-1),yv[r+1].push_back(y),prs[y][x-1]=r+1,mx=max(mx,r+1);
      if (!rs[y][x+1]&&r+1<prs[y][x+1])xv[r+1].push_back(x+1),yv[r+1].push_back(y),prs[y][x+1]=r+1,mx=max(mx,r+1);
      if (!rs[y-1][x]&&r+1<prs[y-1][x])xv[r+1].push_back(x),yv[r+1].push_back(y-1),prs[y-1][x]=r+1,mx=max(mx,r+1);
      if (!rs[y+1][x]&&r+1<prs[y+1][x])xv[r+1].push_back(x),yv[r+1].push_back(y+1),prs[y+1][x]=r+1,mx=max(mx,r+1);
    }
  }
  cout<<res<<'\n';
}
