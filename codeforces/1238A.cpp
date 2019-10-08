// 1238A - Prime Subtraction
// Simple - any positive integer 1 has a prime factorization
// Written during Codeforces Educational Round #74
#include <bits/stdc++.h>
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
    ll x, y;
    cin >> x >> y;
    if (x-y == 1) cout << "NO\n";
    else cout << "YES\n";
  }
}
