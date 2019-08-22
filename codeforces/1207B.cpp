// 1207B - Square Filling
// We try to fill at each space and check that everything's filled after
// Written during Codeforces Educational Round #71
#include <bits/stdc++.h>
using namespace std;
int a[50][50];
int b[50][50];
vector<pair<int, int> > ops;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  for (int x=0; x<n; x++) for (int y=0;y<m;y++) cin >> a[x][y];
  for (int x=0; x<n-1;x++) for (int y=0;y<m-1;y++) {
    if (a[x][y]&&a[x+1][y+1]&&a[x+1][y]&&a[x][y+1]) {
      ops.push_back({x, y});
      b[x][y] = b[x+1][y+1]=b[x+1][y]=b[x][y+1]=1;
    }
  }
  bool ok=true;
  for (int x=0; x<n; x++) for (int y=0;y<m;y++) {
    if (a[x][y]&&!b[x][y]) {
      ok=false;
      break;
    }
  }
  if (ok) {
    cout << ops.size() << '\n';
    for (pair<int, int>& xy : ops) {
      cout << xy.first+1 << ' ' << xy.second+1 << '\n';
    }
  } else cout << "-1\n";
}
