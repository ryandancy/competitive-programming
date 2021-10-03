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
ll k,n[3],t[3];
ll rb[3][3000]={{0}},rbs[3]={0};
ll&rbg(ll x,ll i) {
  return rb[x][(i+rbs[x])%(t[0]+t[1]+t[2])];
}
void rba(ll x) {
  rb[x][rbs[x]]=0;
  rbs[x]++;
  rbs[x]%=t[0]+t[1]+t[2];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>k>>n[0]>>n[1]>>n[2]>>t[0]>>t[1]>>t[2];
  for (ll i=0;i<t[0];i++) rbg(0,i)++;
  for (ll i=t[0];i<t[0]+t[1];i++) rbg(1,i)++;
  for (ll i=t[0]+t[1];i<t[0]+t[1]+t[2];i++)rbg(2,i)++;
  ll r=t[0]+t[1]+t[2];
  for (ll i=1;i<k;i++) {
    ll mu=0;
    for (ll j=t[0]+t[1]+t[2]-1;j>=0;j--) {
      if (rbg(0,j)==n[0]) {mu=max(mu,j+1); break;}
    }
    for (ll j=t[0]+t[1]+t[2]-1;j>=0;j--) {
      if (rbg(1,j)==n[1]) {mu=max(mu,j+1-t[0]); break;}
    }
    for (ll j=t[0]+t[1]+t[2]-1;j>=0;j--) {
      if (rbg(2,j)==n[2]) {mu=max(mu,j+1-t[0]-t[1]); break;}
    }
    for (ll a=0;a<3;a++) for (ll j=0;j<mu;j++) rba(a);
    r+=mu;
    for (ll i=0;i<t[0];i++) rbg(0,i)++;
    for (ll i=t[0];i<t[0]+t[1];i++) rbg(1,i)++;
    for (ll i=t[0]+t[1];i<t[0]+t[1]+t[2];i++)rbg(2,i)++;
  }
  cout<<r<<'\n';
}
