// 1236A - Stones
// Written during Codeforces Round #593
#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
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
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int r = 0;
    if (b >= c/2) {
      r += 3*(c/2);
      b -= c/2;
    } else {
      r += 3*b;
      b = 0;
    }
    if (a >= b/2) {
      r += 3*(b/2);
      a -= b/2;
    } else {
      r += 3*a;
      a = 0;
    }
    cout << r << "\n";
  }
}
