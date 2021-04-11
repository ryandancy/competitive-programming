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
#define N 200000
ll n,a[N+2]={0},dp[N+2]={0};
bool cv[N+2]={false};
vector<pair<pll,ll> > c;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n;
  for (ll i=0;i<n;i++) {
    ll x;
    cin>>x;
    a[x]++;
    cv[x]=true;
  }
  ll l=1,s=0;
  for (ll i=1;i<=N+1;i++) {
    if (a[i]==0) {
      if (l<i) {
        c.push_back({{l,i-1},s-(i-l)});
        s=0;
      }
      l=i+1;
      continue;
    }
    s+=a[i];
  }
  for (pair<pll,ll> x:c) {
    ll ch=min(2ll,x.second);
    if (ch>0&&!cv[x.first.first-1]) {
      cv[x.first.first-1]=true;
      ch--;
    }
    if (ch>0&&!cv[x.first.second+1]) {
      cv[x.first.second+1]=true;
      ch--;
    }
  }
  ll mx=0;
  for (ll i=0;i<=N+1;i++) mx+=cv[i];
  dp[0]=0;
  for (ll i=1;i<=N+1;i++) {
    if (a[i]==0) dp[i]=dp[i-1];
    else if (i>=3) dp[i]=dp[i-3]+1;
    else dp[i]=1;
  }
  cout<<dp[N+1]<<' '<<mx<<'\n';
}
