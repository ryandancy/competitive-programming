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
ll a[300000],mp[300000],b[300000],l[300000],r[300000];
bool u[300000]={false};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll q;
  cin>>q;
  while (q--) {
    ll n;
    cin>>n;
    fill_n(u,n,false);
    fill_n(l,n,-1);
    for (ll i=0;i<n;i++)cin>>a[i],a[i]--,u[a[i]]=true;
    ll nr=0;
    for (ll i=0;i<n;i++) {
      if (u[i])mp[i]=nr++;
    }
    for (ll i=0;i<n;i++) b[i]=mp[a[i]];
    for (ll i=0;i<n;i++) {
      if (l[b[i]]==-1) l[b[i]]=i;
      r[b[i]]=i;
    }
    ll lr=0,s=0;
    for (ll i=1;i<nr;i++) {
      if (r[i-1]>=l[i]) {
        lr=max(lr,i-s);
        s=i;
      }
    }
    lr=max(lr,nr-s);
    cout<<nr-lr<<'\n';
  }
}
