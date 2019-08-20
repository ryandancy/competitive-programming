// 1204D1 - Kirk and a Binary String (easy version)
// This O(n^2) algorithm suffices for 1204D1 (n <= 2000), but fails for 1204D2 (n <= 10^6).
// See 1204D2 for an explanation of the base observations that lead to this solution.
// This algorithm avoids storing O(n^4) segments by holding the number of 1s up to each
// position computed only from the previous 1's position. We then modify this array
// for each successive 1. Time complexity: O(n^2).
// Written during Codeforces Round #581 (Div. 2).
#include <bits/stdc++.h>
using namespace std;
int ans[100000] = {0}; // 10^5 on the off chance that it works for 1204D2
bool ok[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  string s;
  cin >> s;
  int n = s.size();
  fill_n(ok, n, true);
  int i = 0;
  while (s[i] != '1' && i < n) i++;
  if (i==n) {cout << s << '\n'; return 0;}
  ans[i] = 1;
  for (int j = i+1; j < n; j++) {
    ans[j] = ans[j-1];
    if (s[j]=='1') ans[j]++;
    if (ans[j]*2 <= j-i+1) { ok[i] = false; }
  }
  for (int k = i+1; k < n; k++) {
    if (s[k]!='1') continue;
    for (int j = k+1; j < n; j++) {
      ans[j]--;
      if (ans[j]*2 <= j-k+1) ok[k] = false;
    }
  }
  string nu;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0' || (s[i]=='1' && ok[i])) {
      nu += '0';
    } else nu += '1';
  }
  cout << nu << '\n';
}
