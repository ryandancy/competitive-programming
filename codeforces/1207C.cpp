// 1207C - Gas Pipeline
// For each "gap" of m 0s between groups of 1s, we test whether it's cheaper to
// move down and save the m-1 pillars or stay up and save the 2 units of pipe.
// Written during Codeforces Educational Round #71
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int t;
  cin >> t; string s;
  while (t--) {
    ll n, a, b;
    cin >> n >> a >> b;
    cin >> s;
    ll ans = (n+1)*b + n*a;
    int i = 0;
    while (i<n&&s[i]!='1') i++;
    if (i==n) { cout << ans << '\n'; continue; }
    int se=n-1;
    while(s[se]!='1')se--;
    se++;
    ans += 2*a+b;
    int cb=0;
    while(i<se) {
      if (s[i]=='1') {
        ans += b;
        if (cb!=0) {
          int bl=cb-1;
          if (bl>0) {
            ans+=min(bl*b, 2*a);
          }
          ans+=b;
          cb=0;
        }
      } else {
        cb++;
      }
      i++;
    }
    cout << ans << '\n';
  }
}
