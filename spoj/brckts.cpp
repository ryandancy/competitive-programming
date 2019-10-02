// BRCKTS - Brackets
// O(q log n) segment tree
// We keep track of how many open and close brackets there are in each segment

#include <iostream>

using namespace std;

int N, m;
int tree_o[120001]; // segment tree for # open brackets
int tree_c[120001]; // segment tree for # close brackets

inline void combine(int res, int l, int r) {
  int match = min(tree_o[l], tree_c[r]);
  tree_o[res] = tree_o[l] + tree_o[r] - match;
  tree_c[res] = tree_c[l] + tree_c[r] - match;
}

inline void update(int x) { // O(log n)
  swap(tree_o[x], tree_c[x]);
  x /= 2;
  while (x > 0) {
    combine(x, 2*x, 2*x+1);
    x /= 2;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int test = 1;
  while (cin >> N) {
    cin.ignore();
    cout << "Test " << test++ << ":\n";
    
    m = 1;
    while (m < N) m *= 2; // m is smallest power of 2 such that m >= N
    
    for (int i = 0; i < N; i++) {
      if (cin.get() == '(') {
        tree_o[m+i] = 1;
        tree_c[m+i] = 0;
      } else {
        tree_o[m+i] = 0;
        tree_c[m+i] = 1;
      }
    }
    cin.ignore();
    for (int i = N; i < m; i++) { // reset this part of the tree
      tree_o[m+i] = tree_c[m+i] = 0;
    }
    
    for (int k = m/2; k > 0; k /= 2) {
      for (int i = k; i < 2*k; i++) {
        combine(i, 2*i, 2*i+1);
      }
    }
    
    int Q, k;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
      cin >> k;
      if (k == 0) {
        cout << (tree_o[1] == 0 && tree_c[1] == 0 ? "YES\n" : "NO\n");
      } else {
        update(k+m-1);
      }
    }
  }
}
