// 1203D1 - Remove the Substring (easy)
// Written during the contest
#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define ll long long
using namespace std;
inline int val(string& s, string& t, int ss=0, int st=0) {
  int res = -1;
  for (int i = ss; i < s.size(); i++) {
    if (s[i] == t[st]) {
      if (st == t.size() - 1) {
        res = max(res, max(i-ss, (int)s.size()-i-1));
      } else {
        int v = val(s, t, i+1, st+1);
        if (v == -1) continue;
        res = max(res, max(i-ss, v));
      }
    }
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >>t;
  cout << val(s, t) << endl;
}
