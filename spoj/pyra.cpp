// PYRA - Treeramids
// DFS keeping track of size of node and total volume of subtree

#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[10000];
int volumes[10000];
int sizes[10000];

void dfs(int node = 0, int last = -1) {
  int nc = 0;
  int osz = 0;
  for (int& neigh : adj[node]) {
    if (neigh == last) continue;
    nc++;
    dfs(neigh, node);
    osz += sizes[neigh];
    volumes[node] += volumes[neigh];
  }
  
  if (osz) sizes[node] = osz + nc + 1;
  else sizes[node] = 1;
  
  volumes[node] += sizes[node];
}

int main() {
  int cases;
  cin >> cases;
  
  for (int c = 0; c < cases; c++) {
    int n;
    cin >> n;
    if (c > 0) {
      for (int i = 0; i < n; i++) {
        adj[i].clear();
      }
    }
    
    int a, b;
    for (int i = 0; i < n - 1; i++) {
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a); // account for any order nonsense
    }
    
    fill(volumes, volumes+n, 0);
    dfs();
    cout << volumes[0] << endl;
  }
}
