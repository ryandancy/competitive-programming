// Tree Isomorphism I - are two rooted trees isomorphic?
// We recursively compute a hash for each tree which doesn't take into account
// the labels or the orders of children. Probably a bit overkill, but it's ok.
// Time complexity: O(n)
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
vector<int> adj1[100000], adj2[100000];
bool v1[100000]={false}, v2[100000]={false};
int n, o=0;
const ull A1=989998067LL, A2=997984067LL, B1=999698803LL, B2=999998107LL;
struct it {
  vector<it*> ch;
  it() : nohash(true) {}
  ull gethash1() {
    if (nohash) cmphashes();
    return hash1;
  }
  ull gethash2() {
    if (nohash) cmphashes();
    return hash2;
  }
private:
  ull hash1, hash2;
  bool nohash;
  void cmphashes() {
    nohash = false;
    hash1 = A1, hash2 = A2;
    sort(ch.begin(), ch.end(), [&] (it* a, it* b) {return a->gethash1() < b->gethash1();});
    for (it* c : ch) {
      hash1 += c->gethash1();
      hash1 %= B1;
    }
    hash1 *= A1 + 1764951221LL * ch.size();
    hash1 %= B1;
    sort(ch.begin(), ch.end(), [&] (it* a, it* b) {return a->gethash2() < b->gethash2();});
    for (it* c : ch) {
      hash2 += c->gethash2();
      hash2 %= B2;
    }
    hash2 *= A2 + 8957612961LL * ch.size();
    hash2 %= B2;
  }
};
it* mkit(vector<int> adj[], bool v[], int c) {
  it* t = new it;
  for (int nb : adj[c]) {
    if (!v[nb]) {
      v[nb] = true;
      t->ch.push_back(mkit(adj, v, nb));
    }
  }
  return t;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin>>T;
  while (T--) {
    cin>>n;
    for (int i=0;i<n-1;i++){
      int a,b;
      cin>>a>>b;
      a--, b--;
      adj1[o+a].push_back(o+b);
      adj1[o+b].push_back(o+a);
    }
    for (int i=0;i<n-1;i++){
      int a,b;
      cin>>a>>b;
      a--, b--;
      adj2[o+a].push_back(o+b);
      adj2[o+b].push_back(o+a);
    }
    v1[o] = v2[o] = true;
    it* ita = mkit(adj1, v1, o);
    it* itb = mkit(adj2, v2, o);
    cout << (ita->gethash1() == itb->gethash1() && ita->gethash2() == itb->gethash2() ? "YES" : "NO") << '\n';
    o+=n;
  }
}
