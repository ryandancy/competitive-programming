#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...) (0)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll a[5000][5000],n;
ll st[5000]={0};
bool fc=false;
vector<ll> cyc;
ll dfs(ll x) {
  if (st[x]==2) return -1;
  if (st[x]==1) {fc=true;cyc.push_back(x);return x;}
  st[x]=1;
  for (ll i=0;i<n;i++) {
    if (a[x][i]) {
      ll r=dfs(i);
      if (fc) {
        if (r==x||r==-1) return -1;
        else {
          cyc.push_back(x);
          return r;
        }
      }
    }
  }
  st[x]=2;
  return -1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n;
  for (ll i=0;i<n;i++){
    string s; cin>>s;
    for (ll j=0;j<n;j++) a[i][j]=s[j]-'0';
  }
  for (ll i=0;i<n;i++) {
    if (st[i]) continue;
    dfs(i);
    if (fc) break;
  }
  if (!fc) return cout<<"-1\n",0;
  reverse(cyc.begin(),cyc.end());
  while (cyc.size()>=3) {
    if (a[cyc[0]][cyc[cyc.size()-2]]==1) {
      cout<<cyc[0]+1<<' '<<cyc[cyc.size()-2]+1<<' '<<cyc[cyc.size()-1]+1<<'\n';
      return 0;
    } else cyc.pop_back();
  }
  return 0;
}
