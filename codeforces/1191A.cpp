// 1191A - Tokitsukaze and Enhancement
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x[] = {1, 4, 2, 3};
char C[] = {'D', 'A', 'C', 'B'};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, b=0, c, y; cin >> n;
  for (int i = 0; i < 3; i++) {
    if (x[(n+i)%4]>b) {
      b=x[(n+i)%4];
      y=(n+i)%4;
      c = i;
    }
  }
  cout << c << " " << C[y] << endl;
}