// 662D - International Olympiad
// Did it on paper, just a bunch of if statements. O(n).
#include <bits/stdc++.h>
using namespace std;
int y(string s) {
  int i = stoi(s);
  if (s == "9") {
    return 1989;
  } else if (s.size() == 1) {
    return 1990 + i;
  } else if (s == "99") {
    return 1999;
  } else if (s.size() == 2) {
    return 2000 + i;
  } else if (s == "099") {
    return 2099;
  } else if (s.size() == 3) {
    if (s[0] == '0') {
      return 3000 + i;
    } else {
      return 2000 + i;
    }
  }
  string gt;
  for (int j = 0; j < s.size() - 4; j++) {
    gt += '1';
  }
  gt += "3099";
  if (i >= stoi(gt)) {
    return i;
  }
  int t = 1;
  for (int j = 0; j < s.size(); j++) {
    t *= 10;
  }
  return t + i;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    cout << y(s.substr(4)) << "\n";
  }
}
