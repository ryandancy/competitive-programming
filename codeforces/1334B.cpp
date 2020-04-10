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
  int T;
  cin>>T;
  while (T--){
    ll n, x;
    cin>>n>>x;
    for (int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    ll s=0;
    for (ll i=n-1,c=1;i>=0;i--,c++){
      s+=a[i];
      if (s/c<x){
        cout<<(n-i-1)<<'\n';
        goto nxt;
      }
    }
    cout<<n<<'\n';
    nxt:;
  }
}
