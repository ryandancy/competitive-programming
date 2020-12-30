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
string s;
bool ok(pii&ob) {
  int x=0,y=0;
  for (char c:s) {
    int nx=x,ny=y;
    switch (c) {
      case 'L': nx=x-1; break;
      case 'R': nx=x+1; break;
      case 'U': ny=y+1; break;
      case 'D': ny=y-1; break;
    }
    if (!(nx==ob.first&&ny==ob.second)) {
      x=nx,y=ny;
    }
  }
  return x==0&&y==0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin>>T;
  while (T--) {
    cin>>s;
    vector<pii> p;
    {
      int x=0,y=0;
      for (char c:s) {
        switch (c) {
          case 'L': x--; break;
          case 'R': x++; break;
          case 'U': y++; break;
          case 'D': y--; break;
        }
        p.push_back({x,y});
      }
    }
    pii&lst=*--p.end();
    if (lst.first==0&&lst.second==0) {
      cout<<"100000 100000\n";
      continue;
    }
    for (pii&x:p) {
      if (ok(x)) {
        cout<<x.first<<' '<<x.second<<'\n';
        goto end;
      }
    }
    cout<<"0 0\n";
    end:;
  }
}
