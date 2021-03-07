#include <bits/stdc++.h>
typedef long long ll;

// Union-find (disjoint-set union, union-find disjoint set) models disjoint sets of ints [0, N).
// For each int x in [0, N), uf[x] is its parent in the same set.
// The representative of the set (the root of the tree) is the one where uf[r] == r, i.e. it's its own parent.
// For a representative r, sz[r] is the size of the set.
// See CP3 2.4.2.

// find(x) returns the representative for the set where x is.
// unite(x, y) merges the sets containing x and y.
// Time complexity for both: O(n*a(n)) where a(n) is the inverse Ackermann function, a(n) <= 5 for practical use.

#define N 100000

ll uf[N], sz[N];

// initialize the union find array, should be done in main
void init() {
  for (ll i=0;i<N;i++) uf[i]=i,sz[i]=1;
}

ll find(ll x) {
  return uf[x]==x?x:uf[x]=find(x);
}

void unite(ll x, ll y) {
  x=find(x),y=find(y);
  if (x==y) return;
  if (sz[x]<sz[y]) swap(x,y);
  uf[y]=x,sz[x]+=sz[y];
}
