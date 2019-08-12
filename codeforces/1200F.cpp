// 1200F - Graph Traveler
// Since each node can have outdegree between 1 and 10 inclusive,
// the number of possible combinations of (x mod 1), (x mod 2), ..., (x mod 10)
// is LCM(1, 2, ..., 10) = 2520, representing x between 0 and 2519, and so we
// can transform each node into 2520 nodes, each with outdegree 1.
// We thus obtain a successor graph in which each component contains exactly
// one cycle. We determine the unique nodes in each cycle in O(n) time and
// can then answer queries in O(1) time.
// Note: this was NOT created during the contest

#include <iostream>
#include <stack>

using namespace std;

int adj[2520001]; // n=0: 0..2519, n=1: 2520..5039; n: 2520n..2520(n+1)-1; n/2520 gives node number
int ks[1000];
int es[10];
int ans[2520001] = {0}; // 0 = unvisited, -1 = visited, >0 = answer
bool found[1000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> ks[i];
  
  // generate successor graph
  int m, e;
  for (int i = 0; i < n; i++) {
    cin >> m;
    for (int j = 0; j < m; j++) {
      cin >> e;
      es[j] = e-1;
    }
    for (int c = 0; c < 2520; c++) {
      int newc = (c+ks[es[c%m]])%2520; // add on incoming - thus remember to add initial c
      if (newc < 0) newc += 2520;
      adj[2520*i+c] = 2520*es[c%m] + newc;
    }
  }
  
  // find answers from successor graph
  stack<int> path;
  for (int i = 0; i < 2520*n; i++) { // O(n) since each node is processed at most twice
    if (ans[i] > 0) continue;
    
    int curr = i;
    do {
      path.push(curr);
      ans[curr] = -1;
      curr = adj[curr];
    } while (ans[curr] == 0);
    
    int answer;
    if (ans[curr] == -1) {
      // we've found a cycle - pass through the cycle again and compute the answer
      fill_n(found, n, false);
      int cyc = curr;
      answer = 0;
      do {
        if (!found[cyc/2520]) answer++;
        found[cyc/2520] = true;
        cyc = adj[cyc];
      } while (cyc != curr);
    } else {
      // we've already computed an answer for this component
      answer = ans[curr];
    }
    
    // rewind the answer to the rest of the path
    while (path.size()) {
      curr = path.top();
      path.pop();
      ans[curr] = answer;
    }
  }
  
  // process queries in O(1) by referring to ans
  int q, x, y;
  cin >> q;
  while (q--) {
    cin >> x >> y;
    
    int sc = (y+ks[x-1])%2520;
    if (sc < 0) sc += 2520;
    int st = 2520*(x-1) + sc;
    
    cout << ans[st] << endl;
  }
}
