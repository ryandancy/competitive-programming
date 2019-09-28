// 912D - Fishes
// Generate number of net-positions each cell can get caught in
// with a weird tree algorithm:
//          4x8
//         /   \ 
//        4x7   3x8
//       /   \    \ 
//      4x6   3x7  2x8
//     /  \     \    \ 
//    4x5  3x6  2x7  1x8
//   /  \    \    \ 
//  4x4  3x5  2x6  1x7
// etc
// We put the values in a priority queue by product and turns out if you do that
// it generates all the products in descending order.
// We do some twiddling to make sure all the numbers of e.g. 2x3 repeats are
// accurate and subtract until k is 0.
// Time complexity: O(k), I think.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct prod { // for priority_queue
  bool operator()(pair<ll, ll>& a, pair<ll, ll>& b) {
    return a.first*a.second < b.first*b.second;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n, m, r, k;
  cin >> n >> m >> r >> k;
  if (n < m) {
    swap(n, m);
  }
  ll bn = min(r, n-r+1);
  ll bm = min(r, m-r+1);
  ll tot = 0;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, prod> q;
  q.push({bm, bn});
  while (k > 0 && q.size()) {
    auto p = q.top(); q.pop();
    ll prod = p.first * p.second;
    ll num;
    if (bn == bm && ((p.first == bm && p.second != bn) || (p.first != bm && p.second == bn))) {
      num = 2*(n-2*(bn-1)) + 2*(m-2*(bm-1));
    } else if (p.first == bm) {
      if (p.second == bn) {
        num = (n-2*(bn-1))*(m-2*(bm-1));
      } else {
        num = 2*(m-2*(bm-1));
      }
    } else if (p.second == bn) {
      num = 2*(n-2*(bn-1));
    } else if (p.second == bm) {
      num = 2*(m-2*(bm-1));
      if (p.second < bn) {
        num += 4;
      }
    } else if (p.first == bn) { // this is probably impossible
      num = 2*(n-2*(bn-1));
      if (p.first < bm) {
        num += 4;
      }
    } else {
      if (p.first == p.second || (p.second > bm)) {
        num = 4;
      } else {
        num = 8;
      }
    }
    if (k <= num) {
      num = min(k, num);
      k = 0;
    } else {
      k -= num;
    }
    tot += num*prod;
    if (p.second - p.first == 1 || (p.second != p.first && p.first == bm)) {
      q.push({p.first, p.second-1});
    }
    if (p.first == 1) continue;
    q.push({p.first-1, p.second});
  }
  ld outof = (n-r+1) * (m-r+1);
  ld totf = (ld) tot;
  printf("%.100Lf\n", totf/outof);
}
