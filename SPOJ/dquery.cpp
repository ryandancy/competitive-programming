// DQUERY - D-queries
// Mo's algorithm: sort queries into blocks of size sqrt(n) based on start,
// sort in blocks by increasing end, process with an active window.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int bs = 1;
int arr[30000];
int counts[1000000];
int ql[200000];
int qr[200000];
int qans[200000];

inline bool mocomp(int i, int j) {
  // already in blocks, sort based on endpoints
  return qr[i] < qr[j];
}

int main() {
  ios::sync_with_stdio(false);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  fill_n(counts, 1000000, 0);
  
  int n;
  cin >> n;
  while ((bs+1)*(bs+1) < n) bs++;
  
  for (int i = 0; i < n; i++) cin >> arr[i];
  
  vector<int> *qidxs = new vector<int>[n/bs+1]; // blocks
  
  int q;
  cin >> q;
  int a, b;
  for (int i = 0; i < q; i++) {
    cin >> a >> b;
    ql[i] = a-1;
    qr[i] = b-1;
    qidxs[a/bs].push_back(i);
  }
  
  // sort
  for (int i = 0; i <= n/bs; i++) {
    sort(qidxs[i].begin(), qidxs[i].end(), mocomp);
  }
  
  // initialize with first query
  int qi = qidxs[0][0];
  int l = ql[qi], r = qr[qi];
  int ans = 0;
  for (int i = l; i <= r; i++) {
    if (counts[arr[i]-1] == 0) ans++;
    counts[arr[i]-1]++;
  }
  qans[qi] = ans;
  
  // go through rest of queries
  for (int j = 0; j <= n/bs; j++) {
    for (int& qi : qidxs[j]) {
      if (l < ql[qi]) {
        for (int i = l; i < ql[qi]; i++) {
          if (--counts[arr[i]-1] == 0) ans--;
        }
      } else {
        for (int i = l-1; i >= ql[qi]; i--) {
          if (counts[arr[i]-1]++ == 0) ans++;
        }
      }
      if (r < qr[qi]) {
        for (int i = r+1; i <= qr[qi]; i++) {
          if (counts[arr[i]-1]++ == 0) ans++;
        }
      } else {
        for (int i = r; i > qr[qi]; i--) {
          if (--counts[arr[i]-1] == 0) ans--;
        }
      }
      qans[qi] = ans;
      l = ql[qi];
      r = qr[qi];
    }
  }
  
  // output them
  for (int i = 0; i < q; i++) {
    cout << qans[i] << "\n";
  }
}
