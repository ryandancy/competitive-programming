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
    if (n<=5){cout<<n-1<<'\n';continue;}
    ll m=(ll)((-1.0l+sqrtl((ld)(1+8*n)))/2.0l);
    ll a=m*(m-1)/2l,b=n-m;
    if (a+2<=b-1){
      b--;
      a=b;
    }
    cout<<a+b<<'\n';
  }
}
