// 377A - Maze
// Fill in reverse order visited during DFS
// Time complexity: O(nm)

#include <bits/stdc++.h>
using namespace std;

int arr[500][500]; // 0 = '.', 1 = '#', 2 = 'X'
bool visited[500][500];
stack<pair<int, int> > stk;
int n, m, k, added = 0;

void dfs(int x, int y) {
  stk.push({x, y});
  
  while (added < k) {
    tie(x, y) = stk.top();
    
    if (arr[y][x]) {
      stk.pop();
      continue;
    }
    
    visited[x][y] = true;
    bool f = false;
    
    if (x > 0 && !arr[y][x-1] && !visited[x-1][y]) { stk.push({x-1, y}); f = true; }
    if (y > 0 && !arr[y-1][x] && !visited[x][y-1]) { stk.push({x, y-1}); f = true; }
    if (x < m-1 && !arr[y][x+1] && !visited[x+1][y]) { stk.push({x+1, y}); f = true; }
    if (y < n-1 && !arr[y+1][x] && !visited[x][y+1]) { stk.push({x, y+1}); f = true; }
    
    if (!f) {
      stk.pop();
      arr[y][x] = 2;
      added++;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m >> k;
  char e;
  for (int y = 0; y < n; y++) {
    cin.ignore(256, '\n');
    for (int x = 0; x < m; x++) {
      cin.get(e);
      arr[y][x] = (e == '#');
    }
  }
  
  // Find an empty cell and fill
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) {
      if (!arr[y][x]) {
        dfs(x, y);
        goto brk;
      }
    }
  }
  brk:;
  
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) {
      switch (arr[y][x]) {
        case 0: cout << '.'; break;
        case 1: cout << '#'; break;
        case 2: cout << 'X'; break;
      }
    }
    cout << '\n';
  }
}
