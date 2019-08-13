// 1203A - Circle of Students
// Written during the contest
#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define ll long long
using namespace std;
int s[200];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while(q--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    if (n==1) {
      cout << "YES\n";
      continue;
    }
    for (int i = 0; i < n; i++) {
      int lst=-1;
      for (int j = 0; j < n; j++) {
        int d = (i+j)%n;
        if (lst!=-1&&(s[d]!=lst+1&&!(s[d]==n&&lst==1))) {
          goto nxt;
        }
        lst=s[d];
      }
      cout << "YES\n"; goto nxt3;
      nxt:;
    }
    for (int i = 0; i < n; i++) {
      int lst=-1;
      for (int j = 0; j < n; j++) {
        int d = (i+j)%n;
        if (lst!=-1&&(s[d]!=lst-1&&!(s[d]==1&&lst==n))) {
          goto nx2t;
        }
        lst=s[d];
      }
      cout << "YES\n"; goto nxt3;
      nx2t:;
    }
    cout << "NO\n";
    nxt3:;
  }
}
