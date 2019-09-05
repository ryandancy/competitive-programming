// 1195D2 - Submarines in the Rybinsk Sea (easy)
// Since all a_i are the same length, we can compute how much is added to the total
// by each digit independently. O(nd) where d is the number of digits in each a_i.
#include <bits/stdc++.h>
#define MOD 998244353LL
typedef long long ll;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  ll res = 0;
  string s;
  int digs = -1;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (digs == -1) digs = s.size();
    ll fac = 1;
    for (int j = 0; j < digs; j++, fac *= 100LL) {
      ll dig = s[digs-j-1]-'0';
      res += ((fac%MOD * dig)%MOD * n)%MOD;
      res %= MOD;
      res += ((fac%MOD * 10LL * dig)%MOD * n)%MOD;
      res %= MOD;
    }
  }
  cout << res << endl;
}
