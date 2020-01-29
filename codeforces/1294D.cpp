// 1294D - MEX maximizing
// The adding/subtracting x thing means we only care about the residue of the input mod x.
// We use a priority queue to store the positions of the minimum values. O(q+x).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll p[400000]={0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll q, x;
  cin >> q >> x;
  priority_queue<pii> qu;
  for (int i = 0; i < x; i++) qu.push({0, -i});
  for (int i = 0; i < q; i++) {
    ll a;
    cin >> a;
    a %= x;
    p[a]++;
    pii tp = qu.top();
    qu.push({-p[a],-a});
    while (-tp.first!=p[-tp.second]) {
      qu.pop();
      tp = qu.top();
    }
    cout << x*-tp.first-tp.second << '\n';
  }
}
