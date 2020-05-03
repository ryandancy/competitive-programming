#include <iostream>
#include <string>
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
  double c;
  while (cin>>c, c) {
    for (int i=1;;i++){
      c-=1.0/(i+1);
      if (c<=EPS) {
        cout<<i<<" card(s)\n";
        break;
      }
    }
  }
}
