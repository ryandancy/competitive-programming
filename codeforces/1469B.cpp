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
int n,m,a[100],b[100],pa[100],pb[100];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin>>T;
  while (T--) {
    cin>>n;
    for (int i=0;i<n;i++)cin>>a[i];
    cin>>m;
    for (int i=0;i<m;i++)cin>>b[i];
    int mxa=0,mxb=0;
    pa[0]=a[0];
    mxa=max(mxa,pa[0]);
    for (int i=1;i<n;i++)pa[i]=pa[i-1]+a[i],mxa=max(mxa,pa[i]);
    pb[0]=b[0];
    mxb=max(mxb,pb[0]);
    for (int i=1;i<m;i++)pb[i]=pb[i-1]+b[i],mxb=max(mxb,pb[i]);
    cout<<mxa+mxb<<'\n';
  }
}
