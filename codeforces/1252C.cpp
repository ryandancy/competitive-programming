// 1252C - Even Path
// Nice and simple - note the identity of r[i]/c[i] doesn't matter, only if it's even or odd,
// so we store that. The even/odd sum pattern produced is: each row is R, but if c[i] == 1, it's
// bitwise inverted. This leads to a pattern where for (ra, ca) and (rb, cb) to be connected,
// we need them to have the same combination of r/c (both odd or both even same for both points)
// and we need there to not be another block in between, which we accomplish by keeping counts
// of 0s and 1s in r and c. O(1) queries for O(N+Q) time complexity.
#include <bits/stdc++.h>
using namespace std;
bool r[100000], c[100000];
int r0c[100000], r1c[100000], c0c[100000], c1c[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int N, Q;
  cin >> N >> Q;
  int x;
  cin >> x;
  r[0] = x%2;
  r0c[0] = x%2 == 0;
  r1c[0] = x%2;
  for (int i = 1; i < N; i++) {
    cin >> x;
    r[i] = x%2;
    r0c[i] = r0c[i-1] + (x%2==0);
    r1c[i] = r1c[i-1] + (x%2);
  }
  cin >> x;
  c[0] = x%2;
  c0c[0] = x%2==0;
  c1c[0] = x%2;
  for (int i = 1; i < N; i++) {
    cin >> x;
    c[i] = x%2;
    c0c[i] = c0c[i-1] + (x%2==0);
    c1c[i] = c1c[i-1] + (x%2);
  }
  int ra, rb, ca, cb;
  while (Q--) {
    cin >> ra >> ca >> rb >> cb;
    ra--; ca--; rb--; cb--;
    if (r[ra] != r[rb] || c[ca] != c[cb]) {
      cout << "NO\n";
      continue;
    }
    if (!r[ra]) {
      if (r1c[ra] != r1c[rb]) {cout << "NO\n"; continue;}
    } else if (r0c[ra] != r0c[rb]) { cout << "NO\n"; continue;}
    if (!c[ca]) {
      if (c1c[ca] != c1c[cb]) {cout << "NO\n"; continue;}
    } else if (c0c[ca] != c0c[cb]) {cout << "NO\n"; continue;}
    cout << "YES\n";
  }
}
