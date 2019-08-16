// 339D - Xenia and Bit Operations
// Segment tree, choosing bit operation based on level and reading from tree[1].
// O(n log n) initialization, O(log n) queries gives O((n+m) log n)
// Solved in 13:25 (woot!)

#include <bits/stdc++.h>
using namespace std;

int tree[4*(1<<17)+1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;
  
  // Set x = 2^n
  int x = 1;
  for (int i = 0; i < n; i++) x *= 2;
  
  // Input into tree
  for (int i = 0; i < x; i++) {
    cin >> tree[i+x];
  }
  
  // Build tree
  for (int k = x/2, o = 1; k > 0; k /= 2, o++) {
    for (int i = k; i < 2*k; i++) {
      if (o % 2) tree[i] = tree[2*i] | tree[2*i+1];
      else tree[i] = tree[2*i] ^ tree[2*i+1];
    }
  }
  
  int p, b;
  while (m--) {
    cin >> p >> b;
    
    // Update tree
    tree[p+x-1] = b;
    int nd = (p+x-1)/2, o = 1;
    
    while (nd > 0) {
      if (o % 2) tree[nd] = tree[2*nd] | tree[2*nd+1];
      else tree[nd] = tree[2*nd] ^ tree[2*nd+1];
      o++; nd /= 2;
    }
    
    // Answer is at root of tree
    cout << tree[1] << "\n";
  }
}
