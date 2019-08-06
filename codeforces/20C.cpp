// 20C - Dijkstra?
// Modified Dijkstra's algorithm, O(n + m log m)
// Instead of a visited array, we store the previous node in the path, or 0 if unvisited
// Then to reconstruct the original path we traverse backwards from n to 1

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>

using namespace std;

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

vector<pii> adj[100001];
int tree[100001] = {0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m;
  cin >> n >> m;
  
  int a, b, w;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> w;
    adj[a].push_back(make_pair(w, b));
    adj[b].push_back(make_pair(w, a));
  }
  
  priority_queue<tiii, vector<tiii>, greater<tiii> > q;
  q.push(make_tuple(0, 1, 1));
  
  int d, last, node;
  while (q.size()) {
    do {
      tie(d, last, node) = q.top();
      q.pop();
    } while (tree[node]);
    tree[node] = last;
    
    if (node == n) {
      // reconstruct path from tree by traversing back
      stack<int> path;
      path.push(n);
      for (int i = n; i != tree[i]; i = tree[i]) {
        path.push(tree[i]);
      }
      while (path.size()) {
        cout << path.top();
        path.pop();
        cout << (path.size() ? " " : "\n");
      }
      return 0;
    }
    
    for (pii& neigh : adj[node]) {
      if (!tree[neigh.second]) {
        q.push(make_tuple(d + neigh.first, node, neigh.second));
      }
    }
  }
  
  cout << "-1\n";
}
