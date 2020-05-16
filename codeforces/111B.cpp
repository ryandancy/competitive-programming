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
int l[100001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  fill_n(l,100001,-1);
  int n;
  cin>>n;
  for (int i=0,x,y;i<n;i++){
    cin>>x>>y;
    int r=0;
    for (int d=1;d*d<=x;d++){
      if (x%d==0) {
        if (l[d]<i-y) r++;
        if (d*d!=x&&l[x/d]<i-y) r++;
        l[d]=l[x/d]=i;
      }
    }
    cout<<r<<'\n';
  }
}
