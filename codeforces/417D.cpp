// 417D - Cunning Gena
// To deal with the monitors (k), we sort in order of increasing k, then check the
// minimum possible total cost (x) when adding in possible friends one at a time.
// To update the minimum possible total x, we use bitmasks to represent the sets
// and use DP to repeatedly | with new sets. With some optimization this runs in
// Omega(n*2^m) at most, I think, maybe. Big-O analysis is hard for this one.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mc[1<<20];
list<int> th;
struct f {ll x, k, m, ms[20];} fs[100];
bool kcomp(f a, f b) {
  return a.k < b.k;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, m, b;
  cin >> n >> m >> b;
  for (int i = 0; i < n; i++) {
    cin >> fs[i].x >> fs[i].k >> fs[i].m;
    for (int j = 0; j < fs[i].m; j++) {
      cin >> fs[i].ms[j];
      fs[i].ms[j]--;
    }
  }
  sort(fs, fs+n, kcomp);
  ll bst = -1;
  fill_n(mc, 1<<20, -1);
  for (int i = 0; i < n; i++) {
    int tbt = 0;
    for (int mi = 0; mi < fs[i].m; mi++) {
      tbt |= 1<<fs[i].ms[mi];
    }
    int old = mc[tbt];
    mc[tbt] = mc[tbt]==-1?fs[i].x:min(mc[tbt],fs[i].x);
    if (old==mc[tbt]) continue;
    th.push_front(tbt);
    auto it = th.begin();
    auto pe = th.end();
    {
      auto it2 = it;
      ++it2;
      for (; it2 != pe; ++it2) {
        int bt = *it | *it2;
        if (mc[bt]==-1) th.push_back(bt);
        mc[bt] = mc[bt]==-1?mc[*it]+mc[*it2]:min(mc[bt],mc[*it]+mc[*it2]);
      }
    }
    for (int cpos = 0; it != th.end(); ++it, ++cpos) {
      auto it2 = pe;
      auto ce = th.end();
      for (; it2 != ce; ++it2) {
        int bt = *it | *it2;
        if (mc[bt]==-1) th.push_back(bt);
        mc[bt] = mc[bt]==-1?mc[*it]+mc[*it2]:min(mc[bt],mc[*it]+mc[*it2]);
      }
    }
    if (mc[(1<<m)-1] != -1) {
      bst = bst==-1?mc[(1<<m)-1]+b*fs[i].k:min(bst,mc[(1<<m)-1]+b*fs[i].k);
    }
  }
  cout << bst << "\n";
}
