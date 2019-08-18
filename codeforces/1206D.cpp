// 1206D - Shortest Cycle
// Mostly written during the contest, but didn't pass then; made to pass after.
// The idea is that if any bit has 3 or more numbers with it set, that's automatically a cycle
// of length 3. There are only a maximum of 128 numbers with at most 2 sharing a digit, so
// we can simply answer 3 for n > 128 (excluding zeros). Then we can use an O(n^2) BFS
// algorithm to find the shortest cycle for n <= 128. Sadly, I didn't implement it well enough
// during the contest, so boo hoo for me.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> hb[65];
vector<ll> adj[200];
ll a[200];
int lvls[200];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) { i--; n--; continue; }
    for (ll k = 0; (1LL<<k) <= a[i] && k <= 64; k++) {
      if (a[i]&(1LL<<k)) {
        hb[k].push_back(i);
        adj[i].push_back(k);
        if (hb[k].size() > 2) {
          cout << 3 << endl;
          return 0;
        }
      }
    }
  }
  int best = 99999999;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) { i--; continue; }
    fill_n(lvls, 200, -1);
    queue<ll> cs;
    queue<ll> lss;
    cs.push(i);
    lss.push(-1);
    while (cs.size()) {
      ll c = cs.front(), ls = lss.front();
      cs.pop(); lss.pop();
      if (ls == -1) {
        lvls[c] = 0;
      } else {
        lvls[c] = lvls[ls] + 1;
      }
      if (lvls[c] == best) continue;
      for (ll k : adj[c]) {
        for (int nb : hb[k]) {
          if (nb == ls || nb == c) continue;
          if (lvls[nb] != -1) {
            int lvl = lvls[nb] + lvls[c] + 1;
            best = min(best, lvl);
            lvls[nb] = min(lvls[nb], lvls[c] + 1);
            continue;
          }
          cs.push(nb);
          lss.push(c);
        }
      }
    }
  }
  if (best < 99999999) cout << best << endl;
  else cout << "-1\n";
}
