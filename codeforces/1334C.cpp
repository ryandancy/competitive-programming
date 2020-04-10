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
ll h[300000], d[300000], rh[300000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin>>T;
  while (T--){
    int n;
    cin>>n;
    for (int i=0;i<n;i++)cin>>h[i]>>d[i];
    ll sm=0, lod=-1;
    for (int i=0;i<n;i++){
      rh[(i+1)%n]=max(0ll,h[(i+1)%n]-d[i]);
      sm+=rh[(i+1)%n];
      ll df=h[(i+1)%n]-rh[(i+1)%n];
      if (lod==-1||df<lod)lod=df;
    }
    cout<<sm+lod<<'\n';
  }
}
