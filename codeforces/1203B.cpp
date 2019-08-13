// 1203B - Equal Rectangles
// Written during the contest
#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define ll long long
using namespace std;
int a[10001] = {0};
unordered_map<int, int> s;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while(q--) {
    int n;
    cin >> n;
    int x;
    fill_n(a, 10001, 0);
    s.clear();
    for (int i = 0; i < 4*n; i++) {
      cin >> x;
      a[x]++;
    }
    for (int i = 1; i <= 10000; i++) {
      if (a[i]%2) {
        cout << "NO\n";
        goto cnt;
      } else a[i] /= 2;
    }
    for (int i = 1; i <= 10000; i++) {
      if (!a[i]) continue;
      for (int j = i; j <= 10000; j++) {
        if (!a[j]) continue;
        if (i==j) {
          if (a[i]<2) continue;
          s[i*i] += a[i]/2;
          if (s[i*i] >= n) {
            cout << "YES\n";
            goto cnt;
          }
          continue;
        }
        int c = i*j;
        s[c] += min(a[i], a[j]);
        if (s[c] >= n) {
          cout << "YES\n";
          goto cnt;
        }
      }
    }
    cout << "NO\n";
    cnt:;
  }
}
