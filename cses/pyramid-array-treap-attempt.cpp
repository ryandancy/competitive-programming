// This is an incorrect solution - sometimes mixing sides gives a better result.
// However, here's an implementation of randomized treap with insert/erase with counts,
// index finding, and a "this_cnt" for multiple instances of keys.

#include <bits/stdc++.h>

#define INF 1000000000

typedef long long ll;

using namespace std;

struct item {
  ll key, prior, cnt, this_cnt;
  item* l;
  item* r;
  item(ll key, ll prior) : key(key), prior(prior), cnt(1), this_cnt(1), l(nullptr), r(nullptr) {}
};

inline ll cnt(item* t) {
  return t ? t->cnt : 0;
}

void upd_cnt(item* t) {
  if (t) t->cnt = t->this_cnt + cnt(t->l) + cnt(t->r);
}

bool try_add(item* t, ll key) {
  bool ok;
  if (!t) ok = false;
  else if (key == t->key) t->this_cnt++, ok = true;
  else if (key < t->key) ok = try_add(t->l, key);
  else ok = try_add(t->r, key);
  upd_cnt(t);
  return ok;
}

void split(item* t, ll key, item*& l, item*& r) {
  if (!t) l = r = nullptr;
  else if (t->key > key) split(t->l, key, l, t->l), r = t;
  else split(t->r, key, t->r, r), l = t;
  upd_cnt(t);
}

void merge(item*& t, item* l, item* r) {
  if (!l || !r) t = l ? l : r;
  else if (l->prior > r->prior) merge(l->r, l->r, r), t = l;
  else merge(r->l, l, r->l), t = r;
}

void insert(item*& t, item* it) {
  if (!t) t = it;
  else if (it->prior > t->prior) split(t, it->key, it->l, it->r), t = it;
  else insert(it->key < t->key ? t->l : t->r, it);
  upd_cnt(t);
}

void erase(item*& t, int key) {
  if (t->key == key) merge(t, t->l, t->r);
  else erase(key < t->key ? t->l : t->r, key);
}

void try_insert(item*& t, ll key, mt19937& rng) {
  if (!try_add(t, key)) insert(t, new item(key, rng()));
}

ll find_idx(item* t, ll key) {
  if (!t) {
    return -1;
  } else if (key == t->key) {
    return cnt(t->l) + t->this_cnt - 1; // return highest
  } else if (key < t->key) {
    return find_idx(t->l, key);
  } else {
    ll idx = find_idx(t->r, key);
    return idx == -1 ? -1 : cnt(t->l) + t->this_cnt + idx;
  }
}

int main() {
  int n;
  cin >> n;
  
  ll x[200000];
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  
  ll dpl[200000], dpr[200000];
  item* tl = nullptr;
  item* tr = nullptr;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  
  dpl[0] = 0;
  try_insert(tl, x[0], rng);
  for (int i = 1; i < n; i++) {
    try_insert(tl, x[i], rng);
    dpl[i] = dpl[i-1] + i - find_idx(tl, x[i]);
    cout << "dpl[" << i << "] = " << dpl[i] << '\n';
  }
  
  dpr[n-1] = 0;
  try_insert(tr, x[n-1], rng);
  for (int i = n-2, c = 1; i >= 0; i--, c++) {
    try_insert(tr, x[i], rng);
    dpr[i] = dpr[i+1] + c - find_idx(tr, x[i]);
    cout << "dpr[" << i << "] = " << dpr[i] << '\n';
  }
  
  ll res = min(dpr[0], dpl[n-1]);
  for (int i = 0; i < n-1; i++) {
    res = min(res, dpl[i] + dpr[i+1]);
  }
  
  cout << res << '\n';
}
