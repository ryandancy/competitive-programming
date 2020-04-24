// Tree Isomorphism II - are two unrooted trees isomorphic?
// The challenge here is to reliably root the tree, at which point we can use the hashing
// algorithm from Tree Isomorphism I. To root the tree, we start by visiting each leaf, then
// moving inwards only when the node to move into has all but (possibly) one of its neighbours
// visited. This is done simultaneously and in stages, and only one or two neighbouring nodes
// will be visited on the last stage. We cancel any connections between those nodes, then connect
// a designated root node to those nodes. This produces the same root on any isomorphic trees.
// We then hash the rooted trees and compare. Time complexity: O(n).
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
vector<int> adj1[110000], adj2[110000];
int v1[110000]={0}, v2[110000]={0};
bool nv1[110000]={false}, nv2[110000]={false};
bool ca1[110000]={false}, ca2[110000]={false};
int n,o=0;
const ull A1=989998067LL, A2=997984067LL, B1=999698803LL, B2=999998107LL;
struct it {
  vector<it*> ch;
  it(bool fake) : nohash{true}, fake{fake} {}
  void print() {
    cout<<ch.size()<<" children(fake="<<fake<<"):\n";
    for (it* c : ch) c->print();
  }
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
  bool nohash, fake;
  void cmphashes() {
    nohash = false;
    hash1 = A1, hash2 = A2;
    sort(ch.begin(), ch.end(), [&] (it* a, it* b) {return a->gethash1() < b->gethash1();});
    for (it* c : ch) {
      hash1 += c->gethash1();
      hash1 %= B1;
    }
    hash1 *= A1 + 1764951221LL * ch.size() + (8528723754LL * fake);
    hash1 %= B1;
    sort(ch.begin(), ch.end(), [&] (it* a, it* b) {return a->gethash2() < b->gethash2();});
    for (it* c : ch) {
      hash2 += c->gethash2();
      hash2 %= B2;
    }
    hash2 *= A2 + 8957612961LL * ch.size() + (795127501LL * fake);
    hash2 %= B2;
  }
};
it* mkit(vector<int> adj[], bool v[], int c, bool fk=true) {
  it* t = new it{fk};
  for (int nb : adj[c]) {
    if (!v[nb]) {
      v[nb] = true;
      t->ch.push_back(mkit(adj, v, nb, false));
    }
  }
  return t;
}
int nxt(vector<int> adj[], int v[], int pt) {
  // -1==too many, -2==zero
  int res = -2;
  for (int nb : adj[pt]) {
    if (!v[nb]) {
      if (res < 0) {
        res = nb;
      } else {
        return -1;
      }
    }
  }
  return res;
}
void mk_canonical_root(vector<int> adj[], int v[], bool ca[]) {
  list<int> pts;
  for (int i=o;i<o+n;i++){
    if (adj[i].size()==1){
      pts.push_back(i);
      v[i]=1;
    }
  }
  int t=2, mxt=1;
  while (pts.size()) {
    for (auto it = pts.begin(); it != pts.end();) {
      int nx = nxt(adj, v, *it);
      if (nx == -2) {
        it = pts.erase(it);
        continue;
      }
      if (nxt(adj, v, nx) != -1) {
        ca[*it]=true;
      }
      ++it;
    }
    for (auto it = pts.begin(); it != pts.end();) {
      if (ca[*it]) {
        *it = nxt(adj, v, *it);
        assert(*it != -1);
        if (*it == -2 || v[*it]) {
          it = pts.erase(it);
        } else {
          mxt = v[*it] = t;
          ++it;
        }
      } else ++it;
    }
    t++;
  }
  int mx1=-1, mx2=-1;
  for (int i=o;i<o+n;i++) {
    if (v[i]==mxt) {
      if (mx1==-1) mx1=i;
      else {
        assert(mx2==-1); // only 2
        mx2=i;
      }
    }
  }
  assert(mx1!=-1);
  int rt=o+n;
  if (mx2!=-1){
    adj[mx1].erase(remove(adj[mx1].begin(), adj[mx1].end(), mx2), adj[mx1].end());
    adj[mx2].erase(remove(adj[mx2].begin(), adj[mx2].end(), mx1), adj[mx2].end());
    adj[rt].push_back(mx2);
    adj[mx2].push_back(rt);
  }
  adj[rt].push_back(mx1);
  adj[mx1].push_back(rt);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin>>T;
  while (T--){
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
    mk_canonical_root(adj1, v1, ca1);
    mk_canonical_root(adj2, v2, ca2);
    nv1[o+n] = nv2[o+n] = true;
    it *ita = mkit(adj1, nv1, o+n), *itb = mkit(adj2, nv2, o+n);
    // cout<<"A:\n"; ita->print();
    // cout<<"B:\n"; itb->print();
    cout<<(ita->gethash1()==itb->gethash1() && ita->gethash2()==itb->gethash2() ? "YES\n" : "NO\n");
    o+=n+1;
  }
}
