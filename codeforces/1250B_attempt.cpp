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
ll b[8000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n, k, a;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a;
    b[a-1]++;
  }
  sort(b, b+k);
  if (k%2) {
    ll mw = -1;
    for (ll i = 0; i < k; i++) { // TO FIX: SKIP AS MANY AS POSSIBLE MAKING EVEN, NOT JUST ONE
      int num = 1;
      while (i < k-1 && b[i+1] == b[i]) i++, num++;
      int take = num - (num%2==0); // take last |take| incl i
      ll w = 0;                  // (i.e. if there are 3-4 of type, take 3, if there are 7-8, take 7)
      ll wrt = b[i];
      for (ll j = 0; j < (k-take)/2; j++) {
        int rj = j;
        if (j >= i - take + 1) rj += take;
        // ll o = (i<k/2) ? (j<i ? k-j-1 : k-j) : (i<k-j-1 ? k-j-1 : k-j-2);
        ll o = k-take-j-1;
        if (o >= i-take+1) o += take;
        ll s = b[o]+b[rj];
        if (s > wrt) {
          w += (j+take) * (s-wrt);
          wrt = s;
        } else {
          w += wrt-s;
        }
      }
      if (w < mw || mw < 0) mw = w;//, cout << wrt << " " << w << "\n";
    }
    cout << n+mw << "\n";
  } else {
    ll w = 0;
    ll wrt = 0;
    for (ll j = 0; j < k/2; j++) {
      ll o = k-j-1;
      ll s = b[o]+b[j];
      if (s > wrt) {
        w += j * (s-wrt);
        wrt = s;
      } else {
        w += wrt-s;
      }
    }
    cout << n+w << "\n";
  }
}
