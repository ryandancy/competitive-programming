// Pyramid Array - the idea is that at any point, the lowest value in the
// array has to be moved to the left or right side, at which point we can pretend it
// doesn't exist in the array. We use a BIT/Fenwick tree to keep track of missing
// array values in log time and use a bit of trickery to handle equal values.
// Time complexity: O(n log n).

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll bit[200001] = {0};
int n;

void inc(int x) {
  x++;
  while (x <= n) {
    bit[x]++;
    x += x&-x;
  }
}

ll sum(int x) {
  x++;
  ll res = 0;
  while (x > 0) {
    res += bit[x];
    x -= x&-x;
  }
  return res;
}

int main() {
  cin >> n;
  
  ll x[200000], p[200000];
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    p[i] = i;
  }
  sort(p, p+n, [&] (ll a, ll b) { return x[a] < x[b]; });
  
  ll res = 0;
  for (int i = 0, tc = 0; i < n;) {
    ll l = i;
    while (i < n && x[p[i]] == x[p[l]]) i++;
    ll r = i - 1;
    
    while (l <= r) {
      ll tl = p[l] - sum(p[l]), tr = n - 1 - p[r] - (tc - sum(p[r]));
      if (tl < tr) {
        res += tl;
        inc(p[l++]);
      } else {
        res += tr;
        inc(p[r--]);
      }
      tc++;
    }
  }
  
  cout << res << '\n';
}
