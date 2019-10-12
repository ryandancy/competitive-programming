// 1045G - AI Robots
// The idea is to maintain a treap for each IQ and then search 2K+1 IQs for each robot.
// However we can't store 10^9 treaps, so we compress the IQs into only 10^5 possible values.
// We sweep across the map and process three types of events in the following order:
// 1) We insert any robots whose vision starts into their corresponding treap.
// 2) We process any robots at that position. We process at most 2K+1 treaps.
// 3) We remove any robots whose vision ends from their corresponding treap.
// The treap implementation is tricky because we have to support finding the index of a robot
// (necessitating storing subtree sizes) in order to efficiently find the number of robots in
// view, and we also need to support duplicate robot positions.
// Time complexity: O(K log N) to process each robot, O(log N) insertions and removals,
// so overall O(KN log N).
#include <bits/stdc++.h>
struct bot {
  int x, r, oq, q;
};
bool qcomp(bot& a, bot& b) { return a.oq < b.oq; }
bool xcomp(bot& a, bot& b) { return a.x < b.x; }
bool lcomp(bot& a, bot& b) { return a.x-a.r < b.x-b.r; }
bool rcomp(bot& a, bot& b) { return a.x+a.r < b.x+b.r; }
bot b[100000];
pair<int, bot> l[100000], x[100000], r[100000];
int qlt[100000];
static unsigned g_seed = 0xF024;
inline int fastrand() {
  g_seed = (214013*g_seed+2531011);
  return (g_seed>>16)&0x7FFF;
}
struct node {
  int key, prior;
  node(int key, int prior) : key(key), prior(prior) {}
  node* l = nullptr, * r = nullptr;
  int cnt = 1, mecnt = 1;
};
node* rts[100000] = {nullptr};
int cnt(node* t) {
  return t ? t->cnt : 0;
}
void upd_cnt(node* t) {
  if (t) t->cnt = t->mecnt + cnt(t->l) + cnt(t->r);
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
bool try_inc(node*& t, int key) {
  if (!t) return false;
  if (t->key == key) {
    t->mecnt++;
    upd_cnt(t);
    return true;
  }
  bool v = try_inc(key < t->key ? t->l : t->r, key);
  upd_cnt(t);
  return v;
}
void insert(node*& t, node* it) {
  if (!t) t = it;
  else if (it->prior > t->prior) split(t, it->key, it->l, it->r), t = it;
  else insert(it->key < t->key ? t->l : t->r, it);
  upd_cnt(t);
}
void erase(node*& t, int key) {
  if (t->key == key) {
    if (t->mecnt <= 1) merge(t, t->l, t->r);
    else t->mecnt--;
  } else erase(key < t->key ? t->l : t->r, key);
  upd_cnt(t);
}
int find_idx(node*& t, int key, bool greater, int start = 0) {
  if (!t) return start;
  else if (key == t->key) return greater ? start + cnt(t->l) + t->mecnt : start + cnt(t->l);
  else if (key < t->key) return find_idx(t->l, key, greater, start);
  else return find_idx(t->r, key, greater, start + cnt(t->l) + t->mecnt);
}
void print(node*& t) {
  // not used here, but might be useful if I return to copy-paste some treap stuff
  if (!t) return;
  cout << t->key << "(" << "x" << t->mecnt << "; tc" << t->cnt << "; p" << t->prior << "): L {\n";
  print(t->l);
  cout << "} R: {\n";
  print(t->r);
  cout << "}\n";
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
      if (!try_inc(rts[l[li].second.q], l[li].second.x)) insert(rts[l[li].second.q], new node(l[li].second.x, fastrand()));
      li++;
    } else if (xi < N && (li >= N || x[xi].first <= l[li].first) && (ri >= N || x[xi].first <= r[ri].first)) {
      // test
      for (int q = x[xi].second.q-K; q <= x[xi].second.q+K; q++) {
        if (q < 0 || q > qit || qlt[q] < qlt[x[xi].second.q]-K || qlt[q] > qlt[x[xi].second.q]+K) continue;
        int lo = find_idx(rts[q], x[xi].first - x[xi].second.r, false),
          hi = find_idx(rts[q], x[xi].first + x[xi].second.r, true);
        res += hi - lo - (q == x[xi].second.q); // for ourselves
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
