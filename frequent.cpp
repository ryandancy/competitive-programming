// FREQUENT - Frequent values

#include <iostream>
#include <unordered_map>

#define UNUSED 10000000

using namespace std;

struct data {
  int bestFreq = 0, prefFreq = 0, suffFreq = 0, pref = UNUSED, suff = UNUSED;
};

void combine(data& res, const data& d1, const data& d2) {
  if (d1.pref == UNUSED) {
    res = d2; return;
  } else if (d2.pref == UNUSED) {
    res = d1; return;
  }
  
  res.pref = d1.pref;
  res.suff = d2.suff;
  res.prefFreq = d1.prefFreq;
  res.suffFreq = d2.suffFreq;
  res.bestFreq = max(d1.bestFreq, d2.bestFreq);
  if (d1.suff == d2.pref) {
    if (d1.pref == d1.suff) {
      res.prefFreq += d2.prefFreq;
    }
    if (d2.pref == d2.suff) {
      res.suffFreq += d1.suffFreq;
    }
    res.bestFreq = max(res.bestFreq, d1.suffFreq + d2.prefFreq);
  }
}

void get(data& res, data *tree, int left, int right, int a, int b, int node = 1) {
  int w = (left + right) / 2;
  if (a == left && b == right) {
    res = tree[node];
  } else if (a <= w && b <= w) {
    // all in left
    get(res, tree, left, w, a, b, 2*node);
  } else if (a > w && b > w) {
    // all in right
    get(res, tree, w + 1, right, a, b, 2*node + 1);
  } else {
    // split
    data lp, rp;
    get(lp, tree, left, w, a, w, 2*node);
    get(rp, tree, w+1, right, w+1, b, 2*node + 1);
    combine(res, lp, rp);
  }
}

int main() {
  ios::sync_with_stdio(false);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int N, q;
  while (1) {
    cin >> N;
    if (N == 0) break;
    cin >> q;
    
    // n must be smallest power of 2 greater than N
    int n = 1;
    while (n < N) n *= 2;
    
    // build segment tree
    data *tree = new data[2*n]; // leave tree[0] unused because it's easier
    int val;
    for (int i = n; i < n+N; i++) {
      cin >> val;
      tree[i].pref = tree[i].suff = val;
      tree[i].bestFreq = tree[i].prefFreq = tree[i].suffFreq = 1;
    }
    
    for (int k = n/2; k > 0; k /= 2) {
      for (int i = k; i < 2*k; i++) {
        combine(tree[i], tree[2*i], tree[2*i+1]);
      }
    }
    
    // respond to queries
    int a, b;
    data res;
    for (int i = 0; i < q; i++) {
      cin >> a >> b;
      get(res, tree, 1, n, a, b);
      cout << res.bestFreq << endl;
    }
    
    delete[] tree;
  }
}
