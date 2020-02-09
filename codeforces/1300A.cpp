// 1300A - Non-zero
// Add 1 to all the zeros, add 1 to something if the sum is 0.
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int zc=0, s=0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (a==0) zc++;
      s+=a;
    }
    s+=zc;
    if (s==0)zc++;
    cout << zc << '\n';
  }
}
