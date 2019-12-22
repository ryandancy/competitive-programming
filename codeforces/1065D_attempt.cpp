#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int N, b[10][10];
pii s[100];
int bd[99], kd[99], rd[99];
pll dj(int o1[99], int o2[99], int o3[99]) {
  // cout << "----\n";
  int* ds[3] = {o1, o2, o3};
  priority_queue<pair<pll,pii> > q;
  int v[3][100] = {{false}};
  pll dt[3][100];
  for (int i = 0; i < 3; i++) fill_n(dt[i],100,make_pair(INF,INF));
  q.push({{0ll,0ll},{0,0}});
  dt[0][0].first = dt[0][0].second = 0;
  while (!q.empty()) {
    auto cn = q.top(); q.pop();
    ll d = cn.first.first, dr = cn.first.second; int p = cn.second.first, x = cn.second.second;
    if (v[p][x]) continue;
    // cout << p << " " << x << " | " << dt[p][x].first << ' ' << dt[p][x].second << '\n';
    if (x == N*N-1) {
      return dt[p][x];
    }
    v[p][x] = true;
    for (int p2 = 0; p2 < 3; p2++) {
      if (p2 == p) continue;
      pll d2 = dt[p][x];
      d2.first++, d2.second++;
      if (d2 < dt[p2][x]) {
        dt[p2][x] = d2;
        q.push({{d-1,dr-1},{p2,x}});
      }
    }
    if (ds[p][x] < INF) {
      pll d2 = dt[p][x];
      d2.first += ds[p][x];
      if (d2 < dt[p][x+1]) {
        q.push({{d-ds[p][x],dr},{p,x+1}});
        dt[p][x+1] = d2;
      }
    }
  }
  return {1/0,1/0};
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin >> N;
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> b[i][j], b[i][j]--;
  for (int k = 0; k < N*N; k++) {
    for (int y = 0; y < N; y++) {
      for (int x = 0; x < N; x++) {
        if (b[y][x] == k) {
          s[k].first = y, s[k].second = x;
          goto nxtk;
        }
      }
    }
    nxtk:;
  }
  list<pair<int,pii> > q;
  bool v[10][10] = {{false}};
  for (int i = 0; i < N*N-1; i++) {
    bd[i] = ((s[i].first+s[i].second)%2 == (s[i+1].first+s[i+1].second)%2
      ? (s[i].first-s[i].second == s[i+1].first-s[i+1].second || s[i].first-(N-1-s[i].second) == s[i+1].first-(N-1-s[i+1].second)
      ? 1 : 2) : INF);
    rd[i] = (s[i].first==s[i+1].first || s[i].second==s[i+1].second ? 1 : 2);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) v[i][j] = false;
    int ds[10][10];
    for (int i = 0; i < N; i++) fill_n(ds[i], 10, INF);
    ds[s[i].first][s[i].second] = 0;
    q.push_back({0,s[i]});
    v[s[i].first][s[i].second] = true;
    kd[i] = INF;
    // cout << "-------\n";
    while (!q.empty()) {
      auto p = q.front(); q.pop_front();
      // cout << p.second.first << ' ' << p.second.second << ' ';
      if (p.second == s[i+1]) {
        kd[i] = ds[p.second.first][p.second.second];
        q.clear();
        break;
      }
      int x = p.second.first, y = p.second.second;
      if (x>0 && y>1 && ds[x][y]+1 < ds[x-1][y-2]) {q.push_back({ds[x][y]+1,{x-1,y-2}}); ds[x-1][y-2] = ds[x][y]+1;}
      if (x>1 && y>0 && ds[x][y]+1 < ds[x-2][y-1]) {q.push_back({ds[x][y]+1,{x-2,y-1}}); ds[x-2][y-1] = ds[x][y]+1;}
      if (x>0 && y<N-2 && ds[x][y]+1 < ds[x-1][y+2]) {q.push_back({ds[x][y]+1,{x-1,y+2}}); ds[x-1][y+2] = ds[x][y]+1;}
      if (x>1 && y<N-1 && ds[x][y]+1 < ds[x-2][y+1]) {q.push_back({ds[x][y]+1,{x-2,y+1}}); ds[x-2][y+1] = ds[x][y]+1;}
      if (x<N-2 && y>0 && ds[x][y]+1 < ds[x+2][y-1]) {q.push_back({ds[x][y]+1,{x+2,y-1}}); ds[x+2][y-1] = ds[x][y]+1;}
      if (x<N-1 && y>1 && ds[x][y]+1 < ds[x+1][y-2]) {q.push_back({ds[x][y]+1,{x+1,y-2}}); ds[x+1][y-2] = ds[x][y]+1;}
      if (x<N-2 && y<N-1 && ds[x][y]+1 < ds[x+2][y+1]) {q.push_back({ds[x][y]+1,{x+2,y+1}}); ds[x+2][y+1] = ds[x][y]+1;}
      if (x<N-1 && y<N-2 && ds[x][y]+1 < ds[x+1][y+2]) {q.push_back({ds[x][y]+1,{x+1,y+2}}); ds[x+1][y+2] = ds[x][y]+1;}
      // cout << '\n';
    }
  }
  // for (int i = 0; i < N*N-1; i++) cout << bd[i] << ' ';
  // cout << '\n';
  // for (int i = 0; i < N*N-1; i++) cout << rd[i] << ' ';
  // cout << '\n';
  // for (int i = 0; i < N*N-1; i++) cout << kd[i] << ' ';
  // cout << '\n';
  pii m = min(min(dj(bd,kd,rd),dj(kd,bd,rd)),dj(rd,bd,kd));
  cout << m.first << " " << m.second << "\n";
}
