// 1204C - Anna, Svyatoslav, and Maps
// First, we run the Floyd-Warshall algorithm to find the minimum length of the paths between
// every pair of nodes. This is O(n^3), but n <= 100, so it's fast enough. Then, we process the
// path. For every node in the path that is not the first or last node, we check whether
// the distance between the previous and next nodes is the same as the sum of the distance from
// the previous node to the current node and that from the current to the next node (i.e. if
// the path through the current node is a shortest path between the last and next nodes).
// If so, we exclude it from the output. (The exception is if the first and last nodes are the
// same: we never exclude in that case.)
// Time complexity: O(n^3+m).
// Written during Codeforces Round #581 (Div. 2).
#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
int fw[100][100];
int p[1000000];
vector<int> g;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n; char c;
  cin >> n;
  for (int i = 0; i < n; i++) fill_n(fw[i], n, INF);
  for (int a = 0; a < n; a++) {
    cin.ignore(256, '\n');
    for (int b = 0; b < n; b++) {
      cin.get(c);
      if (c=='1') fw[a][b] = 1;
    }
  }
  for (int a = 0; a < n; a++) {
    for (int b = 0; b < n; b++) {
      for (int m = 0; m < n; m++) {
        fw[a][b] = min(fw[a][b], fw[a][m] + fw[m][b]);
      }
    }
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> p[i];
    p[i]--;
  }
  g.push_back(p[0]);
  int ls = p[0];
  for (int i = 1; i < m-1; i++) {
    int c = p[i];
    int nx = p[i+1];
    if (ls == nx || fw[ls][c] + fw[c][nx] != fw[ls][nx]) {
      g.push_back(c);
      ls = c;
    }
  }
  g.push_back(p[m-1]);
  cout << g.size() << '\n';
  for (int x : g) {
    cout << x+1 << ' ';
  }
  cout << '\n';
}
