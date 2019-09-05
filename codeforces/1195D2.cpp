// 1195D2 - Submarines in the Rybinsk Sea (hard)
// Same general idea as 1195D1, but we keep track of the count of elements with each number of digits
// and handle each separately. O(nd), where d is the number of digits per a_i, again, but with a
// constant factor of 10 on 1195D1. (Really, it's O(n) since d is small.)
#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
string a[100000];
ll cnt[11] = {0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i].size()]++;
  }
  ll res = 0;
  for (int i = 0; i < n; i++) {
    for (int k = 1; k <= 10; k++) {
      ll fac = 1;
      for (int j = 0; j < a[i].size(); j++) {
        ll dig = a[i][a[i].size()-j-1] - '0';
        if (j < k) {
          res += ((fac%MOD * dig)%MOD * cnt[k])%MOD;
          res %= MOD;
          res += ((fac%MOD * 10LL * dig)%MOD * cnt[k])%MOD;
          res %= MOD;
          fac *= 100LL;
          fac %= MOD;
        } else {
          res += ((fac%MOD * dig)%MOD * cnt[k] * 2LL)%MOD;
          res %= MOD;
          fac *= 10LL;
          fac %= MOD;
        }
      }
    }
  }
  cout << res << endl;
}
