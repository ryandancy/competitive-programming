#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifndef DEBUG
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
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  ld x, y; int r, t=1;
  while (cin>>x>>y>>r) {
    ld zx=0, zy=0;
    for (int i=0;zx*zx+zy*zy<=4&&i<r;i++){
      ld nzx=zx*zx-zy*zy+x;
      ld nzy=2*zx*zy+y;
      zx=nzx, zy=nzy;
    }
    cout<<"Case "<<t++<<": "<<(zx*zx+zy*zy<=4?"IN":"OUT")<<"\n";
  }
}
