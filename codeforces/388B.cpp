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
bool A[1001][1001]={{false}};
ll h[32],g[32],f[32],c=3;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll pv[2]={1,1};
  f[0]=c++;
  g[0]=1;
  ll k;
  cin>>k;
  ll n=1;
  for (ll x=1;x<k;x*=2) n++;
  for (ll i=1;i<n;i++) {
    ll a=c++;
    ll b=c++;
    g[i]=b;
    h[i]=a;
    A[pv[0]][a]=A[a][pv[0]]=A[pv[1]][a]=A[a][pv[1]]=true;
    A[pv[0]][b]=A[b][pv[0]]=A[pv[1]][b]=A[b][pv[1]]=true;
    f[i]=c++;
    A[f[i]][f[i-1]]=A[f[i-1]][f[i]]=true;
    pv[0]=a;
    pv[1]=b;
  }
  A[2][f[n-1]]=A[f[n-1]][2]=true;
  for (ll b=0;b<n;b++) {
    if (k&(1<<b)) {
      A[g[b]][f[b]]=A[f[b]][g[b]]=true;
      A[h[b]][f[b]]=A[f[b]][h[b]]=true;
    }
  }
  cout<<c-1<<'\n';
  for (ll i=1;i<c;i++) {
    for (ll j=1;j<c;j++) {
      cout<<(A[i][j]?'Y':'N');
    }
    cout<<'\n';
  }
}
