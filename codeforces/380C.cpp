// 380C - Serenja and Brackets
// Segment tree - O((n+q) log n)
// This took *way* too long because I read "substring" instead of "subsequence" :(
#include <bits/stdc++.h>
using namespace std;
struct dat { int best = 0, l = 0, r = 0; };
dat tree[4000000];
void combine(dat& res, dat a, dat b) {
  int comb = min(a.l, b.r);
  res.best = a.best + b.best + 2*comb;
  res.l = a.l + b.l - comb;
  res.r = a.r + b.r - comb;
}
dat get(int a, int b, int node, int l, int r) {
  if (a == l && b == r) return tree[node];
  int mid = (l+r)/2;
  if (a <= mid && b <= mid) {
    return get(a, b, 2*node, l, mid);
  } else if (a > mid && b > mid) {
    return get(a, b, 2*node+1, mid+1, r);
  } else {
    dat res;
    combine(res, get(a, mid, 2*node, l, mid), get(mid+1, b, 2*node+1, mid+1, r));
    return res;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  int m = 1;
  while (m < n) m *= 2;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      tree[i+m].l = 1;
    } else {
      tree[i+m].r = 1; 
    }
  }
  for (int k = m/2; k > 0; k /= 2) {
    for (int i = k; i < 2*k; i++) {
      combine(tree[i], tree[2*i], tree[2*i+1]);
    }
  }
  int Q, a, b;
  cin >> Q;
  while (Q--) {
    cin >> a >> b;
    cout << get(a-1, b-1, 1, 0, m-1).best << "\n";
  }
}
