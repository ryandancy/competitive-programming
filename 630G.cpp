// 630G - Challenge Pennants
// The number of partitions of n items into exactly k boxes is binom(n-1, k-1).
// The number of ways to choose k out of n boxes is binom(n, k).
// For each type of pennant, we calculate ways to choose n boxes * ways to partition into
// those boxes for each n, then multiply together. O(n) to calculate the binomials.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll bc[501][6];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  for (int t = 1; t <= n; t++) {
    for (int k = 0; k <= 5; k++) {
      if (k>t) bc[t][k] = 0;
      else if (k==0||k==t) bc[t][k] = 1;
      else bc[t][k] = (t-1<k?0:bc[t-1][k]) + (t-1<k-1?0:bc[t-1][k-1]);
    }
  }
  cout << (bc[n][5]+bc[n][4]*4+bc[n][3]*6+bc[n][2]*4+bc[n][1])*(bc[n][3]+bc[n][2]*2+bc[n][1]) << "\n";
}
