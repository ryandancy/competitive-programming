// 1206B - Make Product Equal One
// Written during the contest
#include <bits/stdc++.h>
using namespace std;
ll a[100000];
int negcnt = 0;
int zcnt = 0;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < 0) negcnt++;
    if (a[i] == 0) zcnt++;
  }
  sort(a, a+n);
  ll res = 0;
  if (negcnt % 2) {
    if (zcnt) negcnt++;
    else negcnt--;
  }
  for (int i = 0; i < negcnt; i++) {
    res += abs(a[i] + 1);
  }
  for (int i = negcnt; i < n; i++) {
    res += abs(a[i] - 1);
  }
  cout << res << endl;
}
