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
// typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll n,f[200],ls[200],ld[200];
bool ilp[200]={false};
ll sta[200]={0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n;
  for (ll i=0;i<n;i++)cin>>f[i],f[i]--;
  for (ll st=0;st<n;st++) {
    if (sta[st]) continue;
    ll c=st;
    ll no=0;
    while (!sta[c]) {
      sta[c]=1;
      c=f[c];
      no++;
    }
    if (sta[c]==1) {
      ll sz=1;
      for (ll x=f[c];x!=c;x=f[x])sz++;
      ls[c]=sz; ld[c]=0; ilp[c]=true; sta[c]=2;
      for (ll x=f[c];x!=c;x=f[x]) ls[x]=sz,ld[x]=0,ilp[x]=true,sta[x]=2;
      no-=sz;
    }
    for (ll x=st,i=0;x!=c;x=f[x],i++) {
      ls[x]=ls[c];
      ld[x]=ld[c]+no-i;
      sta[x]=2;
    }
  }
  set<ll> uq;
  ll mxd=0;
  for (ll x=0;x<n;x++) {
    debug(x,ls[x],ld[x]);
    uq.insert(ls[x]);
    mxd=max(mxd,ld[x]);
  }
  ll q=1;
  for (ll a:uq) {
    q=lcm(q,a);
  }
  ll k=q;
  while (k<mxd)k+=q;
  cout<<k<<'\n';
}
