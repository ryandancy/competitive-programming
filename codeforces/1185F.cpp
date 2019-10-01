// 1185F - Two Pizzas
// We store each set as a bitset n where 0 <= n < 512 = 2^9. Then it's easy to loop through all possibilities
// and find each count since there are only 512 possibilities for the sets. O(2^(3n)) where n is the size of the
// set, but n = 9, so this is fast enough.
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int f[512] = {0};
int p[512] = {0};
priority_queue<pii> cai[512];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  int numi, ing;
  for (int i = 0; i < n; i++) {
    cin >> numi;
    int set = 0;
    for (int j = 0; j < numi; j++) {
      cin >> ing;
      set |= 1<<(ing-1);
    }
    f[set]++;
  }
  int cost;
  for (int i = 0; i < m; i++) {
    cin >> cost >> numi;
    int set = 0;
    for (int j = 0; j < numi; j++) {
      cin >> ing;
      set |= 1<<(ing-1);
    }
    p[set]++;
    cai[set].push({-cost, i+1});
  }
  int best = -1, besta = -1, bestb = -1, bcost = -1;
  for (int a = 0; a < 512; a++) {
    for (int b = 0; b <= a; b++) {
      if (!p[a] || !p[b]) continue;
      if (a == b && p[a] == 1) continue;
      int x = a|b;
      int cnt = 0;
      for (int m = 0; m < 512; m++) {
        if ((x|m) == x) {
          cnt += f[x^m];
        }
      }
      if (cnt > best) {
        best = cnt;
        besta = a;
        bestb = b;
        if (a == b) {
          pii top = cai[a].top();
          cai[a].pop();
          bcost = -cai[a].top().first - top.first;
          cai[a].push(top);
        } else {
          bcost = -cai[a].top().first - cai[b].top().first;
        }
      } else if (cnt == best) {
        int ncost;
        if (a == b) {
          pii top = cai[a].top();
          cai[a].pop();
          ncost = -cai[a].top().first - top.first;
          cai[a].push(top);
        } else {
          ncost = -cai[a].top().first - cai[b].top().first;
        }
        if (ncost < bcost) {
          bcost = ncost;
          besta = a;
          bestb = b;
        }
      }
    }
  }
  if (besta == bestb) {
    int top = cai[besta].top().second;
    cai[besta].pop();
    cout << top << " " << cai[besta].top().second << "\n";
  } else {
    cout << cai[besta].top().second << " " << cai[bestb].top().second << "\n";
  }
}
