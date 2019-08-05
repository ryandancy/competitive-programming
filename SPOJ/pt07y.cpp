// PT07Y - Is it a tree
// Simple DFS - it's a tree if a DFS from an arbitrary node hits every node once

#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[10000];
bool visited[10000];

bool dfs(int node = 0, int last = -1) {
  visited[node] = true;
  for (int& neigh : adj[node]) {
    if (neigh == last) continue;
    if (visited[neigh]) return false;
    if (!dfs(neigh, node)) return false;
  }
  return true;
}

bool ok(int N) {
  if (!dfs()) return false;
  for (int i = 0; i < N; i++) {
    if (!visited[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  int N, M;
  cin >> N >> M;
  
  int a, b;
  for (int i = 0; i < M; i++) {
    cin >> a >> b; a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  fill_n(visited, 10000, false);
  
  cout << (ok(N) ? "YES" : "NO") << endl;
}
