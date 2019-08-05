// KQUERY - K-query
// Progressively add to the BIT by processing in offline sorted order - O((n+q) log n)

#include <iostream>
#include <algorithm>

using namespace std;

struct elem {
  int val, idx;
  bool operator<(elem& o) { // sort by value in decreasing order
    return this->val > o.val;
  }
};

struct query {
  int l, r, k, idx;
  bool operator<(query& o) { // sort by k value in decreasing order
    return this->k > o.k;
  }
};

int N;
int bit[30000] = {0};
elem arr[30000];
query qs[200000];
int qans[200000];

void bit_inc(int i) {
  while (i <= N) {
    bit[i-1]++;
    i += i&-i;
  }
}

int bit_sum(int i) {
  int res = 0;
  while (i > 0) {
    res += bit[i-1];
    i -= i&-i;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i].val;
    arr[i].idx = i;
  }
  
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    cin >> qs[i].l >> qs[i].r >> qs[i].k;
    qs[i].idx = i;
  }
  
  sort(arr, arr+N);
  sort(qs, qs+Q);
  
  for (int ai = 0, qi = 0; qi < Q; qi++) {
    query& q = qs[qi];
    while (ai < N && arr[ai].val > q.k) {
      bit_inc(1+arr[ai++].idx);
    }
    qans[q.idx] = bit_sum(q.r) - bit_sum(q.l-1);
  }
  
  for (int i = 0; i < Q; i++) {
    cout << qans[i] << "\n";
  }
}
