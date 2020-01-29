// 1294E - Obtain a Permutation
// Keep a count of how many elements would be in place in each column when shifted by
// each amount. Use a key function to avoid storing a 2E5*2E5 array. Then, for each column,
// determine the minimal number of moves by testing the number of moves required when
// shifting by each amount. O(n*m).
#define INF 1000000000
#include <bits/stdc++.h>
using namespace std;
#define k(r,c) (m*(r)+(c))
int s[200000]={0};
int n,m;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin >> n >> m;
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      int a;
      cin >> a; a--;
      if ((a-c)%m==0 && a<n*m && a>=0) {
        s[k(((r-(a-c)/m)+n)%n,c)]++;
      }
    }
  }
  int tc=0;
  for (int c = 0; c < m; c++) {
    int mc=INF;
    for (int j = 0; j < n; j++) {
      int cc=j+n-s[k(j,c)];
      if (cc<mc) mc=cc;
    }
    tc+=mc;
  }
  cout << tc << '\n';
}
