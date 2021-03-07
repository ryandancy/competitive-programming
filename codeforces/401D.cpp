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
string n;
ll dp[1<<18][100]={{0}},m;
ll fact(ll x) {
  if (x==0)return 1;
  return x*fact(x-1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>m;
  ll az=0;
  ll l=n.size();
  for (ll k=0;k<l;k++) {
    if (n[k]=='0') az|=(1<<k);
  }
  for (ll b=0;b<(1<<l);b++) {
    for (ll k=0;k<l;k++) {
      if (!(b&(1<<k))) continue;
      ll nb=b&~(1<<k);
      if ((nb&~az)!=0) {
        for (ll r=0;r<m;r++) {
          dp[b][(10*r+n[k]-'0')%m]+=dp[nb][r];
        }
      }
      if ((b&~az)!=0&&nb==0) dp[b][(n[k]-'0')%m]++;
    }
  }
  ll res=dp[(1<<l)-1][0];
  for (char c='0';c<='9';c++) {
    ll ct=0;
    for (char q:n) if (c==q) ct++;
    res/=fact(ct);
  }
  cout<<res<<'\n';
}
