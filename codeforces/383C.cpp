// 383C - Propagating tree
// Put nodes in 2 arrays by parity of level in pre-order
// Then each subtree (for even/odd-level nodes) corresponds to a contiguous subarray
// We keep track of this subarray by the points we begin/end the subtree during DFS
// For O(log n) updates and retrievals, we use a binary indexed tree on a difference array

#include <iostream>
#include <vector>

using namespace std;

int arr[200000];
vector<int> adj[200001];

bool even[200001];
int sums[2] = {0, 0};
int diffs[2][200001];
int beg[2][200001]; // 1 = even, 0 = odd
int en[2][200001];
int bit[2][200001];

inline int bit_sum(int i, bool ev) {
  int res = 0;
  for (int k = i; k > 0; k -= k&-k) {
    res += bit[ev][k];
  }
  return res;
}

inline void bit_add(int i, bool ev, int v, int num[]) {
  for (int k = i; k <= num[ev]; k += k&-k) {
    bit[ev][k] += v;
  }
}

void dfs(int i[2], int node = 1, bool ev = false) {
  even[node] = ev;
  beg[ev][node] = i[ev];
  beg[!ev][node] = i[!ev];
  diffs[ev][i[ev]] = arr[node-1] - sums[ev];
  sums[ev] += diffs[ev][i[ev]];
  i[ev]++;
  for (int& neigh : adj[node]) {
    dfs(i, neigh, !ev);
  }
  en[ev][node] = i[ev];
  en[!ev][node] = i[!ev];
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> arr[i];
  
  int a, b;
  for (int i = 0; i < n-1; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
  }
  
  int num[] = {1, 1};
  dfs(num);
  num[0]--; num[1]--;
  
  // build BITs from difference arrays
  for (int ev = 0; ev <= 1; ev++) {
    for (int i = 1; i <= num[ev]; i += 2) bit[ev][i] = diffs[ev][i];
    for (int k = 2; k <= num[ev]; k *= 2) {
      for (int i = k; i <= num[ev]; i += 2*k) {
        bit[ev][i] = diffs[ev][i] + bit_sum(i-1, ev);
      }
    }
  }
  
  int type, x, val;
  for (int t = 0; t < m; t++) {
    cin >> type >> x;
    bool ev = even[x];
    if (type == 1) {
      cin >> val;
      bit_add(beg[ev][x], ev, val, num);
      bit_add(en[ev][x], ev, -val, num);
      bit_add(beg[!ev][x], !ev, -val, num);
      bit_add(en[!ev][x], !ev, val, num);
    } else {
      cout << bit_sum(beg[ev][x], ev) << "\n";
    }
  }
}
