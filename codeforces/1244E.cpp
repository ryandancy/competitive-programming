// 1244E - Minimizing Difference
// Greedy - we just sort and go for the smallest-sized range on either end each time.
// We count ranges in O(log n) with binary search, so time complexity O(n log n).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n; ll k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);
  int mni = 0, mxi = n-1;
  ll sp = 0;
  while (sp < k && a[mni] < a[mxi] && mni < mxi) {
    int mnr = upper_bound(a, a+n, a[mni])-a, mxr = a+n-lower_bound(a, a+n, a[mxi]);
    if (mnr < mxr) {
      if (sp+mnr*(a[mni+1]-a[mni]) <= k) {
        sp += mnr*(a[mni+1]-a[mni]);
        mni++;
      } else {
        a[mni] += (k-sp)/mnr;
        break;
      }
    } else {
      if (sp+mxr*(a[mxi]-a[mxi-1]) <= k) {
        sp += mxr*(a[mxi]-a[mxi-1]);
        mxi--;
      } else {
        a[mxi] -= (k-sp)/mxr;
        break;
      }
    }
  }
  cout << a[mxi] - a[mni] << "\n";
}
