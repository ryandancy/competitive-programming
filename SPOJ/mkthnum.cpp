// MKTHNUM - K-th number
// Merge segment tree - O(n log n) initialization, O(m log^2 n) queries

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int arr[100000];
pii sorted[100000];
vector<int> tree[400001];

void merge(vector<int>& res, vector<int>& a, vector<int>& b) {
  auto ai = a.begin(), bi = b.begin();
  while (ai != a.end() || bi != b.end()) {
    if (ai == a.end()) {
      res.push_back(*bi++);
    } else if (bi == b.end()) {
      res.push_back(*ai++);
    } else if (*ai < *bi) {
      res.push_back(*ai++);
    } else {
      res.push_back(*bi++);
    }
  }
}

int orderStat(int l, int r, int k, int node, int m) {
  if (node >= m) {
    return arr[tree[node][0]];
  }
  
  // number of elements in [l, r] in left subtree
  int nls = upper_bound(tree[2*node].begin(), tree[2*node].end(), r)
    - lower_bound(tree[2*node].begin(), tree[2*node].end(), l);
  
  if (nls >= k) {
    return orderStat(l, r, k, 2*node, m);
  } else {
    return orderStat(l, r, k-nls, 2*node + 1, m);
  }
}

int main() {
  int N, Q;
  cin >> N >> Q;
  
  int m = 1;
  while (m < N) m *= 2;
  
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    sorted[i].first = arr[i];
    sorted[i].second = i;
  }
  
  sort(sorted, sorted+N);
  
  for (int i = 0; i < N; i++) {
    tree[m+i].push_back(sorted[i].second);
  }
  
  for (int k = m/2; k > 0; k /= 2) {
    for (int i = k; i < 2*k; i++) {
      merge(tree[i], tree[2*i], tree[2*i+1]);
    }
  }
  
  int l, r, k;
  for (int i = 0; i < Q; i++) {
    cin >> l >> r >> k;
    cout << orderStat(l-1, r-1, k, 1, m) << "\n";
  }
}
