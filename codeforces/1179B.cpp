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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n, m;
  cin>>n>>m;
  for (int r=0;r<n/2;r++){
    for (int c=0;c<m;c++){
      cout<<(r+1)<<' '<<(c+1)<<'\n'<<(n-r)<<' '<<(m-c)<<'\n';
    }
  }
  if (n%2){
    for (int c=0;c<m/2;c++){
      cout<<(n/2+1)<<' '<<(c+1)<<'\n'<<(n/2+1)<<' '<<(m-c)<<'\n';
    }
    if (m%2){
      cout<<(n/2+1)<<' '<<(m/2+1)<<'\n';
    }
  }
}
