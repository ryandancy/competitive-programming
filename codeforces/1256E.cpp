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
pll a[200001];
ll da[200001];
ll dp[200001],lp[200001];
ll t[200001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n;
  cin>>n;
  for (int i=0;i<n;i++)cin>>a[i].first,a[i].second=i;
  sort(a,a+n);
  ll sm=0;
  for (int i=0;i<n-1;i++) {
    da[i+1]=a[i+1].first-a[i].first;
    sm+=da[i+1];
  }
  da[0]=0;
  dp[0]=0; lp[0]=-1;
  for (int i=1;i<=n;i++) {
    // int bst=0,l=0;
    int bst=dp[i-1],l=i-1;
    // if (i<=n-3&&dp[i-1]>bst) {
    //   bst=dp[i-1];
    //   l=i-1;
    // }
    if (i>=3&&i<=n-3&&dp[i-3]+da[i]>bst) {
      bst=dp[i-3]+da[i];
      l=i-3;
    }
    dp[i]=bst; lp[i]=l;
  }
  ll res=sm-dp[n];
  vector<ll> pk;
  for (ll i=n; i>0; i=lp[i]) {
    if (lp[i]!=i-1) pk.push_back(i);
  }
  sort(pk.begin(),pk.end());
  ll k=0;
  for (int i=0;i<n;i++) {
    if (k<pk.size()&&i==pk[k]) k++;
    t[a[i].second]=k+1;
  }
  cout<<res<<' '<<k+1<<'\n';
  for (ll i=0;i<n;i++) {
    cout<<t[i]<<(i==n-1?'\n':' ');
  }
}
