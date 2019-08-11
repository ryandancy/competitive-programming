// 1200A - Hotelier
// Written during Codeforces Round #578 (Div. 2) on 11 August 2019
#include <bits/stdc++.h>
using namespace std;
bool h[10] = {false};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (char c : s) {
    if (c == 'L') {
      for (int i = 0; i < 10; i++) {
        if (!h[i]) {
          h[i] = true;
          break;
        }
      }
    } else if (c == 'R') {
      for (int i = 9; i >= 0; i--) {
        if (!h[i]) {
          h[i] = true;
          break;
        }
      }
    } else {
      h[c-'0'] = false;
    }
  }
  string o;
  for (int i = 0; i < 10; i++) {
    if (h[i]) o += '1';
    else o += '0';
  }
  cout << o << endl;
}