// 448D - Multiplication Table
// Binary search for the answer in O(n log mn), count number less than x
// in O(n) via math.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt(ll n, ll m, ll x) {
  ll res = 0;
  for (int i = 1; i <= n; i++) {
    if (x<i) continue;
    res += min(m, (x-i)/i + ((x-i)%i != 0));
  }
  return res;
}
int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  ll l = 1, r = n*m;
  while (l <= r) {
    ll mid = (l+r)/2;
    ll a = cnt(n, m, mid), b = cnt(n, m, mid+1);
    if (a < k && b >= k) {
      cout << mid << endl;
      break;
    } else if (a >= k) {
      r = mid-1;
    } else {
      l = mid+1;
    }
  }
}
