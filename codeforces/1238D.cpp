// 12838D - AB-string
// The only non-palindromic substrings have a lone "A" or "B" at one end,
// so we calculate the total number and then subtract those.
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
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll res = n*(n-1)/2;
  for (int i = 0; i < n-1; i++) {
    if (s[i] != s[i+1]) res--;
  }
  int curr = '~';
  int cc = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == curr) {
      cc++;
    } else {
      curr = s[i];
      res -= cc;
      cc = 0;
    }
  }
  curr = '~', cc = 0;
  for (int i = n-1; i >= 0; i--) {
    if (s[i] == curr) {
      cc++;
    } else {
      curr = s[i];
      res -= cc;
      cc = 0;
    }
  }
  cout << res << "\n";
}
