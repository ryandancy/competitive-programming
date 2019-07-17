// BUGLIFE - A Bug's Life

#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<int> adj[], int colours[], int node, int colour = 1) {
  // try to 2-colour it, return if we can't
  colours[node] = colour;
  for (int& neigh : adj[node]) {
    if (colours[neigh]) {
      if (colours[neigh] == colour) {
        return true;
      }
    } else if (dfs(adj, colours, neigh, colour == 1 ? 2 : 1)) {
      return true;
    }
  }
  return false;
}

bool susp() {
  int n, m;
  cin >> n >> m;
  
  int colours[2000]; // 0 = unvisited, 1 and 2 are colours
  fill(colours, colours+n, 0);
  vector<int> adj[2000];
  
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  // DFS for each component
  for (int b = 0; b < n; b++) {
    if (!colours[b] && dfs(adj, colours, b)) {
      return true;
    }
  }
  
  return false;
}

int main() {
  int cases;
  cin >> cases;
  
  for (int cas = 1; cas <= cases; cas++) {
    cout << "Scenario #" << cas << ":" << endl;
    if (susp()) {
      cout << "Suspicious bugs found!" << endl;
    } else {
      cout << "No suspicious bugs found!" << endl;
    }
  }
}
