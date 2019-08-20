// 1204A - BowWow and the Timetable
// The answer to the problem is always floor(log4(s-1)) + 1 = floor(1/2 log2(s-1)) + 1.
// To calculate this, note that log2(s) equals the length of the binary representation of s minus 1.
// Written during Codeforces Round #581 (Div. 2)
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  string s;
  cin >> s;
  if (s.size()==1) {
    cout << "0\n";
    return 0;
  }
  bool h1 = false;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == '1') {
      h1 = true;
      break;
    }
  }
  int l2 = h1 ? s.size()-1 : s.size()-2;
  int k = l2/2+1;
  cout << k << "\n";
}
