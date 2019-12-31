// 1276B - Two Fairs
// We do some DFSes to find the number of nodes connected only to a
// and only to b, then multiply those numbers. O(n), I think.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> adj[200000];
list<int> stk;
bool v[200000] = {false};
int o=0;
int n, m, a, b;
ll dfs(int s, bool da, bool db) {
  if (v[o+s] || s == a || s == b) return 0;
  v[o+s] = true;
  stk.push_front(s);
  ll nm = 0;
  while (stk.size()) {
    int x = stk.front(); stk.pop_front();
    if (x == a) da = true;
    if (x == b) db = true;
    if (x == a || x == b) continue;
    nm++;
    for (int nb : adj[o+x]) {
      if (!v[o+nb] || nb == a || nb == b) {
        if (nb == a || nb == b) {
          if (nb == a) da = true;
          if (nb == b) db = true;
        } else {
          v[o+nb] = true;
        }
      }
    }
  }
  return da && db ? 0 :nm;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m >> a >> b;
    a--, b--;
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      adj[o+x].push_back(y);
      adj[o+y].push_back(x);
    }
    ll aa = 0, ba = 0;
    for (int nb : adj[o+a]) {
      aa += dfs(nb, true, false);
    }
    for (int nb : adj[o+b]) {
      ba += dfs(nb, false, true);
    }
    cout << aa*ba << '\n';
    assert(!v[o+a] && !v[o+b]);
    o += n;
  }
}
