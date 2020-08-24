#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
bool lt(pll&a, pll&b) {
  int A=max(a.fi,a.se),B=max(b.fi,b.se);
  if (A<B)return true;
  if (A>B)return false;
  if (a.fi<b.fi) return true;
  return a.se>b.se;
}
ll dst(pll&a, pll&b) {
  return abs(a.fi-b.fi)+abs(a.se-b.se);
}
pll xy[200000];
vector<pll*> lvp; vector<ll> dp[2], dsts;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin>>n;
  for (int i=0;i<n;i++)cin>>xy[i].fi>>xy[i].se;
  sort(xy,xy+n,lt);
  for (int i=0;i<n;) {
    ll l=max(xy[i].fi,xy[i].se);
    vector<pll> q;
    while (i<n&&l==max(xy[i].fi,xy[i].se))q.push_back(xy[i]),i++;
    lvp.push_back(new pll[2]{q.front(),q.back()});
    dsts.push_back(dst(q.front(),q.back()));
  }
  dp[0].resize(lvp.size());
  dp[1].resize(lvp.size());
  dp[0].back()=dp[1].back()=0;
  for (int i=lvp.size()-2;i>=0;i--) {
    dp[0][i]=min(dst(lvp[i][0],lvp[i+1][0])+dsts[i+1]+dp[1][i+1], dst(lvp[i][0],lvp[i+1][1])+dsts[i+1]+dp[0][i+1]);
    dp[1][i]=min(dst(lvp[i][1],lvp[i+1][0])+dsts[i+1]+dp[1][i+1], dst(lvp[i][1],lvp[i+1][1])+dsts[i+1]+dp[0][i+1]);
  }
  pll o{0,0};
  cout<<min(dst(o,lvp[0][0])+dsts[0]+dp[1][0], dst(o,lvp[0][1])+dsts[0]+dp[0][0])<<'\n';
}
