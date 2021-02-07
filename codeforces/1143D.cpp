#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000000000ll
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
ll n,k,a,b;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>k>>a>>b;
  ll nk=n*k;
  ll x=INF,y=-INF;
  for (ll ap=-1;ap<=1;ap+=2) {
    for (ll bp=-1;bp<=1;bp+=2) {
      for (ll l=((ap*a+bp*b)%k+k)%k;l<=nk;l+=k) {
        if (l==0) continue;
        ll v=nk/__gcd((unsigned long long)l,(unsigned long long)nk);
        x=min(x,v);
        y=max(y,v);
      }
    }
  }
  cout<<x<<' '<<y<<'\n';
}
