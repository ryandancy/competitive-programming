// SOPARADE - Soldiers on Parade
// The idea is to see if we can get a valid arrangement by trying and backtracking
// We start with x1=1, then iterate through possible subsequent values using a stack
// For the various rules, we use a map (array) of places to rules using the place for O(1) lookup
// If we encounter an impossible scenario, we backtrack to the next position on the stack
// Also, since xn=1 and xn=2 are symmetric with xn=4 and xn=3 respectively, we only need to test x1=1,2

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int rules[100000][4];
int vals[100000];
vector<int> p2r[100000]; // places to indices of rules that invoke it

void push(stack<pair<int, int>>& stk, int p) {
  switch (vals[p-1]) {
    case 1: stk.push({p, 3}); stk.push({p, 4}); break;
    case 2: stk.push({p, 4}); break;
    case 3: stk.push({p, 1}); break;
    case 4: stk.push({p, 1}); stk.push({p, 2}); break;
  }
}

bool search(int n) {
  stack<pair<int, int>> stk; // (p, pVal) iff there's another to test
  push(stk, 1);
  
  pair<int, int> top;
  int p, pVal;
  while (!stk.empty()) {
    top = stk.top();
    stk.pop();
    p = top.first; pVal = top.second;
    
    if (p >= n) return true;
    
    for (int& r : p2r[p]) {
      for (int i = 0; i < 4; i++) {
        int o = rules[r][i];
        if (o < 0) break;
        if (o >= p) continue;
        if (vals[o] == pVal) goto nextitem;
      }
    }
    
    vals[p] = pVal;
    push(stk, p+1);
    
    nextitem:;
  }
  
  return false;
}

bool ok() {
  int n, nr;
  cin >> n >> nr;
  
  // clear out p2r
  for (int i = 0; i < n; i++) p2r[i].clear();
  
  int a, b;
  for (int r = 0; r < nr; r++) {
    cin >> b;
    fill(rules[r], rules[r]+4, -1);
    for (int i = 0, c = 0; i < b; i++, c++) {
      cin >> a;
      
      // ignore it if it's a duplicate
      bool dupe = false;
      for (int j = 0; j < 4; j++) {
        if (a == rules[r][j]) {
          dupe = true;
          break;
        }
      }
      
      if (dupe) c--;
      else {
        rules[r][c] = --a;
        p2r[a].push_back(r);
      }
    }
  }
  
  // it's symmetric for x1 = 1,4 and x1 = 2,3, so we only have to test x1 = 1,2
  for (int f = 1; f <= 2; f++) {
    vals[0] = f;
    if (search(n)) {
      return true;
    }
  }
  
  return false;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cout << (ok() ? "approved" : "rejected") << endl;
  }
}
