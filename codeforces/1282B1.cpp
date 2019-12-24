// 1282B1 - K for the Price of One (Easy)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200000];
ll o=0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    ll n,p,k;
    cin >> n >> p >> k;
    for (int i=o;i < o+n; i++) cin >> a[i];
    sort(a+o,a+o+n);
    ll l = 0, r = n;
    ll b = 0;
    while (l <= r) {
      ll m = l+(r-l)/2;
      ll t = 0;
      int i = 0;
      ll c = m;
      if (c%2) t += a[o], i++, c--;
      i++;
      while (c > 0) {
        t += a[o+i];
        i += 2;
        c -= 2;
      }
      if (t <= p) {
        if (m > b) b = m;
        l = m+1;
      } else {
        r = m-1;
      }
    }
    cout << b << "\n";
    o += n;
  }
}
