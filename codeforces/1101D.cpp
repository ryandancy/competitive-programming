// 1101D - GCD Counting
// The only way we can output 0 is if all tree elements are 1; otherwise, the output is at least 1.
// Note that a chain of elements with GCD > 1 has at least one prime factor in common. We may split
// the tree into many subtrees by prime factor - all the vertices divisible by 2, say, form a forest
// within the main tree. We check each tree within each of these forests for the longest path. For
// each node, we find the prime factors in O(sqrt n). For each distinct prime factor, if the relevant
// chain has not yet been visited, we perform two breadth-first searches on the tree created by the
// nodes also divisible by this prime factor to find its diameter. O(np sqrt n) where p is the maximum
// number of distinct prime factors an element can have given the limit on the size of the elements -
// in this case, 6 since 2*3*5*7*11*13 < 2*10^5 < 2*3*5*7*11*13*17.
#include <bits/stdc++.h>
using namespace std;
unordered_set<int> vis[200000];
int bst = 1;
int arr[200000];
vector<int> adj[200000];
queue<int> ns, ls, lsts;
inline void process(int c, int i) {
  if (vis[i].count(c)) return;
  int bsth = 0, bnd = -1; // BFS #1 - O(n)
  ns.push(i);
  ls.push(1);
  lsts.push(-1);
  int nd, lvl, lst;
  while (ns.size()) {
    nd = ns.front(); ns.pop();
    lvl = ls.front(); ls.pop();
    lst = lsts.front(); lsts.pop();
    vis[nd].insert(c);
    bool fnd = false;
    for (int& neigh : adj[nd]) {
      if (neigh == lst || arr[neigh] % c != 0) continue;
      fnd = true;
      ns.push(neigh);
      ls.push(lvl+1);
      lsts.push(nd);
    }
    if (!fnd) {
      if (lvl > bsth) {
        bsth = lvl;
        bnd = nd;
      }
    }
  }
  bsth = 0;
  ns.push(bnd); // BFS #2 - O(n)
  ls.push(1);
  lsts.push(-1);
  while (ns.size()) {
    nd = ns.front(); ns.pop();
    lvl = ls.front(); ls.pop();
    lst = lsts.front(); lsts.pop();
    vis[nd].insert(c);
    bool fnd = false;
    for (int& neigh : adj[nd]) {
      if (neigh == lst || arr[neigh] % c != 0) continue;
      fnd = true;
      ns.push(neigh);
      ls.push(lvl+1);
      lsts.push(nd);
    }
    if (!fnd) {
      if (lvl > bsth) {
        bsth = lvl;
      }
    }
  }
  bst = max(bst, bsth);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  bool all1 = true;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] != 1) all1 = false;
  }
  if (all1) {
    cout << "0\n";
    return 0;
  }
  int a, b;
  for (int i = 0; i < n-1; i++) {
    cin >> a >> b;
    a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    int x = arr[i];
    if (x == 1) continue;
    for (int c = 2; c*c <= x; c++) { // Get prime factors - O(sqrt n)
      if (x%c == 0) {
        process(c, i);
        do {
          x /= c;
        } while (x%c == 0);
      }
    }
    if (x > 1) {
      process(x, i);
    }
  }
  cout << bst << "\n";
}
