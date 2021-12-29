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
ll df[200005]={0},n,m,x[200005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>m;
  for (ll i=0;i<m;i++) cin>>x[i],x[i]--;
  for (ll i=0;i<m-1;i++) {
    if (x[i]==x[i+1]) continue;
    ll c=x[i],d=x[i+1];
    if (c>d) swap(c,d);
    ll b=d-c;
    df[0]+=b;
    df[c]-=b;
    df[c]+=d;
    df[c+1]-=d;
    df[c+1]+=b-1;
    df[d]-=b-1;
    df[d]+=c+1;
    df[d+1]-=c+1;
    df[d+1]+=b;
  }
  ll r=0;
  for (ll i=0;i<n;i++) {
    r+=df[i];
    cout<<r<<(i==n-1?'\n':' ');
    // debug(df[i]);
  }
}
