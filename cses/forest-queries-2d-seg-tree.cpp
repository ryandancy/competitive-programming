// Range sums in a static 2D array. This is a 2D segment tree solution, but this
// can be done wayy easier with 2D prefix sums. O(n^2 log n).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, o, q;
ll st[4001][4001]={{0}};

ll sum1d(int y, int x1, int x2) {
  x1 += o, x2 += o;
  ll res = 0;
  while (x1<=x2) {
    if (x1%2 == 1) res += st[y][x1++];
    if (x2%2 == 0) res += st[y][x2--];
    x1 /= 2, x2 /= 2;
  }
  return res;
}

ll sum2d(int y1, int y2, int x1, int x2) {
  y1 += o, y2 += o;
  ll res = 0;
  while (y1<=y2) {
    if (y1%2 == 1) res += sum1d(y1++, x1, x2);
    if (y2%2 == 0) res += sum1d(y2--, x1, x2);
    y1 /= 2, y2 /= 2;
  }
  return res;
}

// to update: update in path up each segment tree in path up

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>n>>q;
  
  // compute offset
  o=1;
  while (o<n) o*=2; // break into o1 and o2 if not square
  
  // input in first row of first row
  string s;
  for (int y = 0; y < n; y++) {
    cin>>s;
    for (int x = 0; x < n; x++) {
      st[o+y][o+x] = (s[x] == '*');
    }
  }
  
  // build first rows of upper trees
  for (int i = o/2; i > 0;i /= 2) {
    for (int j = i; j < 2*i; j++) {
      for (int k = o; k < 2*o; k++) {
        st[j][k] = st[2*j][k] + st[2*j+1][k];
      }
    }
  }
  
  // build upper rows of all trees
  for (int i = 1; i <= 2*o; i++) {
    for (int j = o/2; j > 0; j/=2) {
      for (int k = j; k < 2*j; k++) {
        st[i][k] = st[i][2*k] + st[i][2*k+1];
      }
    }
  }
  
  // process queries
  int x1, x2, y1, y2;
  while (q--) {
    cin>>y1>>x1>>y2>>x2;
    cout<<sum2d(y1-1, y2-1, x1-1, x2-1)<<"\n";
  }
}
