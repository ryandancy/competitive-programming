// 1255C - League of Leesins
// A simple algorithm to reconstruct the permutation (or its reverse):
// Keep a count of how many times each element appears. Find one that appears
// only once: that is the first element. There will be an element in its only
// triple that appears only twice: that is the second element. Initialize these
// as a and b and use the following algorithm:
// Find the triple in which a and b appears where the third element is not the element
// before a in the output array. The third element of that triple is the next element.
// Set a := b and b to the third element. Repeat until b appears only once. That is
// the last element. This is O(n).
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int app[100001] = {0};
vector<pii> tps[100001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n-2; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    app[a]++; app[b]++; app[c]++;
    tps[a].push_back({b,c});
    tps[b].push_back({a,c});
    tps[c].push_back({a,b});
  }
  int o1 = -1;
  for (int i = 1; i <= n; i++) {
    if (app[i] == 1) {
      o1 = i;
      break;
    }
  }
  assert(o1!=-1);
  assert(tps[o1].size()==1);
  int sec = app[tps[o1][0].first]==2 ? tps[o1][0].first : tps[o1][0].second;
  assert(app[sec]==2);
  cout << o1 << ' ' << sec << ' ';
  int a = o1, b = sec, l = -1;
  while (app[b] > 1) {
    for (pii& x : tps[a]) {
      if ((x.first==b || x.second==b) && (x.first != l && x.second != l)) {
        int nx = x.first == b ? x.second : x.first;
        cout << nx << (app[nx]==1 ? '\n' : ' ');
        l = a;
        a = b;
        b = nx;
        goto nxtb;
      }
    }
    assert(false);
    nxtb:;
  }
}
