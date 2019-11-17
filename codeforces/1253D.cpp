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
int link[200000], sz[200000], rm[200000];
// bool seen[200000] = {false};
int find(int x) {
  while (x != link[x]) x = link[x];
  return x;
}
void unite(int a, int b) {
  a = find(a); b = find(b);
  if (a == b) return;
  if (sz[a] < sz[b]) swap(a, b);
  sz[a] += sz[b];
  link[b] = a;
  rm[a] = max(rm[a], rm[b]);
  // seen[a] |= seen[b];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    link[i] = rm[i] = i;
    sz[i] = 1;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    unite(a-1, b-1);
  }
  int res = 0, curr = find(0);
  for (int i = 1; i < n; i++) {
    int fi = find(i);
    if (fi == curr) continue;
    if (rm[curr] > i) {
      res++;
      unite(curr, fi);
      curr = find(curr);
    } else {
      curr = fi;
    }
    // if (seen[fi]) {
    //   res++;
    //   // seen[fi] = false;
    //   unite(curr, fi);
    //   curr = find(curr);
    // } else {
    //   // seen[curr] = true;
    //   curr = fi;
    // }
  }
  cout << res << "\n";
}
