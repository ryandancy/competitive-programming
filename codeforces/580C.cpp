// 580C - Kefa and Park
// Simple DFS keeping track of the consecutive cat-nodes ending at each node
// We stop DFSing if the consecutive nodes exceeds the maximum

#include <iostream>
#include <vector>

using namespace std;

int ok;
vector<int> adj[100001];
bool cat[100001];
int consec[100001];

int dfs(int node = 1, int last = 0) {
  consec[node] = cat[node] ? consec[last] + 1 : 0;
  if (consec[node] <= ok) {
    int res = 0;
    bool found = false;
    for (int& child : adj[node]) {
      if (child != last) {
        found = true;
        res += dfs(child, node);
      }
    }
    if (res) return res;
    else return found ? 0 : 1;
  } else return 0;
}

int main() {
  int n;
  cin >> n >> ok;
  
  for (int i = 1; i <= n; i++) {
    cin >> cat[i];
  }
  
  int a, b;
  for (int i = 0; i < n-1; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  cout << dfs() << "\n";
}
