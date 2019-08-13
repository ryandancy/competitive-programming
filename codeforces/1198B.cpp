// 1198B - Welfare State
// Lazy segment tree - O(1) type 1, O(log n) type 2, O(n log n) update at end
// Overall - O((n+q) log n)

#include <iostream>
#include <stack>

using namespace std;

int upd[8000001] = {0};

int main() {
  int n;
  cin >> n;
  
  int m = 1;
  while (m < n) m *= 2; // m is start of leaf nodes
  
  for (int i = 0; i < n; i++) {
    cin >> upd[m+i];
  }
  
  int q;
  cin >> q;
  
  stack<int> stk;
  
  int type, p, x;
  while (q--) {
    cin >> type;
    if (type == 1) {
      cin >> p >> x;
      // update from the top down; stack for updating in proper order
      for (int node = (m+p-1)/2; node > 0; node /= 2) {
        stk.push(node);
      }
      while (stk.size()) {
        int node = stk.top();
        stk.pop();
        upd[2*node] = max(upd[node], upd[2*node]);
        upd[2*node+1] = max(upd[node], upd[2*node+1]);
        upd[node] = 0;
      }
      upd[m+p-1] = x;
    } else {
      cin >> x;
      // push for lazy evaluation
      upd[1] = max(upd[1], x);
    }
  }
  
  // flush all the lazy updates before printing
  for (int i = 1; i < m; i++) {
    upd[2*i] = max(upd[i], upd[2*i]);
    upd[2*i+1] = max(upd[i], upd[2*i+1]);
  }
  
  for (int i = 0; i < n; i++) {
    cout << upd[m+i] << (i == n-1 ? "\n" : " ");
  }
}
