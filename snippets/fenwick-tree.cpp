#include <bits/stdc++.h>
typedef long long ll;

// A Fenwick tree (Binary Indexed Tree, BIT) supports some range queries on [0, x)
// in O(log n) with O(n log n) setup, and is simpler than a segment tree.
// Indices internally start at 1 and each element stores ranges like so:
// 1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16
// --    --    --    --    --     --      --      --
// -----       -----       -----          ------
// -----------             -------------
// -----------------------
// -----------------------------------------------------
// Basically prefix sums with O(log n) query and update.
// See CP3 2.4.4.

// add(x, v) adds v to index x in O(log n).
// sum(x) sums indices [0, x) in O(log n). Could be extended for other operations.

#define N 100000

ll bit[N+1]={0};

void add(ll x, ll v) { // O(log n) add v to index x
  x++;
  while (x<=N) {
    bit[x]+=v;
    x+=x&-x;
  }
}

ll sum(ll x) { // O(log n) sum [0, x)
  x++;
  ll res=0;
  while (x>0) {
    res+=bit[x]; // could do other operation
    x-=x&-x;
  }
  return res;
}

// setup fenwick tree, should be done in main
void setup(ll a[N]) {
  for (ll i=0;i<N;i++) add(i,a[i]);
}
