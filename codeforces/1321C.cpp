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
  int l;
  cin >> l;
  string s;
  cin >> s;
  l=s.size();
  char h='a';
  for (int i=0;i<l;i++)if (s[i]>h)h=s[i];
  debug(h);
  for (char x=h;x>'a';x--) {
    bool m;
    do {
      m=false;
      for (int i=0;i<l;i++) {
        if (s[i]!=x) {
          continue;
        }
        if ((i>0&&s[i-1]==x-1)||(i<l-1&&s[i+1]==x-1)) {
          m=true;
          s.erase(i,1);
        }
      }
    } while (m);
  }
  cout<<l-s.length()<<'\n';
}
