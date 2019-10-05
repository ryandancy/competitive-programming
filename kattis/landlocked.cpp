// Landlocked
// We process in 4 phases.
// First, we process the letters into IDs and associate the IDs with letters. This is
// to deal with non-contiguous countries.
// Then, we build a graph of the contiguous parts of each country (with the same ID).
// Then, we perform a BFS from the 'water' node (ID 0) to assign a landlocked level to
// each contiguous/ID'd part.
// Finally, we find the lowest-level contiguous part of each country and print.
// O(RC), I think. TIL: unordered_set is SUPER DUPER SLOW. (I mean it's O(log n) for each
// operation vs O(1) for vector operations, so it might be worth not using unordered_set.)
#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<int> adj[1000000];
vector<int> ids[26];
int lvl[1000000] = {0};
char mp[1001][1001];
int ip[1000][1000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int R, C;
  cin >> R >> C;
  int idc = 1;
  stack<int> xs, ys;
  for (int r = 0; r < R; r++) cin >> mp[r];
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      if (mp[r][c] == '-') continue;
      char cc = mp[r][c];
      int id = (cc == 'W') ? 0 : idc++;
      ids[cc-'A'].push_back(id);
      ys.push(r); xs.push(c);
      while (xs.size()) {
        int y = ys.top(); ys.pop();
        int x = xs.top(); xs.pop();
        if (mp[y][x] == '-') continue;
        if (mp[y][x] == cc) {
          mp[y][x] = '-';
          ip[y][x] = id;
          for (int dy = -1; dy <= 1; dy++) {
            if (y+dy < 0 || y+dy >= R) continue;
            for (int dx = -1; dx <= 1; dx++) {
              if (dx == 0 && dy == 0) continue;
              if (x+dx < 0 || x+dx >= C) continue;
              if (mp[y+dy][x+dx] != cc) continue;
              xs.push(x+dx);
              ys.push(y+dy);
            }
          }
        }
      }
    }
  }
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      if (ip[r][c] == -1) continue;
      int id = ip[r][c];
      ys.push(r); xs.push(c);
      while (xs.size()) {
        int y = ys.top(); ys.pop();
        int x = xs.top(); xs.pop();
        if (ip[y][x] == -1) continue;
        if (ip[y][x] == id) {
          ip[y][x] = -1;
          for (int dy = -1; dy <= 1; dy++) {
            if (y+dy < 0 || y+dy >= R) continue;
            for (int dx = -1; dx <= 1; dx++) {
              if (dx == 0 && dy == 0) continue;
              if (x+dx < 0 || x+dx >= C) continue;
              if (ip[y+dy][x+dx] == id) {
                xs.push(x+dx);
                ys.push(y+dy);
              } else if (ip[y+dy][x+dx] != -1) {
                adj[id].push_back(ip[y+dy][x+dx]);
                adj[ip[y+dy][x+dx]].push_back(id);
              }
            }
          }
        }
      }
    }
  }
  queue<int> bfs;
  lvl[0] = 1;
  bfs.push(0);
  while (bfs.size()) {
    int curr = bfs.front(); bfs.pop();
    for (int neigh : adj[curr]) {
      if (lvl[neigh] == 0) {
        lvl[neigh] = lvl[curr] + 1;
        bfs.push(neigh);
      } else if (lvl[curr] + 1 < lvl[neigh]) {
        lvl[neigh] = lvl[curr] + 1;
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    if (i == 'W'-'A') continue;
    if (!ids[i].size()) continue;
    int mn = INF;
    for (int id : ids[i]) {
      mn = min(mn, lvl[id]);
    }
    cout << ((char)(i+'A')) << ' ' << mn-2 << '\n';
  }
}
