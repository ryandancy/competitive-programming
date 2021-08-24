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
ll inv[500001]={0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n,k;
  cin>>n>>k;
  if (k>n) return cout<<"0\n",0;
  if (k==1) return cout<<n<<'\n',0;
  inv[1]=1;
  for (int i=2;i<k;i++) inv[i]=MOD-(MOD/i)*inv[MOD%i]%MOD;
  ll kfinv=1;
  for (int i=2;i<k;i++) {
    kfinv*=inv[i];
    kfinv%=MOD;
  }
  ll res=0;
  for (ll i=1;;i++) {
    ll x=n/i-1;
    if (k-1>x) break;
    ll num=1;
    for (ll i=x-k+2;i<=x;i++) {
      num*=i;
      num%=MOD;
    }
    num*=kfinv;
    num%=MOD;
    res+=num;
    res%=MOD;
  }
  cout<<(res%MOD+MOD)%MOD<<'\n';
}
