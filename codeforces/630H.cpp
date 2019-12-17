// 630H - Benches
// There are (n choose 5)^2 * 120 ways to arrange the benches.
// The theory is that there are (n choose 5)^2 ways to choose which
// 5 rows and columns get the edges, and then 120 (given) ways to arrange
// within the 5 rows/columns. The bulk of the program calculates binom(n, 5)
// with Pascal's Identity binom(n, k) = binom(n-1, k-1) + binom(n, k-1) in O(n).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll bc[101][6];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  for (int t = 1; t <= n; t++) {
    for (int k = 0; k <= 5; k++) {
      if (k>t) continue;
      if (k==0||k==t) bc[t][k] = 1;
      else bc[t][k] = (t-1<k?0:bc[t-1][k]) + (t-1<k-1?0:bc[t-1][k-1]);
    }
  }
  cout << bc[n][5]*bc[n][5]*120LL << "\n";
}
