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
int a[100];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int t;
  cin>>t;
  while (t--) {
    int n;
    cin>>n;
    for (int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int va=0,vb=0; bool br=false;
    for (int i=0,j=0;i<n;i++) {
      while (j<n&&a[j]<i)j++;
      if (j==n||a[j]!=i)break;
      va=i+1;
      if (!br) {
        j++;
        if (j==n) break;
        if (a[j]==i) vb=i+1;
        else br=true;
      }
    }
    cout<<va+vb<<'\n';
  }
}
