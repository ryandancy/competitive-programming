// LCA - Lowest Common Ancestor
// We store the tree as an array of parent elements
// We also store each element's depth in the node
// To find the LCA of a and b, we move up until a and b are on the same level,
// then move them up together until they're equal
// O(NQ) but okay since N and Q are small

#include <iostream>

using namespace std;

int parents[1000];
int levels[1000];

inline int lca(int a, int b) {
  while (levels[a] < levels[b]) b = parents[b];
  while (levels[a] > levels[b]) a = parents[a];
  while (a != b) {
    a = parents[a];
    b = parents[b];
  }
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  levels[0] = 0;
  parents[0] = -1;
  
  int cases;
  cin >> cases;
  for (int cas = 0; cas < cases; cas++) {
    cout << "Case " << cas+1 << ":\n";
    
    int N, M, e;
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> M;
      for (int j = 0; j < M; j++) {
        cin >> e;
        parents[e-1] = i;
        levels[e-1] = levels[i] + 1;
      }
    }
    
    int Q, a, b;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
      cin >> a >> b;
      cout << lca(a-1, b-1) + 1 << "\n";
    }
  }
}
