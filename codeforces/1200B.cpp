// 1200B - Block Adventure
// Written during Codeforces Round #578 (Div. 2) on 11 August 2019
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll h[100];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int c = 0; c < t; c++) {
    ll n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n-1; i++) {
      if (h[i+1]-h[i] < k) {
        m += min(k-h[i+1]+h[i], h[i]);
      } else {
        m -= h[i+1]-h[i]-k;
      }
      if (m < 0) {
        cout << "NO\n";
        goto nxtc;
      }
    }
    cout << "YES\n";
    nxtc:;
  }
}