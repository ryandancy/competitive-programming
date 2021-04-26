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
ll a[200];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll t;
  cin>>t;
  while (t--) {
    ll n,k;
    cin>>n>>k;
    if (k*2>=n) {cout<<"-1\n";continue;}
    ll b=1,t=n;
    for (ll i=0;i<k;i++) {
      a[2*i]=b++;
      a[2*i+1]=t--;
    }
    for (ll i=2*k;i<n;i++) {
      a[i]=b++;
    }
    for (ll i=0;i<n;i++){
      cout<<a[i];
      if (i==n-1)cout<<"\n";
      else cout<<" ";
    }
  }
}
