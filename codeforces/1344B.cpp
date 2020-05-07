#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
string mp[1000];
bool v[1000][1000]={{false}};
bool dr[1000]={false}, dc[10000]={false};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n, m;
  cin>>n>>m;
  for (int i=0;i<n;i++)cin>>mp[i];
  for (int i=0;i<n;i++) {
    int nhc=0;
    char c=mp[i][0];
    int j=0;
    while (j<m){
      while (j<m&&c==mp[i][j])j++;
      if (c=='#')nhc++;
      if (j<m)c=mp[i][j];
    }
    if (nhc>1)return cout<<"-1\n",0;
    if (nhc==1)dr[i]=true;
  }
  for (int j=0;j<m;j++){
    int nhc=0;
    char c=mp[0][j];
    int i=0;
    while (i<n){
      while (i<n&&c==mp[i][j])i++;
      if (c=='#')nhc++;
      if (i<n)c=mp[i][j];
    }
    if (nhc>1)return cout<<"-1\n",0;
    if (nhc==1)dc[j]=true;
  }
  bool ard=true;
  for (int i=0;i<n;i++){
    if (!dr[i]){
      ard=false;
      break;
    }
  }
  bool acd=true;
  for (int j=0;j<m;j++){
    if (!dc[j]) {
      acd=false;
      break;
    }
  }
  if (ard!=acd)return cout<<"-1\n",0;
  queue<int> x,y;
  int res=0;
  for (int ci=0;ci<n;ci++){
    for (int cj=0;cj<m;cj++){
      if (v[ci][cj]||mp[ci][cj]=='.')continue;
      res++;
      y.push(ci); x.push(cj);
      while (x.size()) {
        int j=x.front(), i=y.front();
        x.pop(), y.pop();
        if (v[i][j])continue;
        v[i][j]=true;
        for (int mi=-1;mi<=1;mi++){
          for (int mj=-1;mj<=1;mj++){
            if ((mi==0)==(mj==0))continue;
            int ni=i+mi,nj=j+mj;
            if (ni<0||ni>=n||nj<0||nj>=m)continue;
            if (v[ni][nj]||mp[ni][nj]=='.')continue;
            x.push(nj), y.push(ni);
          }
        }
      }
    }
  }
  cout<<res<<'\n';
}
