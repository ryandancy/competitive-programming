// 1282A - Temporarily unavailable
// Very simple solution
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    int a,b,c,r;
    cin >> a >> b >> c >> r;
    int x = min(a,b);
    int y = max(a,b);
    int i;
    if (c <= x) {
      i = max(0,min(y-x,r-(x-c)));
    } else if (c >= y) {
      i = max(0,min(y-x,r-(c-y)));
    } else {
      i = max(0,min(r,c-x)) + max(0,min(r,y-c));
    }
    cout << (y-x)-i << "\n";
  }
}
