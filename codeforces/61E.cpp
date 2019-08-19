// 61E - Enemy is weak
// We essentially iterate the O(n log n) inversion-counting algorithm twice. The first iteration
// finds inversions, and the second finds elements less than the second element of each of those
// inversions - yielding the three decreasing elements required. Both phases are O(n log n) using
// binary indexed (Fenwick) trees. Also, since the binary indexed trees rely on a small enough
// element value, yet the elements may go up to 10^9, we use O(n log n) index compression:
// we sort the indices of the elements with respect to the elements themselves, then if e[i] is
// the i-th index in sorted order, we set the e[i]-th index-compressed element to i.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<int, int> a[1000000]; // original, pre index compression, with indices
int n;
int x[1000000]; // index compressed original
int s[1000000]; // intermediate between first and second iterations
ll bit[1000001] = {0}; // first iteration
ll ibit[1000001] = {0}; // second iteration

inline void bit_add(const int& x, const int& v = 1, ll bita[] = bit) {
  for (int k = x; k <= n; k += k&-k) {
    bita[k] += v;
  }
}

inline ll bit_sum(const int& x, ll bita[] = bit) {
  ll res = 0;
  for (int k = x; k > 0; k -= k&-k) {
    res += bita[k];
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  
  // Input + index compression
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a, a+n);
  for (int i = 0; i < n; i++) {
    x[a[i].second] = i;
  }
  
  // First iteration of inversion counting
  for (int i = 0; i < n; i++) {
    s[i] = bit_sum(n-x[i]);
    bit_add(n-x[i]);
  }
  
  // Second iteration of inversion counting
  ll res = 0;
  for (int i = 0; i < n; i++) {
    res += bit_sum(n-x[i], ibit);
    bit_add(n-x[i], s[i], ibit);
  }
  cout << res << '\n';
}
