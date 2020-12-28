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
ll h[200000],d[200000],m[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin>>T;
  while (T--) {
    ll n,k;
    cin>>n>>k;
    ll q=k-1;
    for (int i=0;i<n;i++)cin>>h[i];
    fill_n(m,n,0);
    for (int i=0;i<n-1;i++)d[i]=h[i+1]-h[i];
    // if (abs(h[n-1]-h[0])>q*(n-1)) {cout<<"NO\n";continue;}
    // if (d[0]>q||d[n-2]< -q){cout<<"NO\n";continue;}
    for (int i=0;i<n-2;i++) {
      if (d[i]< -q) {
        ll del=-q-d[i];
        d[i]+=del;
        d[i+1]-=del;
        m[i+1]+=del;
      }
    }
    for (int i=n-2;i>0;i--) {
      if (d[i]>q) {
        ll del=q-d[i];
        d[i]+=del;
        d[i-1]-=del;
        m[i]-=del;
      }
    }
    bool ok=true;
    for (int i=0;i<n-1;i++) {
      if (d[i]>q||d[i]< -q||m[i]>q) {cout<<"NO\n";ok=false;break;}
    }
    if (!ok)continue;
    cout<<"YES\n";
  }
}
