// GSS3 - Can you answer these queries III
// Segment tree like GSS1 with extra update function

#include <iostream>

using namespace std;

struct data {
  long long val, tot, pref, suff;
  bool empty = true;
};

data tree[1000001]; // copious space

void combine(data& res, const data& a, const data& b) {
  if (a.empty) res = b;
  else if (b.empty) res = a;
  else {
    res.tot = a.tot + b.tot;
    res.val = max(max(max(a.val, b.val), max(a.tot + b.pref, a.suff + b.tot)), a.suff + b.pref);
    res.pref = max(max(a.pref, a.tot + b.pref), a.tot);
    res.suff = max(max(b.suff, b.tot + a.suff), b.tot);
  }
}

data get(int a, int b, int l, int r, int node) {
  if (a == l && b == r) {
    return tree[node];
  }
  int mid = (l+r)/2;
  if (a <= mid && b <= mid) {
    return get(a, b, l, mid, 2*node);
  } else if (a > mid && b > mid) {
    return get(a, b, mid + 1, r, 2*node + 1);
  } else {
    data res;
    res.empty = false;
    combine(res, get(a, mid, l, mid, 2*node), get(mid + 1, b, mid + 1, r, 2*node + 1));
    return res;
  }
}

void update(int node, long long val) {
  tree[node].val = tree[node].tot = tree[node].pref = tree[node].suff = val;
  for (int i = node/2; i > 0; i /= 2) {
    combine(tree[i], tree[2*i], tree[2*i+1]);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int N;
  cin >> N;
  
  int m = 1;
  while (m < N) m *= 2; // largest power of 2 greater than N
  
  long long e;
  for (int i = 0; i < N; i++) {
    cin >> e;
    tree[m+i].val = tree[m+i].tot = tree[m+i].pref = tree[m+i].suff = e;
    tree[m+i].empty = false;
  }
  
  // build segment tree
  for (int k = m/2; k > 0; k /= 2) {
    for (int i = k; i < 2*k; i++) {
      tree[i].empty = tree[2*i].empty && tree[2*i+1].empty;
      combine(tree[i], tree[2*i], tree[2*i+1]);
    }
  }
  
  // answer queries
  int M, type;
  long long a, b;
  cin >> M;
  for (int q = 0; q < M; q++) {
    cin >> type >> a >> b;
    if (type) {
      cout << get(a, b, 1, m, 1).val << endl;
    } else {
      update(m+a-1, b);
    }
  }
}
