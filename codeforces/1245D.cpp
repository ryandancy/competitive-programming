// 1245D - Shichikuji and Power Grid
// Generate a graph of the cities, find an MST with Prim's algorithm.
// Then power on the least expensive station and for each edge in decreasing
// order of cost (the sorting may not be necessary), do a DFS to find if there's
// a station on the side of the MST that would be unpowered if the edge was cut that
// is less expensive than the edge. If such a station is found, cut the edge and
// power on that station. O(n^2).
#include <bits/stdc++.h>
#define INF 10000000000000000LL
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
pll xy[2000];
ll c[2000], k[2000];
ll cst[2000][2000];
bool cut[2000][2000]={{false}};
vector<int> mst[2000];
bool v[2000] = {false};
bool pw[2000] = {false};
int stcd[2000];
vector<pii> es;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> xy[i].first >> xy[i].second;
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < n; i++) cin >> k[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cst[i][j] = (abs(xy[i].first-xy[j].first) + abs(xy[i].second-xy[j].second))*(k[i]+k[j]);
    }
  }
  for (int i = 0; i < n; i++) stcd[i] = i;
  sort(stcd,stcd+n,[&](int a, int b){return c[a]<c[b];});
  v[0] = true;
  int uv=n-1;
  priority_queue<tuple<ll, int, int> > mstq;
  for (int j = 1; j < n; j++) {
    mstq.push({-cst[0][j], 0, j});
  }
  ll tc=c[stcd[0]];
  ll np=1, nc=n-1;
  pw[stcd[0]] = true;
  while (uv>0) {
    ll d; int frm, cur;
    tie(d, frm, cur) = mstq.top(); mstq.pop();
    if (v[cur]) continue;
    v[cur] = true;
    uv--;
    mst[frm].push_back(cur);
    mst[cur].push_back(frm);
    es.push_back({frm,cur});
    tc += -d;
    for (int j = 0; j < n; j++) {
      if (v[j]) continue;
      mstq.push({-cst[cur][j], cur, j});
    }
  }
  sort(es.begin(),es.end(),[&](pii& a, pii& b){return cst[a.first][a.second]>cst[b.first][b.second];});
  list<int> q;
  for (pii& e : es) {
    ll minc=INF, minst=-1;
    bool nv[2000]={false};
    q.push_back(e.first);
    while (q.size()) {
      int cur = q.back(); q.pop_back();
      if (nv[cur]) continue;
      nv[cur] = true;
      if (pw[cur]) {
        minc=INF, minst=-1;
        q.clear();
        break;
      }
      if (c[cur] < minc) {
        minc = c[cur], minst=cur;
      }
      for (int oe : mst[cur]) {
        if (cut[oe][cur]) continue;
        if ((oe==e.first&&cur==e.second)||(cur==e.first&&oe==e.second)) continue;
        if (nv[oe]) continue;
        q.push_back(oe);
      }
    }
    if (minc != INF) {
      if (minc < cst[e.first][e.second]) {
        pw[minst]=true;
        np++; nc--;
        cut[e.first][e.second]=cut[e.second][e.first]=true;
        tc-=cst[e.first][e.second];
        tc+=minc;
      }
      continue;
    }
    q.push_back(e.second);
    while (q.size()) {
      int cur = q.back(); q.pop_back();
      if (nv[cur]) continue;
      nv[cur] = true;
      if (pw[cur]) {
        minc=INF, minst=-1;
        q.clear();
        break;
      }
      if (c[cur] < minc) {
        minc = c[cur], minst=cur;
      }
      for (int oe : mst[cur]) {
        if (cut[oe][cur]) continue;
        if ((oe==e.first&&cur==e.second)||(cur==e.first&&oe==e.second)) continue;
        if (nv[oe]) continue;
        q.push_back(oe);
      }
    }
    if (minc != INF) {
      if (minc < cst[e.first][e.second]) {
        pw[minst]=true;
        np++; nc--;
        cut[e.first][e.second]=cut[e.second][e.first]=true;
        tc-=cst[e.first][e.second];
        tc+=minc;
      }
    }
  }
  cout << tc << '\n' << np << '\n';
  for (int i = 0; i < n; i++) {
    if (pw[i]) cout << i+1 << ' ';
  }
  cout << '\n' << nc << '\n';
  for (pii& e : es) {
    if (!cut[e.first][e.second]) {
      cout << e.first+1 << ' ' << e.second+1 << '\n';
    }
  }
}
