// 1278C - Berry Jam
// Use prefix sums to find the minimum to take away each possible number
// of jams of each colour from each side, then iterate over 2-partitions
// of the number we need to take away to find the minimum. O(n).
#include <bits/stdc++.h>
using namespace std;
int a[100000], b[100000], o=0;
int la[100000]={0}, lb[100000]={0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int s=0;
    for (int i = 0; i < n; i++) {cin >> a[o+n-i-1]; a[o+n-i-1]=(a[o+n-i-1]==1?1:-1); s += a[o+n-i-1];}
    for (int i = 0; i < n; i++) {cin >> b[o+i]; b[o+i] = (b[o+i]==1?1:-1); s += b[o+i];}
    if (s==0) {cout << "0\n"; continue;}
    int as=0;
    for (int i = 0; i < n; i++) {
      as += a[o+i];
      if (as<0 == s<0) {
        if (la[o+abs(as)-1]==0) {
          la[o+abs(as)-1]=i+1;
        }
      }
    }
    int bs=0;
    for (int i = 0; i < n; i++) {
      bs += b[o+i];
      if (bs<0 == s<0) {
        if (lb[o+abs(bs)-1]==0) {
          lb[o+abs(bs)-1]=i+1;
        }
      }
    }
    int bst=2*n;
    for (int fa=0; fa <= abs(s); fa++) {
      int fb = abs(s)-fa;
      if (fa>n || fb>n) continue;
      if ((fa != 0 && la[o+fa-1]==0) || (fb != 0 && lb[o+fb-1]==0)) continue;
      int c = (fa==0?0:la[o+fa-1]) + (fb==0?0:lb[o+fb-1]);
      if (c<bst) {bst=c;}
    }
    cout << bst << '\n';
    o += n;
  }
}
