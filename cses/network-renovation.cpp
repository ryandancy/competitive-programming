// Network Renovation - given a tree, find the minimum-size set of edges to
// add to make the graph 2-connected.
// First, note that vertices of degree 2 are irrelevant; remove these and
// replace with a single edge. (This is done implicitly here.)
// We then transform the tree into a "leaf-list" tree: every vertex of
// degree >= 3 is changed to a list of leaf vertices connected to it.
// If in this leaf-list tree a leaf-list vertex is itself a leaf, we call
// it a metaleaf. Note that all metaleaf leaf-lists must contain at least
// 2 leaves, as otherwise it would be of degree 2.
// We take two leaves from each metaleaf's leaf-list and connect them
// circularly, connecting the second leaf in one pair to the first leaf in
// the next pair, etc. We then connect the rest of the leafs to each other
// arbitrarily and if there are an odd number of leafs, we connect the last
// pseudo-arbitrarily. Time complexity: O(n).

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  
  // input tree
  vector<int> adj[100000];
  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  // transform into leaf-list representation
  vector<int> lladj[100000], lls[100000];
  int root = -1;
  for (int i = 0; i < n; i++) {
    if (adj[i].size() >= 3) {
      if (root == -1) root = i;
      for (int nb : adj[i]) {
        int last = i;
        while (adj[nb].size() == 2) {
          int nxt = (adj[nb][0] == last) ? adj[nb][1] : adj[nb][0];
          last = nb;
          nb = nxt;
        }
        if (adj[nb].size() == 1) {
          lls[i].push_back(nb);
        } else {
          lladj[i].push_back(nb);
        }
      }
    }
  }
  
  if (root == -1) {
    // fully linear: connect the two endpoints
    int l1 = -1, l2 = -1;
    for (int i = 0; i < n; i++) {
      if (adj[i].size() == 1) {
        if (l1 == -1) {
          l1 = i;
        } else {
          l2 = i;
          break;
        }
      }
    }
    
    cout << "1\n" << l1+1 << " " << l2+1 << "\n";
    return 0;
  }
  
  // find pairs of leaves in metaleaves and put the rest in ext
  vector<int> ext;
  vector<pair<int, int>> lvs;
  for (int i = 0; i < n; i++) {
    if (lladj[i].size() == 1) {
      // metaleaf
      lvs.push_back({lls[i][0], lls[i][1]});
      for (int j = 2; j < lls[i].size(); j++) {
        ext.push_back(lls[i][j]);
      }
    } else {
      for (int lf : lls[i]) {
        ext.push_back(lf);
      }
    }
  }
  
  // connect metaleaf pairs circularly
  vector<pair<int, int>> res;
  for (int i = 0; i < lvs.size(); i++) {
    int j = (i + 1) % lvs.size();
    res.push_back({lvs[i].second, lvs[j].first});
  }
  
  // connect ext in pairs, and an odd one arbitrarily
  for (int i = 0; i+1 < ext.size(); i += 2) {
    res.push_back({ext[i], ext[i+1]});
  }
  if (ext.size() % 2 == 1) {
    // connect to root, or some connected to root if already connected
    int e = ext.back();
    int o = -1;
    bool needo = false;
    for (int nb : adj[root]) {
      int last = root;
      while (adj[nb].size() == 2) {
        int nxt = (adj[nb][0] == last) ? adj[nb][1] : adj[nb][0];
        last = nb;
        nb = nxt;
      }
      if (nb == e) needo = true;
      else o = nb;
    }
    res.push_back({e, needo ? o : root});
  }
  
  // print
  cout << res.size() << '\n';
  for (pair<int, int>& p : res) {
    cout << p.first + 1 << ' ' << p.second + 1 << '\n';
  }
}
