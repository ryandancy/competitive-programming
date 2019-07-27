// HORRIBLE - Horrible Queries
// Lazy segment tree - O(log n) queries and updates
// For some reason segment tree size 4*N doesn't work, but 40*N does, so ???

#include <iostream>

typedef long long int ll;

using namespace std;
  
ll sumtree[4000001]; // segment tree of "real" sums
ll updtree[4000001]; // segment tree of additions waiting

inline void propagate(ll node, ll a, ll b) {
  if (updtree[node]) {
    sumtree[node] += updtree[node] * (b - a + 1);
    updtree[node*2] += updtree[node];
    updtree[node*2 + 1] += updtree[node];
    updtree[node] = 0;
  }
}

void add(const ll& l, const ll& r, const ll& v, ll node, ll a, ll b) {
  if (l > r) return;
  if (l <= a && b <= r) {
    updtree[node] += v;
    return;
  }
  propagate(node, a, b);
  ll isec;
  if (l < a) {
    isec = r - a + 1;
  } else if (b < r) {
    isec = b - l + 1;
  } else {
    isec = r - l + 1;
  }
  sumtree[node] += isec * v;
  if (a == b) return;
  ll mid = (a+b)/2;
  if (l < mid && r < mid) {
    add(l, r, v, node*2, a, mid);
  } else if (l > mid && r > mid) {
    add(l, r, v, node*2 + 1, mid + 1, b);
  } else {
    add(l, mid, v, node*2, a, mid);
    add(mid + 1, r, v, node*2 + 1, mid + 1, b);
  }
}

ll sum(const ll& l, const ll& r, ll node, ll a, ll b) {
  if (l > r) return 0;
  propagate(node, a, b);
  if (l <= a && b <= r) {
    return sumtree[node];
  }
  ll mid = (a+b)/2;
  if (l < mid && r < mid) {
    return sum(l, r, node*2, a, mid);
  } else if (l > mid && r > mid) {
    return sum(l, r, node*2 + 1, mid + 1, b);
  } else {
    return sum(l, mid, node*2, a, mid) + sum(mid + 1, r, node*2 + 1, mid + 1, b);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int T;
  cin >> T;
  
  for (int t = 0; t < T; t++) {
    ll N, C;
    cin >> N >> C;
    
    fill(sumtree, sumtree+4000001, 0L);
    fill(updtree, updtree+4000001, 0L);
    
    ll type, l, r, v;
    for (int c = 0; c < C; c++) {
      cin >> type >> l >> r;
      if (type) {
        cout << sum(l, r, 1, 1, N) << endl;
      } else {
        cin >> v;
        add(l, r, v, 1, 1, N);
      }
    }
  }
}
