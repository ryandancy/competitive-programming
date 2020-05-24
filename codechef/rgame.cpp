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
ll a[100500], e[100500], d[100500];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin>>T;
  while (T--) {
    int n;
    cin>>n;
    for (int i=0;i<=n;i++)cin>>a[i];
    e[0]=a[0], d[0]=0;
    for (int i=1,k=1;i<=n;i++,k*=2,k%=MOD) {
      e[i]=(e[i-1]+k*a[i]%MOD)%MOD;
      d[i]=2*((d[i-1]+a[i]*e[i-1]%MOD)%MOD)%MOD;
    }
    cout<<(d[n]+MOD)%MOD<<'\n';
  }
}
