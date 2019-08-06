// 86D - Powerful Array
// Mo's algorithm - O(n sqrt n)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

struct query { int l, r, idx; };

bool operator<(query& a, query& b) {
  return a.r < b.r;
}

ll arr[200000];
ll c[1000001]; // counts
vector<query> qs[448]; // queries
ll qans[200000]; // answers to queries

inline void remove(ll& res, int x) {
  res -= c[x]*c[x]*x;
  c[x]--;
  res += c[x]*c[x]*x;
}

inline void add(ll& res, int x) {
  res -= c[x]*c[x]*x;
  c[x]++;
  res += c[x]*c[x]*x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int N, T;
  cin >> N >> T;
  for (int i = 0; i < N; i++) cin >> arr[i];
  
  int bs = 1;
  while (bs*bs < N) bs++; // block size = sqrt(N)
  
  int l, r;
  for (int i = 0; i < T; i++) {
    cin >> l >> r;
    qs[l/bs].push_back({l, r, i});
  }
  
  l = r = -1;
  ll curr = 0;
  for (int b = 0; b <= N/bs; b++) {
    sort(qs[b].begin(), qs[b].end());
    for (query& q : qs[b]) {
      if (l == -1 && r == -1) {
        // create active window
        for (int i = q.l; i <= q.r; i++) {
          add(curr, arr[i-1]);
        }
      } else {
        // move active window
        for (int i = l-1; i >= q.l; i--) {
          add(curr, arr[i-1]);
        }
        for (int i = r+1; i <= q.r; i++) {
          add(curr, arr[i-1]);
        }
        for (int i = l; i < q.l; i++) {
          remove(curr, arr[i-1]);
        }
        for (int i = r; i > q.r; i--) {
          remove(curr, arr[i-1]);
        }
      }
      qans[q.idx] = curr;
      l = q.l; r = q.r;
    }
  }
  
  // print answers
  for (int i = 0; i < T; i++) {
    cout << qans[i] << "\n";
  }
}
