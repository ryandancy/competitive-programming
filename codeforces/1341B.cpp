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
int a[200000];
bool ip[200000]={false};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin>>T;
  while (T--) {
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)cin>>a[i];
    for (int i=1;i<n-1;i++){
      ip[i]=a[i]>a[i-1]&&a[i]>a[i+1];
    }
    // for (int i=0;i<n;i++)debug(ip[i]);
    int np=0;
    for (int i=1;i<k-1;i++){
      np+=ip[i];
    }
    // debug(np);
    int mxl=0,mxp=np;
    for (int l=1;l<=n-k;l++){
      np-=ip[l];
      np+=ip[l+k-2];
      // debug(l,np);
      if (np>mxp){
        mxp=np,mxl=l;
      }
    }
    cout<<mxp+1<<' '<<mxl+1<<'\n';
  }
}
