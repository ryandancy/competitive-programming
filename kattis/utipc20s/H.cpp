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
bool rs[8]={false}, cs[8]={false};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  string s;
  for (int r=0;r<8;r++){
    cin>>s;
    for (int c=0;c<8;c++){
      if (s[c]=='R') {
        rs[r]=true;
        cs[c]=true;
      }
    }
  }
  int res=0;
  for (int r=0;r<8;r++){
    for (int c=0;c<8;c++){
      res+=!(rs[r]||cs[c]);
    }
  }
  cout<<res<<'\n';
}
