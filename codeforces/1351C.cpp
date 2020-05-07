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
  int T;
  cin>>T;
  while (T--) {
    string s;
    cin>>s;
    set<pair<pii, pii>> v;
    pii xy{0,0};
    ll res=0;
    for (char c:s) {
      pii nxy = xy;
      switch (c) {
        case 'S': nxy.second--; break;
        case 'N': nxy.second++; break;
        case 'W': nxy.first--; break;
        case 'E': nxy.first++; break;
      }
      pair<pii, pii> k=xy<nxy?pair{xy,nxy}:pair{nxy,xy};
      if (v.count(k)) res++;
      else res+=5, v.insert(k);
      xy=nxy;
    }
    cout<<res<<'\n';
  }
}
