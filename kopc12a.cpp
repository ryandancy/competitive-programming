// KOPC12A - K12 - Building Construction
// Ternary search for minimum cost - O(n log m) where m is the range of heights
// Let cost(k) be the total cost to set all buildings to height k.
// Then cost(k) = sum(i=0 to n-1) |k - heights[i]| * costs[i]. This is unimodal and O(n).
// We then ternary search, initializing with the highest and lowest height
// (since it is never optimal to go outside the initial range) for O(n log m).

#include <iostream>

using namespace std;

typedef long long ll; // long long is probably unnecessary, but whatever

int n;
ll h[10000];
ll c[10000];

inline ll cost(int targ) {
  ll res = 0;
  for (int i = 0; i < n; i++) {
    res += abs(targ - h[i]) * c[i];
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> n;
    
    // input, keeping track of min and max in l and r respectively
    ll l = 10000000, r = -1;
    for (int i = 0; i < n; i++) {
      cin >> h[i];
      l = min(l, h[i]);
      r = max(r, h[i]);
    }
    for (int i = 0; i < n; i++) cin >> c[i];
    
    // ternary search
    while (r - l >= 3) {
      int m1 = l + (r-l)/3, m2 = r - (r-l)/3;
      ll c1 = cost(m1), c2 = cost(m2);
      if (c1 >= c2) l = m1;
      if (c1 <= c2) r = m2;
    }
    
    // find the actual minimum
    ll ans = cost(l);
    for (int h = l+1; h <= r; h++) ans = min(ans, cost(h));
    cout << ans << "\n";
  }
}

