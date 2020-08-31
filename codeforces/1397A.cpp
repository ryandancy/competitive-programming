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
ll a[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n;
  cin>>n;
  for (ll i=0;i<n;i++)cin>>a[i];
  cout<<"1 1\n"<< -a[0]<<"\n";
  a[0]=0;
  if (n==1) {
    cout<<"1 1\n0\n1 1\n0\n";
    return 0;
  }
  cout<<2<<' '<<n<<'\n';
  ll t=n-1;
  for (ll i=1;i<n;i++) {
    cout<<a[i]*t<<(i==n-1?'\n':' ');
    a[i]+=a[i]*t;
  }
  cout<<"1 "<<n<<'\n';
  for (ll i=0;i<n;i++) {
    cout<< -a[i]<<(i==n-1?'\n':' ');
  }
}
