// BITMAP - Bitmap
// Keep track of all white pixels and do a BFS from each
// BFS is optimized by stopping when dist[nx][ny] <= dist[x][y] + 1
// (i.e. no more can be done)
// O(n^3) I think, but optimized + n is small

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define INF 10000000

using namespace std;

const int DXS[] = {-1, 1, 0, 0};
const int DYS[] = {0, 0, -1, 1};

int dists[182][182];

vector<pair<int, int> > ones;
queue<pair<int, int> > bfs;

int main() {
  int T, n, m;
  
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      fill_n(dists[i], m, INF);
      cin.ignore(256, '\n');
      for (int j = 0; j < m; j++) {
        if (cin.get() == '1') {
          ones.push_back(make_pair(i, j));
          dists[i][j] = 0;
        }
      }
    }
    cin.ignore(256, '\n');
    
    for (pair<int, int>& one : ones) {
      bfs.push(one);
      pair<int, int> curr;
      while (!bfs.empty()) {
        curr = bfs.front();
        bfs.pop();
        int currdist = dists[curr.first][curr.second];
        for (int i = 0; i < 4; i++) {
          int nx = curr.first+DXS[i], ny = curr.second+DYS[i];
          if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if (dists[nx][ny] > currdist + 1) {
            dists[nx][ny] = currdist + 1;
            bfs.push(make_pair(nx, ny));
          }
        }
      }
    }
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << dists[i][j];
        if (j < m - 1) cout << " ";
      }
      cout << endl;
    }
    
    ones.clear();
  }
}
