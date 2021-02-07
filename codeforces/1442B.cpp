#include <bits/stdc++.h>
#define MOD 998244353
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
ll ap[200000],b[200000],n,k;
bool ib[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll t;
  cin>>t;
  while (t--) {
    cin>>n>>k;
    for (ll i=0,a;i<n;i++)cin>>a,a--,ap[a]=i,ib[i]=false;
    for (ll i=0;i<k;i++)cin>>b[i],b[i]--,ib[ap[b[i]]]=true;
    for (ll i=0;i<n;i++)debug(i,ib[i]);
    ll res=1;
    for (ll i=0;i<k;i++) {
      ll m=0;
      if (ap[b[i]]>0&&!ib[ap[b[i]]-1])m++;
      if (ap[b[i]]<n-1&&!ib[ap[b[i]]+1])m++;
      ib[ap[b[i]]]=false;
      res*=m;
      res%=MOD;
    }
    res%=MOD;
    res+=MOD;
    res%=MOD;
    cout<<res<<'\n';
  }
}
