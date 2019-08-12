// NAJPF - Pattern Find
// KMP algorithm for pattern matching - O(|a|+|b|)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int fail[1000001];
char a[1000001];
char b[1000001];

inline void genfail() { // generate failure array from b - O(|b|)
  fail[0] = 0;
  int j = 0;
  for (int i = 1; b[i]; i++) {
    while (j > 0 && b[i] != b[j]) {
      j = fail[j-1];
    }
    if (b[i] == b[j]) fail[i] = ++j;
    else fail[i] = 0; // j == 0
  }
}

int main() {
  int T;
  cin >> T;
  
  while (T--) {
    cin >> a >> b;
    genfail();
    
    vector<int> idxs;
    
    int pa = 0, pb = 0;
    while (a[pa]) { // KMP main algorithm - O(|a|)
      if (a[pa] == b[pb]) {
        pa++; pb++;
        if (!b[pb]) {
          // reset after finding an instance of b
          idxs.push_back(pa-pb+1);
          pa -= pb-1; // start matching from next character after this match
          pb = 0;
        }
      } else if (pb == 0) {
        pa++;
      } else {
        pb = fail[pb-1];
      }
    }
    
    if (idxs.size()) {
      cout << idxs.size() << "\n";
      for (int i = 0; i < idxs.size(); i++) {
        cout << idxs[i];
        if (i < idxs.size()-1) cout << " ";
      }
      cout << "\n";
    } else {
      cout << "Not Found\n";
    }
    
    if (T > 0) cout << "\n";
  }
}
