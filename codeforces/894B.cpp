#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll n,m,k;
ll fexp(ll b, ll exp) {
  if (exp==0) return 1;
  if (exp==1) return b;
  ll d2=fexp(b, exp/2);
  d2*=d2;d2%=MOD;
  if (exp%2)d2*=b,d2%=MOD;
  return d2;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>m>>k;
  if (n%2!=m%2&&k==-1)return cout<<"0\n",0;
  if (n>m)swap(n,m);
  cout<<(fexp(fexp(2, n-1), m-1)+MOD)%MOD<<'\n';
}
