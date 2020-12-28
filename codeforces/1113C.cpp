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
ll n,a[300000],p[300001],e[2][300001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n;
  for (ll i=0;i<n;i++) cin>>a[i];
  p[0]=0;
  for (ll i=1;i<=n;i++)p[i]=p[i-1]^a[i-1];//,debug(p[i]);
  ll id[2]={0};
  for (ll i=0;i<=n;i++) {
    e[i%2][id[i%2]++]=p[i];
  }
  sort(e[0],e[0]+id[0]);
  sort(e[1],e[1]+id[1]);
  ll res=0;
  for (ll d=0;d<=1;d++){
    ll cn=0;
    for (ll i=0,c=-1;i<id[d];i++) {
      if (c!=e[d][i]) res+=cn*(cn+1)/2,cn=0,c=e[d][i];
      else cn++;
    }
    res+=cn*(cn+1)/2;
  }
  cout<<res<<'\n';
}
