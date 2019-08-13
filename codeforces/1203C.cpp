// 1203C - Common Divisors
// Written during the contest
#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define ll long long
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int g, e;
  cin >> g;
  for (int i = 0; i < n-1; i++) {
    cin >> e;
    g = __gcd(g, e);
  }
  unordered_map<int, int> f;
  for (int i = 2; i*i <= g; i++) {
    while (g%i == 0) {
      f[i]++;
      g /= i;
    }
  }
  if (g > 1) f[g]++;
  int res = 1;
  for (auto& i : f) {
    res *= (i.second + 1);
  }
  cout << res << endl;
}
