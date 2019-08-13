// 1198C - Matching vs Independent Set
// For each, if we construct a matching greedily, either the matching is
// at least of size n, or since there are 3*n vertices, less than 2*n of
// which are covered by the matching, the remaining vertices form an
// independent set of size at least n.
// To avoid clearing 3*n spaces each time, we store a value s that is the
// start of the vertices for the graph and add 3*n each time.

#include <iostream>
#include <vector>

using namespace std;

bool v[300000] = {false};
vector<int> mat;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int T, s = 0;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    mat.clear();
    
    int a, b;
    for (int i = 1; i <= m; i++) {
      cin >> a >> b;
      if (!v[s+a-1] && !v[s+b-1]) {
        v[s+a-1] = v[s+b-1] = true;
        mat.push_back(i);
      }
    }
    
    if (mat.size() >= n) {
      cout << "Matching\n";
      for (int i = 0; i < n; i++) {
        cout << mat[i] << (i == n-1 ? "\n" : " ");
      }
    } else {
      mat.clear();
      for (int i = 0, num = 0; i < 3*n; i++) {
        if (!v[s+i]) {
          num++;
          mat.push_back(i+1);
          if (num == n) break;
        }
      }
      if (mat.size() >= n) {
        cout << "IndSet\n";
        for (int i = 0; i < n; i++) {
          cout << mat[i] << (i == n-1 ? "\n" : " ");
        }
      } else {
        cout << "Impossible\n";
      }
    }
    
    s += 3*n;
  }
}
