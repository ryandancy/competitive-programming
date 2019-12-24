// 1282B2 - K for the Price of One (Hard)
// Failed system tests, who knows why
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200000];
int o=0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin >> T;
  while (T--) {
    ll n,p,k;
    cin >> n >> p >> k;
    for (int i=o;i < o+n; i++) cin >> a[i];
    sort(a+o,a+o+n);
    int b=0;
    for (int q = 0; q < k; q++) {
      int nt = (n-q)/k;
      // debug(q,nt);
      int l = 0, r = nt;
      while (l <= r) {
        int m = l+(r-l)/2;
        ll t = 0;
        for (int i = 0; i < q; i++) {
          t += a[i+o];
        }
        int i = q+k-1;
        for (int j = 0; j < m; j++) {
          t += a[i+o];
          i += k;
        }
        if (t <= p) {
          if (m*k+q>b) b=m*k+q;
          l = m+1;
        } else {
          r = m-1;
        }
        // debug(q,nt,m,t,b);
        // cout << q << ' ' << m << ' ' << t << "\n";
      }
      // cout << q << " " << b << '\n';
    }
    cout << b << "\n";
    o += n;
  }
}
