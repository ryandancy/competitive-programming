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
ll a[100000],b[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n;
  cin>>n;
  for (ll i=0;i<n/2;i++) cin>>a[i];
  ll rt=0;
  for (ll i=0;i<n/2;i++) {
    ll bk=-1;
    for (ll p=1;p*p<a[i];p++) {
      if ((a[i]-p*p)%(2*p)==0) {
        ll cbk=(a[i]-p*p)/(2*p);
        if (cbk*cbk<=rt) break;
        bk=cbk;
      }
    }
    if (bk==-1) return cout<<"No"<<'\n',0;
    bk=bk*bk;
    b[i]=bk-rt;
    rt=bk+a[i];
  }
  cout<<"Yes\n";
  for (int i=0;i<n/2;i++) {
    cout<<b[i]<<' '<<a[i]<<(i==n/2-1?'\n':' ');
  }
}
