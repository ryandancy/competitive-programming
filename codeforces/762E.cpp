// 762E - Radio Stations
// This was actually written as a partial solution for 1045G - AI Robots,
// but that problem allows multiple robots/stations at the same positions.
// See 1045G.cpp for explanation.
// (I suppose for this problem, the q-compression stuff isn't necessary,
// but it works, so whatever.)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct bot {
  int x, r, oq, q;
};
bool qcomp(bot& a, bot& b) {
  return a.oq < b.oq;
}
bool xcomp(bot& a, bot& b) { return a.x < b.x; }
bool lcomp(bot& a, bot& b) { return a.x-a.r < b.x-b.r; }
bool rcomp(bot& a, bot& b) { return a.x+a.r < b.x+b.r; }
bot b[100000];
pair<int, bot> l[100000], x[100000], r[100000];
int qlt[100000];
static unsigned g_seed;
inline int fastrand() {
  g_seed = (214013*g_seed+2531011);
  return (g_seed>>16)&0x7FFF;
}
struct node {
  int key, prior;
  node(int key, int prior) : key(key), prior(prior) {}
  node* l = nullptr, * r = nullptr;
  int cnt = 1;
};
node* rts[100000] = {nullptr};
int cnt(node* t) {
  return t ? t->cnt : 0;
}
void upd_cnt(node* t) {
  if (t) t->cnt = 1 + cnt(t->l) + cnt(t->r);
}
void split(node* t, int key, node*& l, node*& r) {
  if (!t) l = r = nullptr;
  else if (key < t->key) split(t->l, key, l, t->l), r = t;
  else split(t->r, key, t->r, r), l = t;
  upd_cnt(t);
}
void merge(node*& t, node* l, node* r) {
  if (!l || !r) t = l ? l : r;
  else if (l->prior > r->prior) merge(l->r, l->r, r), t = l;
  else merge(r->l, l, r->l), t = r;
  upd_cnt(t);
}
void insert(node*& t, node* it) {
  if (!t) t = it;
  else if (it->prior > t->prior) split(t, it->key, it->l, it->r), t = it;
  else insert(it->key < t->key ? t->l : t->r, it);
  upd_cnt(t);
}
void erase(node*& t, int key) {
  if (t->key == key) merge(t, t->l, t->r);
  else erase(key < t->key ? t->l : t->r, key);
  upd_cnt(t);
}
pair<int, bool> find_idx(node*& t, int key, int start = 0) { // {idx, rounded up?}
  if (!t) return {start, true};
  else if (key == t->key) return {start + cnt(t->l), false};
  else if (key < t->key) return find_idx(t->l, key, start);
  else return find_idx(t->r, key, start + cnt(t->l) + 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> b[i].x >> b[i].r >> b[i].oq;
  }
  sort(b, b+N, qcomp);
  int qit = -1, lq = -1;
  for (int i = 0; i < N; i++) {
    if (b[i].oq == lq) {
      b[i].q = qit;
    } else {
      qit++;
      b[i].q = qit;
      lq = b[i].oq;
      qlt[qit] = b[i].oq;
    }
  }
  sort(b, b+N, lcomp);
  for (int i = 0; i < N; i++) l[i].first = b[i].x-b[i].r, l[i].second = b[i];
  sort(b, b+N, xcomp);
  for (int i = 0; i < N; i++) x[i].first = b[i].x, x[i].second = b[i];
  sort(b, b+N, rcomp);
  for (int i = 0; i < N; i++) r[i].first = b[i].x+b[i].r, r[i].second = b[i];
  int li, xi, ri;
  li = xi = ri = 0;
  ll res = 0;
  while (li < N || xi < N || ri < N) {
    if (li < N && (xi >= N || l[li].first <= x[xi].first) && (ri >= N || l[li].first <= r[ri].first)) {
      // ins
      insert(rts[l[li].second.q], new node(l[li].second.x, fastrand()));
      li++;
    } else if (xi < N && (li >= N || x[xi].first <= l[li].first) && (ri >= N || x[xi].first <= r[ri].first)) {
      // test
      for (int q = x[xi].second.q-K; q <= x[xi].second.q+K; q++) {
        if (q < 0 || q > qit || qlt[q] < qlt[x[xi].second.q]-K || qlt[q] > qlt[x[xi].second.q]+K) continue;
        pair<int, bool> lo = find_idx(rts[q], x[xi].first - x[xi].second.r),
          hi = find_idx(rts[q], x[xi].first + x[xi].second.r);
        res += hi.first - lo.first + !hi.second - (q == x[xi].second.q); // for ourselves
      }
      xi++;
    } else {
      // del
      erase(rts[r[ri].second.q], r[ri].second.x);
      ri++;
    }
  }
  cout << res/2 << "\n";
}
