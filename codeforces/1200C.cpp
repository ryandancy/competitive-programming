// 1200C - Round Corridor
// Written during Codeforces Round #578 (Div. 2) on 11 August 2019
// The corridor will be divided into gcd(n, m) segments
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, m, q;
  cin >> n >> m >> q;
  ll g = gcd(n, m);
  ll nf = n/g, mf = m/g;
  ll sx, sy, ex, ey;
  for (int Q = 0; Q < q; Q++) {
    cin >> sx >> sy >> ex >> ey;
    sy--; ey--;
    if (sx == 1) sy /= nf;
    else sy /= mf;
    if (ex == 1) ey /= nf;
    else ey /= mf;
    if (sy == ey) cout << "YES\n";
    else cout << "NO\n";
  }
}