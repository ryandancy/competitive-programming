// 796C - Bank Hacking
// Since there are n-1 edges and n nodes, the bank network forms a tree.
// The idea is that we can root the tree at the node we start at. Then,
// the root node stays as-is, its direct children have 1 added, and all other
// nodes have 2 added. The value of the computer at a node is the maximum of
// all nodes in this modified tree.
// We compute this efficiently (i.e. in less than O(n^2)) by keeping track of
// the highest and second-highest values and cleverly checking only a node's
// immediate children to see if we can use top+1 or top instead of top+2 as
// the best value. Time complexity: O(n).
#include <bits/stdc++.h>
using namespace std;
int str[300000];
vector<int> adj[300000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int top = -1000000005;
  int topc = 0;
  int stop = -1000000005;
  int stopc = 0;
  for (int i = 0; i < n; i++) {
    cin >> str[i];
    if (str[i] > top) {
      stop = top;
      stopc = topc;
      top = str[i];
      topc = 1;
    } else if (str[i] == top) {
      topc++;
    } else if (str[i] > stop) {
      stop = str[i];
      stopc = 1;
    } else if (str[i] == stop) {
      stopc++;
    }
  }
  int a, b;
  for (int i = 0; i < n-1; i++) {
    cin >> a >> b;
    a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int best = top + 2;
  for (int i = 0; i < n; i++) {
    if (topc == 1 && str[i] == top) {
      if (stop == top - 1) {
        int nstopc = stopc;
        for (int ne : adj[i]) {
          if (str[ne] == stop) nstopc--;
          if (nstopc == 0) break;
        }
        if (nstopc == 0) {
          best = min(best, top);
        } else {
          best = min(best, top+1);
        }
      } else {
        best = min(best, top);
      }
    } else {
      int ntopc = topc;
      if (str[i] == top) ntopc--;
      for (int ne : adj[i]) {
        if (str[ne] == top) ntopc--;
        if (ntopc == 0) break;
      }
      if (ntopc == 0) {
        best = min(best, top+1);
      }
    }
  }
  cout << best << "\n";
}
