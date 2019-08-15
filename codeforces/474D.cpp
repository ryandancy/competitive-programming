// 474D - Flowers
// DP: Let 1 represent white flowers and 0 represent red ones.
// Then for length 4 and k=2, the following configurations are possible with
// one or zero groups of 1s: 0000, 0011, 0110, 1100.
// For each possible configuration, there are lengths of 0s that represent
// subproblems; for example, in 0011, the 00 is a subproblem of length 2.
// To avoid duplicates, we focus only on the lengths of 0s at the beginning
// (or equivalently, the end) of each configuration.
// Let T_n be the answer to a problem of length n. Then T_n = 1 for n < k.
// For n >= k, T_n = 1 + sum_{i=0}^{n-k} T_i, the 1 representing all 0s
// and each T_i representing a length of 0s at the beginning.
// Now, to compute sums of ranges of T_n in O(1) time, we need a prefix sum
// array, P_n = sum_{i=0}^n T_i. Then T_n = 1 + P_{n-k}, and so
// P_n = 1 + P_{n-k} + P_{n-1}. Thus T is unnecessary and we may DP on P.
// Time complexity: constant 10^5 precomputation, O(t) queries.
#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
ll pdp[100001] = {0}; // "prefix sum of DP"
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t, k, a, b;
  cin >> t >> k;
  for (int i = 0; i < k; i++) {
    pdp[i] = i+1;
  }
  for (int i = k; i <= 100000; i++) {
    pdp[i] = 1 + pdp[i-k];
    pdp[i] %= MOD;
    pdp[i] += pdp[i-1];
    pdp[i] %= MOD;
  }
  while (t--) {
    cin >> a >> b;
    ll res = pdp[b] - pdp[a-1];
    res %= MOD;
    if (res < 0) res += MOD;
    cout << res << "\n";
  }
}
