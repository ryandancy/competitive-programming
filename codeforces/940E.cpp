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
ll n,c;
ll a[100000],b[100000]={0},dp[100000]={0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>c;
  ll s=0;
  for (ll i=0;i<n;i++)cin>>a[i],s+=a[i];
  if (c>n) return cout<<s<<'\n',0;
  multiset<ll> cu;
  for (ll i=0;i<c;i++)cu.insert(a[i]);
  b[0]=*cu.begin();
  for (ll i=1;i+c<=n;i++) {
    cu.erase(cu.find(a[i-1]));
    cu.insert(a[i+c-1]);
    b[i]=*cu.begin();
  }
  dp[0]=b[0];
  for (ll i=1;i<n;i++) {
    dp[i]=max(dp[i-1],b[i]+(i-c<0?0:dp[i-c]));
  }
  cout<<s-dp[n-1]<<'\n';
}
