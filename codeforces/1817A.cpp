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
ll a[200001]={0}, pf[200001]={0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n,q;
  cin>>n>>q;
  for (ll i=1;i<=n;i++) cin>>a[i];
  pf[0]=0;
  for (ll i=1;i<=n-2;i++) {
    pf[i]=pf[i-1]+(a[i]>=a[i+1]&&a[i+1]>=a[i+2]);
  }
  for (ll T=0;T<q;T++) {
    ll l,r;
    cin>>l>>r;
    if (r-l+1<=2) {cout<<r-l+1<<"\n"; continue;}
    ll d=pf[r-2]-pf[l-1];
    cout<<r-l+1-d<<"\n";
  }
}
