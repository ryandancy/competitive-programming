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
ll k[300000], c[300000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin>>T;
  while (T--) {
    ll n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)cin>>k[i],k[i]--;
    for (int i=0;i<m;i++)cin>>c[i];
    sort(k,k+n);
    ll res=0,nu=0;
    for (int i=n-1;i>=0;i--) {
      if (nu<n&&c[k[i]]>c[nu]) res+=c[nu++];
      else res+=c[k[i]];
    }
    cout<<res<<'\n';
  }
}
