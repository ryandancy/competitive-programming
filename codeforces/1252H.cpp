// 1252H - Twin Buildings
// We reorder all lands such that L <= W; this suffices to get the largest area.
// We first calculate the maximum area from having two buildings in the same
// plot; this is simply taking L*W/2.
// We apply the following algorithm to find the maximum area from having two buildings
// of the same size in two plots:
// We sort by decreasing L and then generate an array mx where mx[i] is the maximum
// W in the array from 0 to i. Then, for each L at index, we calculate L*min(mx[i-1],W),
// which is the maximum area with L and an item with a lower index in the list.
// The maximum of all of this is the output. O(n).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
pll lwl[100000];
ll mx[100000];
bool lcomp(pll a, pll b) {
  return a.first > b.first;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  ll bs = 0;
  bool hf = false;
  for (int i = 0; i < N; i++) {
    cin >> lwl[i].first >> lwl[i].second;
    if (lwl[i].first > lwl[i].second) swap(lwl[i].first,lwl[i].second);
    ll nu = lwl[i].first*lwl[i].second;
    if (nu/2 > bs || (nu/2 == bs && nu % 2)) {
      bs = nu/2;
      hf = nu % 2;
    }
  }
  sort(lwl,lwl+N,lcomp);
  ll mw = 0;
  for (int i = 0; i < N; i++) {
    mw = max(mw, lwl[i].second);
    mx[i] = mw;
  }
  for (int i = 1; i < N; i++) {
    ll nu = min(lwl[i].second, mx[i-1])*lwl[i].first;
    if (nu > bs) {
      bs = nu;
      hf = false;
    }
  }
  cout << bs << '.' << (hf ? '5' : '0') << '\n';
}
