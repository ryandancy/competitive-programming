// 158C - Cd and pwd commands
// We create a trie-like structure to hold the directory structure.
// For pwd, we move upwards to root, holding the names in a stack.
// For cd, we move into available directories if possible, and else create them.
// Note: the memory safety was not done in the submitted version.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct trie {
  string name;
  unordered_map<string, trie*> children;
  trie* parent = nullptr;
  ~trie() { // rule of three/five be danged, we're not copying anything
    for (auto& child : children) {
      delete child.second;
      child.second = nullptr;
    }
    parent = nullptr;
  }
};
trie* root;
trie* curr;
stack<string> p;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  root = new trie;
  curr = root;
  int n;
  cin >> n;
  string cmd, pth;
  for (int i = 0; i < n; i++) {
    cin >> cmd;
    if (cmd == "pwd") {
      trie* c = curr;
      while (c) {
        p.push(c->name);
        c = c->parent;
      }
      while (p.size()) {
        cout << p.top() << "/";
        p.pop();
      }
      cout << endl;
    } else {
      cin >> pth;
      int i = 0;
      if (pth[0] == '/') {
        curr = root;
        i++;
      }
      string cd;
      while (i < pth.size()) {
        while (i < pth.size() && pth[i] != '/') {
          cd += pth[i++];
        }
        i++;
        if (cd == "..") {
          curr = curr->parent;
        } else {
          if (curr->children.count(cd)) {
            curr = curr->children[cd];
          } else {
            trie** nu = &curr->children[cd];
            *nu = new trie;
            (*nu)->parent = curr;
            (*nu)->name = cd;
            curr = *nu;
          }
        }
        cd.clear();
      }
    }
  }
  delete root;
}